


// AdaFruit 12 key capacitive touch breakout board
// You can have up to 4 on one i2c bus but one is enough for testing!
Adafruit_MPR121 cap = Adafruit_MPR121();

// Keeps track of the last pins touched
// so we know when buttons change
uint16_t lasttouched = 0;
uint16_t currtouched = 0;

// detect a button change and enqueue a message.
void listen_inputs() {
  currtouched = cap.touched();

  for (uint8_t i=0; i<4; i++) {
    // it if *is* touched and *wasnt* touched before, aka btn_down
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
      enqueue(btn_down, i, false, false);
      //Serial.print(i); Serial.println(" touched");
    }
    // if it *was* touched and now *isnt*, aka btn_up
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      enqueue(btn_up, i, false, false);
      //Serial.print(i); Serial.println(" released");
    }
  }

  // reset our state
  lasttouched = currtouched;
  return;
}

boolean is_btn_down(uint8_t btn_index) {
  return (currtouched & _BV(btn_index));
}
