#include QMK_KEYBOARD_H
#include "quantum/keycodes.h"
#include "layout.h"
#include "layers.h"
#include "enums.h"

// function to determine the current tapdance state
int cur_dance (tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void shftosm_finished (tap_dance_state_t *state, void *user_data);
void shftosm_reset (tap_dance_state_t *state, void *user_data);

int cur_dance (tap_dance_state_t *state) {
  if (state->count == 1) {
    if (state->pressed) return SINGLE_HOLD;
    else return SINGLE_TAP;
  }
  else if (state->count == 2) {
    if (state->pressed) return DOUBLE_HOLD;
    else return DOUBLE_TAP;
  }
  else if (state->count == 3) {
    if (state->interrupted || !state->pressed)  return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  }
  else return 8;
}
typedef struct {
  bool is_press_action;
  int state;
} tap;

static tap shftap_state = {
  .is_press_action = true,
  .state = 0
};


// handle the possible states for each tapdance keycode you define:
void shftosm_finished (tap_dance_state_t *state, void *user_data) {
  shftap_state.state = cur_dance(state);
  switch (shftap_state.state) {
    case SINGLE_TAP: set_oneshot_layer(MOD, ONESHOT_START); clear_oneshot_layer_state(ONESHOT_PRESSED); break;
    case SINGLE_HOLD: register_code(KC_LSFT); break;
    case DOUBLE_TAP: set_oneshot_layer(MOD, ONESHOT_START); set_oneshot_layer(MOD, ONESHOT_PRESSED); break;
    case DOUBLE_HOLD: register_code(KC_LSFT); layer_on(MOD); break;
  }
}

void shftosm_reset (tap_dance_state_t *state, void *user_data) {
  switch (shftap_state.state) {
    case SINGLE_TAP: break;
    case SINGLE_HOLD: unregister_code(KC_LSFT); break;
    case DOUBLE_TAP: break;
    case DOUBLE_HOLD: layer_off(MOD); unregister_code(KC_LSFT); break;
  }
  shftap_state.state = 0;
}

// define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
  [SHFT_OSM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, shftosm_finished, shftosm_reset)
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case KC_TRNS:
    case KC_NO:
      /* Always cancel one-shot layer when another key gets pressed */
      if (record->event.pressed && is_oneshot_layer_active())
      clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      return true;
    case QK_RBT:
      /* Don't allow reset from oneshot layer state */
      if (record->event.pressed && is_oneshot_layer_active()){
        clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        return false;
      }
      return true;
    default:
      return true;
  }
  return true;
}
