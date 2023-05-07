#include QMK_KEYBOARD_H
#include "quantum/keycodes.h"
#pragma once

#define TAPPING_TERM 200
#define RETRO_TAPPING

#define XXX KC_NO

// Layout alias wrapper
#define LAYOUT_36key(\
     K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
     K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
     K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
               K32, K33, K34,                K35, K36, K37 \
)\
LAYOUT_ergodox_pretty(\
XXX, XXX, XXX, XXX, XXX, XXX, XXX,      XXX, XXX, XXX, XXX, XXX, XXX, XXX,\
XXX, K00, K01, K02, K03, K04, XXX,      XXX, K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24, XXX,      XXX, K25, K26, K27, K28, K29, XXX,\
XXX, XXX, XXX, XXX, K32,                          K37, XXX, XXX, XXX, XXX,\
                         XXX, XXX,      XXX, XXX,\
                              XXX,      XXX,\
                    K33, K34, XXX,      XXX, K35, K36\
)

// Layout alias wrapper for use in json keymap
#define LAYOUT_36key_w(...) LAYOUT_36key(__VA_ARGS__)

enum layer_names {
    BSE,
    AUX,
    NAV,
    MOD,
    NUM,
    SYM,
    FUN
};

enum td_keycodes {
  SHFT_OSM // `LSFT` when held, one shot to mod layer when tapped.
};

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;

// function to determine the current tapdance state
int cur_dance (tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void shftosm_finished (tap_dance_state_t *state, void *user_data);
void shftosm_reset (tap_dance_state_t *state, void *user_data);

#define OS_SYM OSL(SYM)
#define OS_NAV OSL(NAV)
#define OS_AUX OSL(AUX)
#define OS_MOD OSL(MOD)
#define OS_NUM OSL(NUM)
#define OS_FUN OSL(FUN)

#define LT_AUX LT(AUX, KC_BSPC)
#define LT_NAV LT(NAV, KC_SPC)
#define LT_NUM LT(NUM, KC_ESC)
#define LT_SYM LT(SYM, KC_TAB)

#define OS_LCTL OSM(MOD_LCTL)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_LALT OSM(MOD_LALT)
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_RALT OSM(MOD_RALT)
#define OS_RGUI OSM(MOD_RGUI)
#define TD_SHFT TD(SHFT_OSM)

#define _BSE \
    KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_QUOT, \
    KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_M   , KC_N   , KC_E   , KC_I   , KC_O,    \
    KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, \
                      LT_AUX , LT_NAV , TD_SHFT, TD_SHFT, LT_NUM , LT_SYM
#define _AUX \
    _______, _______, KC_UP  , _______, _______, KC_BRID, KC_VOLD, KC_MUTE, KC_VOLU, KC_BRIU, \
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_MPRV, KC_MRWD, KC_MFFD, KC_MNXT, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
                      _______, _______, _______, _______, KC_MPLY, KC_MSTP
#define _NAV \
    KC_QUOT, KC_Y   , KC_U   , KC_L   , KC_J   , KC_AGIN, KC_PSTE, KC_COPY, KC_CUT , KC_UNDO, \
    KC_O   , KC_I   , KC_E   , KC_N   , KC_M   , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_CAPS, \
    KC_SLSH, KC_DOT , KC_COMM, KC_H   , KC_K   , KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS , \
                      _______, _______, _______, _______, KC_BSPC, KC_DEL
#define _MOD \
    QK_RBT , KC_APP , OS_NUM , OS_SYM , OS_FUN , OS_FUN , _______, _______, _______, _______, \
    KC_ESC , OS_LGUI, OS_LALT, OS_LCTL, KC_ENT , _______, OS_LCTL, OS_LALT, OS_LGUI, _______, \
    OS_LSFT, OS_RGUI, OS_RALT, OS_RCTL, _______, _______, _______, _______, _______, OS_LSFT, \
                      QK_LEAD, KC_TAB , _______, _______, QK_RBT , QK_LEAD
#define _NUM \
    KC_LBRC, KC_7   , KC_8   , KC_9   , KC_RBRC, _______, _______, _______, _______, _______, \
    KC_SCLN, KC_4   , KC_5   , KC_6   , KC_EQL , _______, _______, _______, _______, _______, \
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_BSLS, _______, _______, _______, _______, _______, \
                      KC_MINS, KC_0   , _______, _______, _______, _______
#define _SYM \
    KC_LCBR, KC_AMPR, KC_ASTR, KC_UNDS, KC_RCBR, _______, _______, _______, _______, _______, \
    KC_COLN, KC_DLR , KC_PERC, KC_CIRC, KC_PLUS, _______, _______, _______, _______, _______, \
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_PIPE, _______, _______, _______, _______, _______, \
                      KC_LPRN, KC_RPRN, _______, _______, _______, _______
#define _FUN \
    KC_F12 , KC_F7  , KC_F8  , KC_F9  , KC_PSCR, PB_1   , KC_F19 , KC_F20 , KC_F21 , KC_F24 , \
    KC_F11 , KC_F4  , KC_F5  , KC_F6  , KC_SCRL, PB_2   , KC_F16 , KC_F17 , KC_F18 , KC_F23 , \
    KC_F10 , KC_F1  , KC_F2  , KC_F3  , KC_PAUS, PB_3   , KC_F13 , KC_F14 , KC_F15 , KC_F22 , \
                      _______, _______, _______, _______, _______, _______
