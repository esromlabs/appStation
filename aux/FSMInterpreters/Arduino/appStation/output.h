// put output functions here
#include <Arduino.h>
#define ON  1
#define OFF 0


void setup_outputs() {
  pinMode(13, OUTPUT);
}


void led(int state) {
  digitalWrite(13, state);
}

