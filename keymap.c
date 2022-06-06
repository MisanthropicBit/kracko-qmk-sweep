/* Kracko QMK sweep layout
 *
 * Custom Mac OS keymap for the Ferris Sweep
 */
#include QMK_KEYBOARD_H

#include "keymap_danish.h"

#define BASE_LAYER           0
#define SYMBOL_LAYER         1
#define CTRL_NAV_MEDIA_LAYER 2
#define QMK_LAYER            3
#define GAMING_LAYER         4

#define KC_BRIGHT_UP         KC_PRINT_SCREEN
#define KC_BRIGHT_DOWN       KC_SCROLL_LOCK
#define KC_LPAREN            LSFT(KC_8)
#define KC_RPAREN            LSFT(KC_9)
#define KC_LBRACKET          LALT(KC_8)
#define KC_RBRACKET          LALT(KC_8)
#define KC_SLBRACKET         LSFT(LALT(KC_8))
#define KC_SRBRACKET         LSFT(LALT(KC_9))
#define KC_DQUOTE            LSFT(KC_QUOTE)
#define KC_COPY              LGUI(KC_C)
#define KC_PASTE             LGUI(KC_V)
#define KC_CUT               LGUI(KC_X)
#define KC_LWORD             LALT(KC_LEFT)
#define KC_RWORD             RALT(KC_LEFT)
#define KC_LEND              LGUI(KC_LEFT)
#define KC_REND              RGUI(KC_RIGHT)
#define KC_SNAPSHOT_AREA     LSFT(LGUI(KC_4))
#define KC_STAB              LSFT(KC_TAB)

enum {
    TD_CTRL_LAYERS,
};

/***************************************************************************************************
 * QWERTY layer
****************************************************************************************************/
const uint16_t BASE_QWERTY_LAYER[] = {
    KC_Q,  KC_W,    KC_E,    KC_R,  KC_T,              KC_Y,   KC_U,    KC_I,     KC_O,   KC_P,\
    KC_A,  KC_S,    KC_D,    KC_F,  LATLT_T(KC_G),     KC_H,   KC_J,    KC_K,     KC_L,   KC_SCLN,\
    KC_Z,  KC_X,    KC_C,    KC_V,  KC_B,              KC_N,   KC_M,    KC_COMMA, KC_DOT, KC_SLSH,\
\
        TD(TD_CTRL_LAYERS), KC_SPC,              KC_BSPC, MO(SYMBOLS_LAYER)\
};

/***************************************************************************************************
 * Colemak DH layer
****************************************************************************************************/
const uint16_t BASE_COLEMAK_DH_LAYER[] = {
    KC_Q,  KC_W,    KC_F,    KC_P,  KC_B,              KC_J,   KC_L,    KC_U,     KC_Y,   KC_P,\
    KC_A,  KC_R,    KC_S,    KC_T,  LALT_T(KC_G),      KC_M,   KC_N,    KC_E,     KC_I,   KC_O,\
    KC_Z,  KC_X,    KC_C,    KC_D,  KC_V,              KC_K,   KC_H,    KC_COMMA, KC_DOT, KC_SLSH,\
\
        TD(TD_CTRL_LAYERS), KC_SPC,              KC_BSPC, MO(SYMBOLS_LAYER)\
};

/***************************************************************************************************
 * Symbols layer
****************************************************************************************************/
const uint16_t SYMBOLS_LAYER[] = {
    KC_1,       KC_2,      KC_3,        KC_4,         KC_5,               KC_6,     KC_7,      KC_8,     KC_9,        KC_0,
    KC_PERCENT, KC_LPAREN, KC_LBRACKET, KC_SLBRACKET, KC_COMMA,           KC_EQUAL, KC_QUESTION, KC_QUOTE,  KC_PLUS,  KC_ASTERISK,
    KC_DOLLAR,  KC_RPAREN, KC_RBRACKET, KC_SRBRACKET, KC_DOT,             KC_AT,    KC_EXCLAIM,  KC_DQUOTE, KC_MINUS, KC_SLASH,

                                        KC_, KC_SPACE,               KC_, _______
};

/***************************************************************************************************
 * Control/Navigation layer
****************************************************************************************************/
const uint16_t CTRL_NAV_LAYER[] = {
    KC_, KC_,     KC_UP,   KC_,      KC_,           KC_BRIGHT_DOWN, KC_BRIGHT_UP,      KC_,      KC_,    KC_BOOTLOADER,
    KC_CAPS, KC_LEFT, KC_DOWN, KC_RIGHT, KC_,       KC_LEND, KC_LWORD, KC_RWORD, KC_REND,    KC_TAB,
    KC_SNAPSHOT_AREA, KC_,     KC_,     KC_,        KC_, KC_COPY,  KC_PASTE, KC_CUT, KC_STAB,
                                _______, KC_,           KC_, KC_                
};

