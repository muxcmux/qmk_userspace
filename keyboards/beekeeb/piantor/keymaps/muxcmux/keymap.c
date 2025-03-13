#include QMK_KEYBOARD_H
#include "muxcmux.h"
#define layout(...) LAYOUT_split_3x6_3(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = layout(L0R3, L0R2, L0R1, L0R0),
  [1] = layout(L1R3, L1R2, L1R1, L1R0),
  [2] = layout(L2R3, L2R2, L2R1, L2R0),
  [3] = layout(L3R3, L3R2, L3R1, L3R0),
  [4] = layout(L4R3, L4R2, L4R1, L4R0)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return handle_macros(keycode, record);
}
