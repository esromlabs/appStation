// main code file for an appState StateFlow machine.
// Template code is a bare minimum and may need extra code to be useful

// Uncomment these if you want to track what your application is doing on
// the Serial port.
//#define DEBUG_STATE
//#define DEBUG_EVENTS

// includes needed output
#include "output.h"

// timer utility
unsigned long timer = 0;
void set_timer(unsigned long timer_milli) {
  timer = millis() + timer_milli;
}
void cancel_timer(unsigned long timer_milli) {
  timer = 0;
}

#include "app_state.h"
#include "signal_queue.h"
#include "input.h"

void send_signal(int sig) {
    enqueue(sig, -1, false, false);
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
  delay(100);

}