/***************************************************************************************************
 * Control/Media layer
****************************************************************************************************/
const uint16_t CTRL_MEDIA_LAYER[] = {
    KC_, KC_, KC_,            KC_,          KC_,            KC_, KC_, KC_, KC_, KC_,
    KC_, KC_, KC_BRIGHT_DOWN, KC_BRIGHT_UP, KC_,            KC_, KC_MEDIA_PLAY_PAUSE, KC_AUDIO_MUTE, KC_, KC_,
    KC_, KC_, KC_,            KC_,          KC_,            KC_, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_,
                                _______, KC_, KC_,            KC_
}

/***************************************************************************************************
 * QMK (bootloader/reset) layer
****************************************************************************************************/
const uint16_t QMK_LAYER[] = {
    KC_, KC_, KC_, KC_, KC_,               KC_, KC_, KC_, KC_, KC_,
    KC_, KC_, KC_, KC_, KC_,               KC_, KC_, KC_, KC_, KC_,
    KC_, KC_, KC_, KC_, KC_,               KC_, KC_, KC_, KC_, KC_,
                   KC_, KC_,               KC_, KC_                
};

/***************************************************************************************************
 * Gaming layer
****************************************************************************************************/
const uint16_t GAMING_LAYER[] = {
    KC_, KC_, KC_, KC_, KC_,               KC_, KC_, KC_, KC_, KC_,
    KC_, KC_, KC_, KC_, KC_,               KC_, KC_, KC_, KC_, KC_,
    KC_, KC_, KC_, KC_, KC_,               KC_, KC_, KC_, KC_, KC_,
                   KC_, KC_,               KC_, KC_                
};

const uint16_t QWERTY_LAYOUT[] = {
    KC_Q,         KC_W,         KC_E,            KC_R,           KC_T,
    KC_Y,         KC_U,         KC_I,            KC_O,           KC_P,
    LSFT_T(KC_A), LT(5, KC_S),  LT(1, KC_D),     LT(3, KC_F),    KC_G,
    KC_H,         LT(4, KC_J),  LT(2, KC_K),     LT(6,KC_L),     LSFT_T(KC_SCLN),
    KC_Z,         LCTL_T(KC_X), LALT_T(KC_C),    KC_V,           KC_B,
    KC_N,         KC_M,         LALT_T(KC_COMM), LCTL_T(KC_DOT), KC_SLSH,
    KC_P0,        KC_BSPC,      LT(7, KC_SPC),   KC_P1
};

/***************************************************************************************************
 * Combos
****************************************************************************************************/
const uint16_t PROGMEM combo1[] = {CTRL_NAV_MEDIA_LAYER, SYMBOLS_LAYER, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo1, KC_)
};

/***************************************************************************************************
 * Tap dance
****************************************************************************************************/
void tapdance_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        layer_on(CTRL_MEDIA_LAYER);
    } else {
        layer_on(CTRL_NAV_LAYER);
    }
}

void dance_cln_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_COLN);
    } else {
        unregister_code(KC_SCLN);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_CTRL_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_cln_finished, dance_cln_reset)
};















const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_LAYER] = LAYOUT_split_3x5_2(BASE_QWERTY_LAYOUT),
    [1] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_WH_U, KC_BTN2, KC_TRNS, KC_TRNS, KC_BTN2, KC_NO, KC_BTN1, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [2] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LGUI, KC_NO, LCTL(KC_LALT), LCA(KC_LSFT), KC_TRNS, KC_HOME, KC_PGDN, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [3] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_UNDS, KC_PIPE, KC_QUOT, KC_TRNS, KC_CIRC, KC_ASTR, KC_AMPR, KC_NO, KC_TRNS, KC_HASH, KC_TILD, KC_SLSH, KC_DQUO, KC_DLR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_BSLS, KC_GRV, KC_TRNS, RGB_RMOD, KC_TRNS, KC_TRNS, RGB_MOD),
    [4] = LAYOUT_split_3x5_2(KC_TRNS, KC_COLN, KC_LT, KC_GT, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_AT, KC_TRNS, KC_NO, KC_EQL, KC_PLUS, KC_PERC, KC_TRNS, KC_EXLM, KC_LBRC, KC_RBRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_TRNS, KC_VOLU),
    [5] = LAYOUT_split_3x5_2(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_NO, LCTL(KC_LALT), KC_TRNS, KC_TRNS, KC_TRNS, KC_F4, KC_F5, KC_F6, KC_F11, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [6] = LAYOUT_split_3x5_2(KC_PSLS, KC_7, KC_8, KC_9, KC_PPLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_1, KC_2, KC_3, KC_PMNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_PAST, KC_4, KC_5, KC_6, KC_PEQL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [7] = LAYOUT_split_3x5_2(BASE_COLEMAK_DH_LAYOUT)
};
