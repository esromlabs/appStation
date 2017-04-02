// put output functions here
#include <Arduino.h>
// output pins
#define REC_ON LOW
#define REC_OFF HIGH
#define PLAY_ON LOW
#define PLAY_OFF HIGH
#define PLAY_1  6
#define REC_1   7
#define PLAY_2  8
#define REC_2   9

enum {board_rec_on, board_rec_off, click_play_on, click_play_off};

void setup_outputs() {
  pinMode(13, OUTPUT);
  pinMode(PLAY_1, OUTPUT);
  pinMode(REC_1,  OUTPUT);
  pinMode(PLAY_2, OUTPUT);
  pinMode(REC_2,  OUTPUT);
  
  digitalWrite(13, HIGH);
  digitalWrite(REC_1, REC_OFF);
  digitalWrite(REC_2, REC_OFF);
  digitalWrite(PLAY_1, PLAY_OFF);
  digitalWrite(PLAY_2, PLAY_OFF);

}

void sound_board(byte board, byte button) {
  if (board == 0) {
    if (button == board_rec_on) {
      digitalWrite(REC_1, REC_ON);
      digitalWrite(13, HIGH);
    }
    else if (button == board_rec_off) {
      digitalWrite(REC_1, REC_OFF);
      digitalWrite(13, LOW);
    }
    else if (button == click_play_on) {
      digitalWrite(PLAY_1, PLAY_ON);
    }
    else if (button == click_play_off) {
      digitalWrite(PLAY_1, PLAY_OFF);
    }
  }
  else if (board == 1) {
    if (button == board_rec_on) {
      digitalWrite(REC_2, REC_ON);
    }
    else if (button == board_rec_off) {
      digitalWrite(REC_2, REC_OFF);
    }
    else if (button == click_play_on) {
      digitalWrite(PLAY_2, PLAY_ON);
    }
    else if (button == click_play_off) {
      digitalWrite(PLAY_2, PLAY_OFF);
    }
  }
}

void led(int state) {
  digitalWrite(13, state);
}

