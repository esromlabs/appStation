// generated to target Arduino from a StateFlow
#include <stdio.h>
//#include <string.h>

//#define DEBUG_STATE
//#define DEBUG_EVENTS

// neopixel display
#include <Adafruit_NeoPixel.h>
//#include <avr/power.h>
#define NEOPIX_PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, NEOPIX_PIN, NEO_GRB + NEO_KHZ800);

typedef enum {question_mark = 0, home_colors, animate_swirl} Patterns;

unsigned char pix[2][8][8] = {{
{ 0, 0, 0,42,42, 0, 0, 0},
{ 0, 0,42, 0, 0,42, 0, 0},
{ 0, 0, 0, 0, 0, 42, 0, 0},
{ 0, 0, 0, 0, 0, 42, 0, 0},
{ 0, 0, 0, 42, 42, 0, 0, 0},
{ 0, 0, 0, 42, 0, 0, 0, 0},
{ 0, 0, 0, 0, 0, 0, 0, 0},
{ 0, 0, 0, 42, 0, 0, 0, 0}
},
{
{0b111100,12,12,12,12,12,12, 0b101110},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b110000, 0, 0, 0, 0, 0, 0, 0b101010},
{0b111011, 3, 3, 3, 3, 3, 3, 0b101011}
}};
int swirl_i = 0;

// pixel map of where the indexes fall
//  0  1  2  3  4  5  6  7
//  8  9 10 11 12 13 14 15
// 16 17 18 19 20 21 22 23
// 24 25 26 27 28 29 30 31
// 32 33 34 35 36 37 38 39
// 40 41 42 43 44 45 46 47
// 48 49 50 51 52 53 54 55
// 56 57 58 59 60 61 62 63
#define SWIRL_SIZE 66
unsigned char swirl_path[SWIRL_SIZE] =
{0, 1, 2, 3, 4, 5, 6, 7
,15,23,31,39, 47, 55, 63
,62,61,60,59,58, 57,56
,48,40,32,24,16
,17,18,19,20,21
,29,37,45, 44, 43,42
,34,35
,43, 44, 36, 28
,27,26,25, 33,41,49, 50,51,52,53,54
,46,38,30,22,14, 13,12,11,10,9,8};
void display(int p) {
  if (p == animate_swirl) {
    pixels.setPixelColor(swirl_path[swirl_i], pixels.Color(0, 0, 0));
    swirl_i = (swirl_i+1)%SWIRL_SIZE;
    pixels.setPixelColor(swirl_path[(swirl_i+1)%SWIRL_SIZE], pixels.Color(4, 3, 4));
    pixels.setPixelColor(swirl_path[(swirl_i+2)%SWIRL_SIZE], pixels.Color(6, 6, 20));
    pixels.setPixelColor(swirl_path[(swirl_i+3)%SWIRL_SIZE], pixels.Color(10, 8, 10));
    pixels.setPixelColor(swirl_path[(swirl_i+4)%SWIRL_SIZE], pixels.Color(20, 10, 8));
    pixels.setPixelColor(swirl_path[(swirl_i+5)%SWIRL_SIZE], pixels.Color(10, 20, 4));
    pixels.setPixelColor(swirl_path[(swirl_i+6)%SWIRL_SIZE], pixels.Color(4, 8, 2));
  }
  else {
    unsigned char red_filter = 0b110000;
    unsigned char blu_filter = 0b001100;
    unsigned char gre_filter = 0b000011;
    unsigned char red_shift = 4;
    unsigned char blu_shift = 2;
    unsigned char gre_shift = 0;
    for(int i=0;i<8;i+=1) {
      for(int j=0;j<8;j+=1) {
        unsigned char red = ((pix[p][i][j]&red_filter)>>red_shift)*3;
        unsigned char blu = ((pix[p][i][j]&blu_filter)>>blu_shift)*3;
        unsigned char gre = ((pix[p][i][j]&gre_filter)>>gre_shift)*3;
        pixels.setPixelColor(i*8+j, pixels.Color(red, blu, gre));
      }
    }
  }
  pixels.show();
}

// state machine vars and methods
typedef enum {start, whos_who, init_game, pick_player, phase_1, inc_player, dec_non_player, phase_2, inc_non_player, dec_player, blank} State;
typedef enum {btn_down, btn_up, done, times_up} Signal;

// signal queue
typedef struct Signal_item {
  Signal sig;
  int data;
  boolean consume; // indicates that this signal must be consumed (i.e. will only be removed from the queue if a state transition consumes it)
} Signal_item;

#ifdef DEBUG_STATE || DEBUG_EVENTS
char *state_name(int state) {
  switch (state) {
    case start : return "start";
    case whos_who : return "whos_who";
    case init_game : return "init_game";
    case pick_player : return "pick_player";
    case phase_1 : return "phase_1";
    case inc_player : return "inc_player";
    case dec_non_player : return "dec_non_player";
    case phase_2 : return "phase_2";
    case inc_non_player : return "inc_non_player";
    case dec_player : return "dec_player";
    case blank : return "blank";
  }
  return "no state";
}
char *signal_name(int signal) {
  switch (signal) {
    case btn_down : return "btn_down";
    case btn_up : return "btn_up";
    case done : return "done";
    case times_up : return "times_up";
  }
  return "!no signal translation!";
}
#endif


#define Q_LEN 10
Signal_item q[Q_LEN];
int q_enter = 0;
int q_size = 0;
Signal_item none;

