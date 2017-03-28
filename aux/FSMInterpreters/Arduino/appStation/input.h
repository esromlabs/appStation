// input definitions and functions

// example Analog pin
int sensorPin = A2;
int sensorValue = 0;

byte BTN_1_PIN = 5;
byte button_state_1 = 1; // 1 is up, 0 is down

// provide a function that does all the setup for all inputs
void setup_inputs() {
  pinMode(BTN_1_PIN, INPUT_PULLUP);
}

// detect a button (or other input) change and enqueue a message.
void listen_inputs() {
  if (!digitalRead(BTN_1_PIN)) {
    // Shutter button is down
    if (button_state_1) {
      button_state_1 = 0;
      //enqueue(btn_1, button_state_1, false, false);
    }
  }
  else {
    // shutter button is up
    if (!button_state_1) {
      button_state_1 = 1;
      //enqueue(btn_1, button_state_1, false, false);
    }
  }
}
