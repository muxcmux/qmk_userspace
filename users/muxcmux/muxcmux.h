#include QMK_KEYBOARD_H

// include ignored secrets definition
#if __has_include("secrets.h")
# include "secrets.h"
#endif

// define the macro keycodes
enum macro_keycodes {
    M_LOGIN = SAFE_RANGE,
};

// define dummy secrets values so we don't break compilation
// when the secrets header is missing
#ifndef SECRET_LOGIN
# define SECRET_LOGIN "lol"
#endif

bool handle_macros(uint16_t keycode, keyrecord_t *record);

// Define some short aliases for modifier keys
#define GUI_SPC LGUI_T(KC_SPC)
#define CTL_Z LCTL_T(KC_Z)
#define CTL_SLS RCTL_T(KC_SLSH)
#define S_EMOJI C(G(KC_SPC))
#define S_SPOTL G(KC_SPC)
#define S_SWWIN G(KC_GRV)
#define S_SCRSH LSG(KC_4)
#define LCA_S LCA(KC_S)
#define LCA_D LCA(KC_D)
#define LCA_F LCA(KC_F)
#define LCA_G LCA(KC_G)
#define LCA_X LCA(KC_X)
#define LCA_C LCA(KC_C)
#define LCA_V LCA(KC_V)
#define LCA_B LCA(KC_B)
#define MEH_S MEH(KC_S)
#define MEH_D MEH(KC_D)
#define MEH_F MEH(KC_F)
#define MEH_G MEH(KC_G)
#define MEH_X MEH(KC_X)
#define MEH_C MEH(KC_C)
#define MEH_V MEH(KC_V)
#define MEH_B MEH(KC_B)
#define MEH_ESC MEH(KC_ESC)
#define MEH_BSP MEH(KC_BSPC)
#define ALT_BSP LALT(KC_BSPC)

// The split layout

              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
#define L0R3       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L0R2        MO(2),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,   MO(1)
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L0R1      SC_LSPO,   CTL_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, CTL_SLS, SC_RSPC
              //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
#define L0R0                                          KC_LALT,  KC_SPC, KC_LGUI,     KC_ENT,   MO(3),   MO(4)
                                                  //`--------------------------'  `--------------------------'

              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
#define L1R3      M_LOGIN, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, XXXXXXX, S_EMOJI, _______
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L1R2      CW_TOGG, S_SPOTL,   LCA_S,   LCA_D,   LCA_F,   LCA_G,                      KC_MRWD, KC_VOLD, KC_VOLU, KC_MFFD, S_SCRSH, XXXXXXX
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L1R1      S_SWWIN, KC_LCTL,   LCA_X,   LCA_C,   LCA_V,   LCA_B,                      KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, XXXXXXX
              //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
#define L1R0                                          _______, _______, _______,    _______, _______, _______
                                                  //`--------------------------'  `--------------------------'

              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
#define L2R3      XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_PLUS, KC_LBRC, KC_RBRC, KC_MINS, XXXXXXX, _______
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L2R2      XXXXXXX,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                       KC_EQL, KC_LCBR, KC_RCBR, KC_UNDS, KC_PIPE, KC_BSLS
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L2R1      XXXXXXX,   KC_F11, KC_F12,  KC_F13,  KC_F14,  KC_F15,                       KC_GRV, KC_QUOT, KC_DQUO, KC_AMPR, KC_TILD, _______
              //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
#define L2R0                                          _______, _______, _______,    _______, _______, _______
                                                  //`--------------------------'  `--------------------------'

              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
#define L3R3      _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L3R2      _______,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, MEH_ESC, XXXXXXX
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L3R1      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, _______, _______, _______, _______
              //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
#define L3R0                                          _______, _______, _______,    _______, _______, _______
                                                  //`--------------------------'  `--------------------------'

              //,-----------------------------------------------------.                    ,-----------------------------------------------------.
#define L4R3      XXXXXXX, RGB_TOG, RGB_VAD, RGB_VAI, RGB_MOD, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L4R2      XXXXXXX, XXXXXXX, XXXXXXX,   MEH_D,   MEH_F,   MEH_G,                      XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX
              //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
#define L4R1      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
              //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
#define L4R0                                          _______, _______, ALT_BSP,    _______, _______, _______
                                                  //`--------------------------'  `--------------------------'
