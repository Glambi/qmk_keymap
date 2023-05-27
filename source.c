#include QMK_KEYBOARD_H
#include "quantum/keycodes.h"
#include "layout.h"
#include "layers.h"
#include "flow.h"
#include "layer_lock.h"

// flow_config should correspond to following format:
// * layer keycode
// * modifier keycode
const uint16_t flow_config[FLOW_COUNT][2] = {
    {OS_MOD, KC_LALT},
    {OS_MOD, KC_LGUI},
    {OS_MOD, KC_LCTL},
    {OS_MOD, KC_RALT},
    {OS_MOD, KC_RCTL},
    {OS_MOD, KC_RGUI},
    {OS_MOD, KC_LSFT},
};

const uint16_t flow_layers_config[FLOW_LAYERS_COUNT][2] = {
    {OS_NUM, NUM},
    {OS_SYM, SYM},
    {OS_FUN, FUN},
    {OS_NAV, NAV},
    {OS_MOD, MOD},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_layer_lock(keycode, record, L_LOCK)) { return false; }
    if (!update_flow(keycode, record->event.pressed, record->event.key)) return false;
    return true;
}

void matrix_scan_user(void) {
    flow_matrix_scan();
}

void leader_end_user(void) {
    // RESET = restart the keyboard
  if (leader_sequence_five_keys(KC_R, KC_E, KC_S, KC_E, KC_T)) {
    soft_reset_keyboard();
    // FLASH = restart into bootloader
  } if (leader_sequence_five_keys(KC_F, KC_L, KC_A, KC_S, KC_H)) {
    reset_keyboard();
    // WIPE = clear EEPROM
  } if (leader_sequence_four_keys(KC_W, KC_I, KC_P, KC_E)) {
    eeconfig_init();
    leader_end();
  }

}
