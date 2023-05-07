#pragma once

enum td_keycodes {
  SHFT_OSM // `LSFT` when held, one shot to mod layer when tapped.
};

// define a type containing as many tapdance states as you need
typedef enum {
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;
