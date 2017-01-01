// generated to target Arduino from a StateFlow
#include <stdio.h>
//#include <string.h>

#define DEBUG_STATE
#define DEBUG_EVENTS


// state machine vars and methods
typedef enum {ready, go} State;
typedef enum {btn_down, btn_up, done, times_up} Signal;

// signal queue
typedef struct Signal_item {
  Signal sig;
  int data;
} Signal_item;

#ifdef DEBUG_STATE || DEBUG_EVENTS
char *state_name(int state) {
  switch (state) {
  case ready : return "ready";
  case go : return "go";
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

boolean enqueue (struct Signal_item s, boolean no_duplicates) {
  if (q_size >= Q_LEN) {
    // we have a problem in that the queue is full.
    return false;
  }
  if (no_duplicates && is_in_queue(s)) {
    return false;
  }
  q[q_enter].sig = s.sig;
  q[q_enter].data = s.data;
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

State state = ready;
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
  state = go;
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
    struct Signal_item s;
    s.sig = btn_down;
    s.data = pin;
    enqueue(s, false);
    btn_prev = 1;
  }
  else if (btn_prev == 1 && btn_curr == HIGH) {
    struct Signal_item s;
    s.sig = btn_up;
    s.data = pin;
    enqueue(s, false);
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
    if (enqueue(s, false)) {
      timer = 0;
    }
  }
}

// main arduino loop
void loop () {

  listen_inputs();
  check_timer();
  while(queue_size() > 0) {
    struct Signal_item this_event = dequeue();

#ifdef DEBUG_EVENTS
    Serial.print("Event--> sig: ");
    Serial.print(signal_name(this_event.sig));
    Serial.print(", data: ");
    Serial.println(this_event.data);
#endif // DEBUG_EVENTS

#ifdef DEBUG_STATE
    State from_state = state;
#endif
    // run the state machine
    switch (state) {
      case ready :
        switch (this_event.sig) {
          //case btn_down :
          //  state = go;
          //break;
          case done :
            state = go;
          break;
          case times_up :
            state = go;
          break;
        }
        break;
      case go :
        switch (this_event.sig) {
          case btn_down :
            state = ready;
            //// test the timer
            set_timer(1000);
            //// test a done signal
            //struct Signal_item an_event;
            //an_event.sig = done;
            //an_event.data = -1;
            //enqueue(an_event, false);
          break;
        }
        break;
      default:
#ifdef DEBUG_STATE
        Serial.println("--unknown state--!!");
#endif
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
  delay(50);


















#ifdef DEBUG_QUEUE
int failed_tests = 0;
delay(3000);
Signal_item test;
test.sig = btn_down;
test.data = 5;
enqueue(test, false);
if (queue_size() != 1) {
  // failed test
  Serial.println("queue_size failed to report 1 after enqueue();");
  failed_tests++;
}
test.sig = btn_down;
test.data = 88;
enqueue(test, false);
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
