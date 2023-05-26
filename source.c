#include QMK_KEYBOARD_H
#include "quantum/keycodes.h"
#include "layout.h"
#include "layers.h"
#include "flow.h"

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {OS_MOD, KC_LALT},
    {OS_MOD, KC_LGUI},
    {OS_MOD, KC_LCTL},
    {OS_MOD, KC_RCTL},
    {OS_MOD, KC_RGUI},
    {OS_MOD, KC_LSFT},
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_NUM, NUM},
    {OS_SYM, SYM},
    {OS_FUN, FUN},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;
    return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}

void leader_end_user(void) {
  if (leader_sequence_one_key(QK_LEAD)) {
    leader_end();
  }
  if (leader_sequence_one_key(KC_Q)) {
    send_unicode_string("æ");
    leader_end();
  }
  if (leader_sequence_one_key(KC_A)) {
    send_unicode_string("ø");
    leader_end();
  }
  if (leader_sequence_one_key(KC_Z)) {
    send_unicode_string("å");
    leader_end();
  }
  if (leader_sequence_five_keys(KC_S, KC_H, KC_R, KC_U, KC_G)) {
    send_unicode_string("¯\\_(ツ)_/¯");
    leader_end();
  }
}
