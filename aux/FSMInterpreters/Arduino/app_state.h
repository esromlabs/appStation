// state machine vars and methods
typedef enum { blank, dec_player, inc_non_player, phase_2, dec_non_player, inc_player, phase_1, pick_player, init_game, whos_who, start } State;
typedef enum { btn_down, times_up, btn_up, done } Signal;
State state;
// setup pre-init state
void setup_pre_init_state() { state = (State)-1; }
// onTick processor function
void onTick_processor() {
  switch (state) {
  }
}

  // onEnterState processor function
void onEnterState_processor() {
  switch (state) {
    case phase_1 :
      set_timer(2000);
    break;
    case pick_player :
      random_player(); set_timer(1500);
    break;
    case init_game :
      set_players(); display(home_colors);
    break;
    case whos_who :
      set_timer(3000);
    break;
    case start :
      display(question_mark);
    break;
  }
}

  // process the state transition
int state_trans_processor(int state, int sig, int sig_data) {
  switch (state) {
      case blank :
        switch (sig) {
          case done :
            state = pick_player;
          break;
        }
      break;
      case dec_player :
        switch (sig) {
          case done :
            state = phase_2;
          break;
        }
      break;
      case inc_non_player :
        switch (sig) {
          case done :
            state = phase_2;
          break;
        }
      break;
      case phase_2 :
        switch (sig) {
          case times_up :
            state = blank;
          break;
          case btn_down :
                  // evaluate guard expression
            if(sig_data != current_player) {
                state = inc_non_player;
              }
                  // evaluate guard expression
              else             if(sig_data == current_player) {
                state = dec_player;
              }
          break;
        }
      break;
      case dec_non_player :
        switch (sig) {
          case done :
            state = phase_1;
          break;
        }
      break;
      case inc_player :
        switch (sig) {
          case done :
            state = phase_2;
          break;
        }
      break;
      case phase_1 :
        switch (sig) {
          case btn_down :
                  // evaluate guard expression
            if(sig_data == current_player) {
                state = inc_player;
              }
                  // evaluate guard expression
              else             if(sig_data !=  current_player) {
                state = dec_non_player;
              }
              else {
                state = phase_2;
            }
          break;
          case times_up :
            state = blank;
          break;
        }
      break;
      case pick_player :
        switch (sig) {
          case done :
            state = phase_1;
          break;
        }
      break;
      case init_game :
        switch (sig) {
          case done :
            state = pick_player;
          break;
        }
      break;
      case whos_who :
        switch (sig) {
          case times_up :
            state = init_game;
          break;
          case btn_up :
            state = start;
          break;
        }
      break;
      case start :
        switch (sig) {
          case btn_down :
            state = whos_who;
          break;
        }
      break;
  }
}
