// input definitions and functions

// input pins
#define BTN_REC_A 10
#define BTN_MODE  11
#define BTN_REC_B 12

byte btn_rec_a = 1;
byte btn_mode = 1;
byte btn_rec_b = 1;

// provide a function that does all the setup for all inputs
void setup_inputs() {
  pinMode(BTN_REC_A, INPUT_PULLUP);
  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BTN_REC_A, INPUT_PULLUP);
}

const bool no_duplicate = true;

// detect a button (or other input) change and enqueue a message.
void listen_inputs() {
  if (!digitalRead(BTN_REC_A)) {
    // button is down
    if (btn_rec_a) {
      btn_rec_a = 0;
      enqueue(RecA_dn, btn_rec_a, false, no_duplicate);
    }
  }
  else {
    // button is up
    if (!btn_rec_a) {
      btn_rec_a = 1;
      enqueue(RecA_up, btn_rec_a, false, no_duplicate);
    }
  }

  if (!digitalRead(BTN_MODE)) {
    // button is down
    if (btn_mode) {
      btn_mode = 0;
      enqueue(Mode_dn, btn_mode, true, no_duplicate);
    }
  }
  else {
    // button is up
    if (!btn_mode) {
      btn_mode = 1;
      //enqueue(Mode_up, btn_mode, false, no_duplicate);
    }
  }

  if (!digitalRead(BTN_REC_B)) {
    // Shutter button is down
    if (btn_rec_b) {
      btn_rec_b = 0;
      enqueue(RecB_dn, btn_rec_b, false, no_duplicate);
    }
  }
  else {
    // shutter button is up
    if (!btn_rec_b) {
      btn_rec_b = 1;
      //enqueue(RecB_up, btn_rec_b, false, no_duplicate);
    }
  }

}
