#pragma once

enum td_keycodes {
  SHFT_OSM // `LSFT` when held, one shot to mod layer when tapped.
};

typedef enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  TRIPLE_TAP = 5,
  TRIPLE_HOLD = 6
} td_state_t;
