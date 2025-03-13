const uint16_t PROGMEM jk_escape_combo[] = { KC_J, KC_K, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
  COMBO(jk_escape_combo, KC_ESC)
};