boolean is_in_queue (struct Signal_item s) {
  for (int i = 0; i < q_size; i++) {
    struct Signal_item this_s;
    int q_i = (i + q_enter + 1) % Q_LEN;
    this_s = q[q_i];
    if (this_s.sig == s.sig && this_s.data == s.data) {
      return true;
    }
  }
  return false;
}

boolean enqueue (int s, int data, boolean must_be_consumed, boolean no_duplicates) {
  if (q_size >= Q_LEN) {
    // we have a problem in that the queue is full.
    return false;
  }
  //if (no_duplicates && is_in_queue(s)) {
  //  return false;
  //}
  q[q_enter].sig = (Signal)s;
  q[q_enter].data = data;
  q[q_enter].consume = must_be_consumed;
  q_enter += -1;
  if (q_enter < 0) {q_enter += Q_LEN;}
  q_size += 1;
  return true;
}

struct Signal_item dequeue () {
  if (q_size == 0) {
    return none;
  }
  int q_exit = (q_enter + q_size) % Q_LEN;
  q_size -= 1;
  return (q[q_exit]);
}

int queue_size () {
  return (q_size);
}

State state = (State)-1;
void setup() {
  // initialize inputs
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

#ifdef DEBUG_STATE || DEBUG_EVENTS
  Serial.begin(19200);
#endif

  // init the state machine
  state = (State)-1;

  pixels.begin(); // This initializes the NeoPixel library.
}

// inputs (buttons via digital read)
int btn2_previous = 0;
int btn3_previous = 0;
int btn4_previous = 0;
int btn7_previous = 0;
// detect a button change and enqueue a message.
// returns the button state 0==disengaged, 1==engaged
int msg_input(int prev, int pin) {
  int btn_curr = digitalRead(pin);
  int btn_prev = prev;
  if (btn_prev == 0 && btn_curr == LOW) {
    enqueue(btn_down, pin, false, false);
    btn_prev = 1;
  }
  else if (btn_prev == 1 && btn_curr == HIGH) {
    enqueue(btn_up, pin, false, false);
    btn_prev = 0;
  }
  return btn_prev;
}

void listen_inputs() {
  btn2_previous = msg_input(btn2_previous, 2);
  btn3_previous = msg_input(btn3_previous, 3);
  btn4_previous = msg_input(btn4_previous, 4);
  btn7_previous = msg_input(btn7_previous, 7);
}

// timer utility
unsigned long timer = 0;
void set_timer(unsigned long timer_milli) {
  timer = millis() + timer_milli;
}
void check_timer() {
  if (timer != 0 && timer < millis()) {
    struct Signal_item s;
    s.sig = times_up;
    s.data = 0;
    if (enqueue(times_up, 0, false, false)) {
      timer = 0;
    }
  }
}

void set_players() {
  // read all the button states and record which player have their button down.
  // there are the players ready to play.

}

// main arduino loop
void loop () {

  listen_inputs();
  check_timer();

  // animate onTick function
  switch (state) {
    case whos_who :
      display(animate_swirl);
    break;
  }

  while(queue_size() > 0) {
    struct Signal_item this_event = dequeue();


#ifdef DEBUG_EVENTS
    Serial.print("Event--> sig: ");
    Serial.print(signal_name(this_event.sig));
    Serial.print(", data: ");
    Serial.println(this_event.data);
#endif // DEBUG_EVENTS

    State from_state = state;

    // test if this signal causes a transitions in the state machine
    switch (state) {
      case start :
        switch (this_event.sig) {
          case btn_down :
            state = whos_who;
          break;
        }
      break;
      case whos_who :
        display(animate_swirl);
        switch (this_event.sig) {
          case times_up :
            state = init_game;
          break;
          case btn_up :
            state = start;
          break;
        }
      break;
      case init_game :
        switch (this_event.sig) {
          case times_up :
            state = start;
          break;
        }
      break;
      default:
        state = start;
#ifdef DEBUG_STATE
        Serial.println("init to start state!");
#endif
    }
    // did the signal cause a state change?
    if (from_state != state) {
      // since this 'state' is a new state --> run any onEnterState function
      switch (state) {
        case start :
          display(question_mark);
        break;
        case whos_who :
          set_timer(10000);
        break;
        case init_game :
          //set_players();
          display(home_colors);
          set_timer(10000);
          //enqueue(done, -1, false, false);
        break;
      }
    }
    else { // nope, no state change occurred
      if (this_event.consume) {
        // signals marked "consume" that do not cause a transition are put back in the queue.
        enqueue(this_event.sig, this_event.data, this_event.consume, true);
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
int failed_tests = 0;
delay(3000);
Signal_item test;
enqueue(btn_down, 5, false, false);
if (queue_size() != 1) {
  // failed test
  Serial.println("queue_size failed to report 1 after enqueue();");
  failed_tests++;
}
enqueue(btn_down, 88, false, false);
if (queue_size() != 2) {
  // failed test
  Serial.println("queue_size failed to report 2 after second enqueue();");
  failed_tests++;
}
test = dequeue();
if (queue_size() != 1) {
  // failed test
  Serial.println("queue_size failed to report 1 after dequeue();");
  failed_tests++;
}
if (test.data != 5) {
  // failed test
  Serial.println("dequeue() did not return an item with data == 5");
  failed_tests++;
}
test = dequeue();
if (queue_size() != 0) {
  // failed test
  Serial.println("queue_size failed to report 0 after dequeue();");
  failed_tests++;
}
if (test.data != 88) {
  // failed test
  Serial.println("dequeue() did not return an item with data == 88");
  failed_tests++;
}
if (!failed_tests) {
  Serial.println("passed tests!");
}
#endif
}
