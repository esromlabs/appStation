// main code file for an appState StateFlow machine.
// Template code is a bare minimum and may need extra code to be useful

// Uncomment these if you want to track what your application is doing on
// the Serial port.
#define DEBUG_STATE
#define DEBUG_EVENTS

unsigned long rec_a_start = 0;
unsigned long rec_b_start = 0;
unsigned long rec_a_stop = 0;
unsigned long rec_b_stop = 0;
unsigned long rec_a_duration = 0;
unsigned long rec_a_duration_base = 0;
unsigned long rec_b_duration = 0;
unsigned long rec_b_duration_base = 0;
unsigned long duration_step = 0;

// includes needed output
#include "output.h"

// timer utility
unsigned long timer[3] = {0,0,0};

void setTimer(unsigned long timer_milli, int i) {
  timer[i] = millis() + timer_milli;
}

void cancel_timer(unsigned long timer_milli, int i) {
  timer[i] = 0;
}

#include "app_state.h"
#include "signal_queue.h"
#include "input.h"

void send_signal(int sig) {
    enqueue(sig, -1, false, false);
}

void check_timer() {
  for(int i = 0; i < 3; i++) {
    if (timer[i] != 0 && timer[i] < millis()) {
      if (enqueue(times_up, i, true, false)) {
        timer[i] = 0;
      }
    }
  }
}

void inc_value(unsigned long *scaler) {
  if (*scaler < rec_a_duration_base*2 - 240 - duration_step) {
    *scaler += duration_step;
  }
#ifdef DEBUG_EVENTS
  Serial.print("inc ");
  Serial.print(*scaler);
  Serial.print(" ");
  Serial.println(rec_a_duration);
#endif
}

void dec_value(unsigned long *scaler) {
  if (*scaler > 240 + duration_step) {
    *scaler -= duration_step;
  }
#ifdef DEBUG_EVENTS
  Serial.print("dec ");
  Serial.print(*scaler);
  Serial.print(" ");
  Serial.println(duration_step);
#endif
}

void set_duration_step() {
  rec_a_duration_base = rec_a_duration;
  duration_step = rec_a_duration/64;
}

void setup() {
#ifdef DEBUG_STATE | DEBUG_EVENTS
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
#endif

  // initialize inputs
  setup_inputs();
  setup_outputs();
  // initialize the state machine
  state = setup_pre_init_state();
}

// main arduino loop
void loop () {
  // call methods that (might) enqueue signals
  listen_inputs();
  check_timer();

  // onTick function
  onTick_processor(state.s);

  while(queue_size() > 0) {
    struct Signal_item this_event = dequeue();

    state.changed = false;

    // see if this signal causes a transitions in the state machine
    state = state_trans_processor(state, this_event.sig, this_event.data);

    // did the signal cause a state change?
    if (state.changed) {
      onEnterState_processor(state.s, this_event.sig, this_event.data);
    }
    else { // nope, no state change occurred
      if (this_event.consume) {
        // signals marked "consume" that do not cause a transition are put back in the queue.
        // note that consume is set to false so that this re queuing will not loop
        enqueue(this_event.sig, this_event.data, false, false);
      }
    }

  }
  delay(10);

}
