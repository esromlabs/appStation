// main code file for SOGP target Arduino with an appState StateFlow machine.

#include <stdio.h>
//#include <string.h>

//#define DEBUG_STATE
//#define DEBUG_EVENTS

// neopixel display
#include <Adafruit_NeoPixel.h>
#include "view.h"

// timer utility
unsigned long timer = 0;
void set_timer(unsigned long timer_milli) {
  timer = millis() + timer_milli;
}


// game vars and methods
byte current_player = -1;
byte playing[4] = {0,0,0,0};
char score[4] = {0,0,0,0};
uint32_t player_color[4] = {0x0A0000,0x050A00,0x00050A,0x080006};
boolean animate_toggle = true;
byte num_players = 0;
void random_player() {
  int index = random(0, num_players);
  current_player = playing[index];
}

#include "app_state.h"
#include "signal_queue.h"

#include <Wire.h>
#include <Adafruit_MPR121.h>
#include "input.h"


byte set_players() {
  // read all the button states and record which player have their button down.
  // these are the players ready to play.
  num_players = 0;
  display_black();
  for(int i = 0; i < 4; i += 1) {
    if (is_btn_down(i)) {
      playing[num_players] = i;
      num_players++;
      uint32_t color = player_color[i];
      mask(p1_mask+i, color);
      score[i] = 0;
    }
  }
  return num_players;
}

void display_black() {
    uint32_t color = pixels.Color(0, 0, 0);;
    mask(layer1_mask, color);
    color = pixels.Color(0, 0, 0);;
    mask(layer1_mask, color);

}

void display_bait() {
    uint32_t color = pixels.Color(1, 1, 1);
    mask(layer2_mask, color);
    delay(50);
    color = pixels.Color(5, 5, 5);
    mask(layer2_mask, color);
    delay(50);
    color = pixels.Color(1, 1, 1);
    mask(layer3_mask, color);
    delay(50);
    color = pixels.Color(5, 5, 5);
    mask(layer3_mask, color);
    delay(50);

    color = player_color[current_player];
    mask(layer4_mask, color);

    color = pixels.Color(1, 1, 1);
    mask(layer2_mask, color);
    delay(50);
    color = pixels.Color(1, 1, 1);;
    mask(layer3_mask, color);
}

void inc_player_score(int player_index) {
  if (score[player_index]<15) {
    score[player_index]++;
  }
}
void dec_player_score(int player_index) {
  if (score[player_index] > -3) {
    score[player_index]--;
  }
}
void score_phase_1(int sig_data) {
  int i = findPlayerIndex(sig_data);
  if(i == current_player) {
    inc_player_score(i);
  }
  else {
    dec_player_score(i);
  }
}

void score_phase_2(int sig_data) {
  int i = findPlayerIndex(sig_data);
  if(i == current_player) {
    dec_player_score(i);
  }
  else {
    inc_player_score(i);
  }
}

byte findPlayerIndex(byte sig_data) {
  for (int i = 0; i < num_players; i++) {
    if (playing[i] == sig_data) {
      return i;
    }
  }
  return -1;
}

void display_score() {
  for (int i = 0; i < num_players; i++) {
    int player_index = playing[i];
    char this_score = score[player_index];
    for (int j = 0; j < 7; j++) {
      light_player_point(player_index, j, (j < (this_score +3)), player_color[player_index]);
    }
  }
}

void animate_bait() {
  uint32_t color;
  animate_toggle = !animate_toggle;
  if (animate_toggle) {
    color = player_color[current_player];
    mask(layer4_mask, color);
  }
  else {
    uint32_t color = pixels.Color(10, 10, 0);
    mask(layer4_mask, color);
  }
}

void send_signal(int sig) {
    enqueue(sig, -1, false, false);
}
boolean is_winner() {
  for (int i = 0; i < num_players; i++) {
    int player_index = playing[i];
    if (score[player_index] > 4) {
      current_player = player_index;
      return true;
    }
  }
  return false;
}

void display_winner() {
  for (int i = 0; i < num_players; i++) {
    int player_index = playing[i];
    if (score[player_index] > 4) {
      current_player = player_index;
      uint32_t color = player_color[current_player];
      uint32_t reset_color = 1;

      display_black();

      mask(p1_mask+current_player, color);
      delay(500);

      mask(p1_mask+current_player, reset_color);
      delay(500);

      mask(p1_mask+current_player, color);
      delay(500);


      mask(layer4_mask, color);
      delay(500);
      mask(layer3_mask, color);
      delay(500);
      mask(layer2_mask, color);
      delay(500);
      mask(layer1_mask, color);

      mask(layer4_mask, reset_color);
      delay(500);
      mask(layer3_mask, reset_color);
      delay(500);
      mask(layer2_mask, reset_color);
      delay(500);
      mask(layer1_mask, reset_color);
    }
  }
}


void check_timer() {
  if (timer != 0 && timer < millis()) {
    struct Signal_item s;
    s.sig = times_up;
    s.data = 0;
    if (enqueue(times_up, 0, true, false)) {
      timer = 0;
    }
  }
}



void setup() {
  // initialize inputs
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

#ifdef DEBUG_STATE || DEBUG_EVENTS
  Serial.begin(9600);

  while (!Serial) { // needed to keep leonardo/micro from starting too fast!
    delay(10);
  }
#endif

  pixels.begin(); // This initializes the NeoPixel library.

  // Capacitive touch init
  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
#ifdef DEBUG_STATE || DEBUG_EVENTS
    Serial.println("MPR121 not found, check wiring?");
#endif
//    while (1);
  }
#ifdef DEBUG_STATE || DEBUG_EVENTS
  Serial.println("MPR121 found!");
#endif

  // initialize the state machine
  setup_pre_init_state();

}

// main arduino loop
void loop () {

  listen_inputs();
  check_timer();

  // onTick function
  onTick_processor();
//  switch (state) {
//    case whos_who :
//      display(animate_swirl);
//    break;
//  }

  while(queue_size() > 0) {
    struct Signal_item this_event = dequeue();


#ifdef DEBUG_EVENTS
    Serial.print("Event--> sig: ");
    Serial.print(signal_name(this_event.sig));
    Serial.print(", data: ");
    Serial.println(this_event.data);
#endif // DEBUG_EVENTS

    State from_state = state;

    // see if this signal causes a transitions in the state machine
    state = (State)state_trans_processor(state, this_event.sig, this_event.data);

    // did the signal cause a state change?
    if (from_state != state) {
      // since this 'state' is a new state --> run any onEnterState functionality.
      onEnterState_processor(this_event.sig, this_event.data);
    }
    else { // nope, no state change occurred
      if (this_event.consume) {
        // signals marked "consume" that do not cause a transition are put back in the queue.
#ifdef DEBUG_STATE
        Serial.println("Alert: re-queuing unconsumed message!");
#endif
        // note that consume is set to false so that this re queuing will not loop
        enqueue(this_event.sig, this_event.data, false, false);
      }
    }

#ifdef DEBUG_STATE
    if (from_state != state) {
      Serial.print("State change: ");
      Serial.print(state_name(from_state));
      Serial.print(" --> ");
      Serial.println(state_name(state));
    }
#endif

  }
  delay(100);

#ifdef DEBUG_QUEUE
  test_signal_queue();
#endif

}
