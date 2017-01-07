// generated to target Arduino from a StateFlow
#include <stdio.h>
//#include <string.h>

//#define DEBUG_STATE
//#define DEBUG_EVENTS

#include "view.h"

// state machine vars and methods
typedef enum {start, whos_who, init_game, pick_player, phase_1, inc_player, dec_non_player, phase_2, inc_non_player, dec_player, blank} State;
typedef enum {btn_down, btn_up, done, times_up} Signal;

#include "signal_queue.h"

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

  // onTick function
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

    // see if this signal causes a transitions in the state machine
    switch (state) {
      case start :
        switch (this_event.sig) {
          case btn_down :
            state = whos_who;
          break;
        }
      break;
      case whos_who :
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
