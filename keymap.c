/* Kracko QMK sweep layout
 *
 * Custom Mac OS keymap for the Ferris Sweep
 */
#include QMK_KEYBOARD_H

#include "keymap_danish.h"

#define BASE_LAYER          0
#define SYMBOLS_LAYER       1
#define EXTRA_SYMBOLS_LAYER 2
#define CTRL_NAV_LAYER      3
#define CTRL_MEDIA_LAYER    4
#define GAMING_LAYER        5

// Return to base layer if pressed
#define RRRRRR      TG(BASE_LAYER)
#define OSM_SFT_GUI OSM(MOD_LSFT | MOD_LGUI)
#define OSM_CTL_GUI OSM(MOD_LCTL | MOD_LGUI)

#define KC_BRIGHT_UP         KC_PRINT_SCREEN
#define KC_BRIGHT_DOWN       KC_SCROLL_LOCK
#define KC_LPAREN            LSFT(KC_8)
#define KC_RPAREN            LSFT(KC_9)
#define KC_LBRACKET          LALT(KC_8)
#define KC_RBRACKET          LALT(KC_9)
#define KC_SLBRACKET         LSFT(LALT(KC_8))
#define KC_SRBRACKET         LSFT(LALT(KC_9))
#define KC_DQUOTE            LSFT(KC_QUOTE)
#define KC_COPY              LGUI(KC_C)
#define KC_PASTE             LGUI(KC_V)
#define KC_CUT               LGUI(KC_X)
#define KC_SFTTAB            LSFT(KC_TAB)
#define KC_AMPERSAND         LSFT(KC_7)
#define KC_BAR               LALT(KC_I)
#define KC_HAT               LSFT(KC_6)

/***************************************************************************************************
 * QWERTY layer
****************************************************************************************************/
const uint16_t BASE_QWERTY_LAYER[] = {
    KC_Q,         KC_W,         KC_E, KC_R, KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,\
    LCTL_T(KC_A), LSFT_T(KC_S), KC_D, KC_F, KC_G,            KC_H,    KC_J,    KC_K,     KC_L,   KC_QUOTE,\
    KC_Z,         KC_X,         KC_C, KC_V, KC_B,            KC_N,    KC_M,    KC_COMMA, KC_DOT, LSFT_T(KC_SLASH),\

                    MO(CTRL_NAV_LAYER), KC_SPACE,            KC_BSPC, MO(SYMBOLS_LAYER)
};

/***************************************************************************************************
 * Colemak DH layer
****************************************************************************************************/
const uint16_t BASE_COLEMAK_DH_LAYER[] = {
    KC_Q,         KC_W,         KC_F, KC_P, KC_B,            KC_J,    KC_L,              KC_U,     KC_Y,   KC_QUOTE,\
    LCTL_T(KC_A), LSFT_T(KC_R), KC_S, KC_T, KC_G,            KC_M,    KC_N,              KC_E,     KC_I,   KC_O,\
    KC_Z,         KC_X,         KC_C, KC_D, KC_V,            KC_K,    KC_H,              KC_COMMA, KC_DOT, LSFT_T(KC_SLSH),\

                    MO(CTRL_NAV_LAYER), KC_SPACE,            KC_BSPC, MO(SYMBOLS_LAYER)
};

#ifdef _USE_QWERTY_BASE_LAYER
    #define _BASE_LAYER BASE_QWERTY_LAYER
#else
    #define _BASE_LAYER BASE_COLEMAK_DH_LAYER
#endif

/***************************************************************************************************
 * Symbols layer
****************************************************************************************************/
const uint16_t _SYMBOLS_LAYER[] = {
    KC_1,       KC_2,      KC_3,        KC_4,                    KC_5,         KC_6,     KC_7,        KC_8,           KC_9,     KC_0,\
    KC_PERCENT, KC_LPAREN, KC_LBRACKET, KC_SLBRACKET,            KC_AMPERSAND, KC_EQUAL, KC_QUESTION, LSFT(KC_MINUS), KC_PLUS,  KC_ASTERISK,\
    KC_DOLLAR,  KC_RPAREN, KC_RBRACKET, KC_SRBRACKET,            KC_BAR,       KC_GRAVE, KC_EXCLAIM,  KC_DQUOTE,      KC_MINUS, KC_AT,\

                     MO(EXTRA_SYMBOLS_LAYER), ______,            ______,       ______
};

/***************************************************************************************************
 * Extra symbols layer
****************************************************************************************************/
const uint16_t _EXTRA_SYMBOLS_LAYER[] = {
    ______, ______, ______, ______,   ______,            ______, ______,       ______, ______, ______,\
    ______, ______, ______, KC_SPACE, ______,            ______, KC_COLON,     KC_BACKSLASH, KC_GRAVE, ______,\
    ______, ______, ______, ______,   ______,            ______, KC_SEMICOLON, KC_HAT, ______, ______,\

                              ______, ______,            ______, ______
};

/***************************************************************************************************
 * Control/Navigation layer (arrow keys are laid out as H, J, K, L)
****************************************************************************************************/
const uint16_t _CTRL_NAV_LAYER[] = {
    ______,    OSM_SFT_GUI,   OSM_CTL_GUI,   ______,        L_CMD(KC_SPACE),            TG(CTRL_MEDIA_LAYER), KC_ENTER, KC_ESCAPE, ______, ______,\
    CAPS_WORD, KC_LSFT,       KC_LCMD,       KC_LALT,       KC_SPACE,                   KC_TAB,               KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,\
    ______,    OSM(MOD_LSFT), OSM(MOD_LCMD), OSM(MOD_LALT), ______,                     KC_SFTTAB,            KC_CUT,   KC_COPY,   KC_PASTE, ______,\

                                                            ______,  ______,            ______, MO(_EXTRA_SYMBOLS_LAYER)
};

/***************************************************************************************************
 * Control/Media layer
****************************************************************************************************/
const uint16_t _CTRL_MEDIA_LAYER[] = {
    ______, QK_REBOOT, QK_BOOTLOADER, ______,              ______,          RRRRRR, ______,         ______,            ______,              ______,\
    ______, ______,    ______,        MOD_LSFT | MOD_LALT, ______,          ______, KC_BRIGHT_UP,   KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE, DF(BASE_QWERTY_LAYER),\
    ______, ______,    ______,        ______,              ______,          ______, KC_BRIGHT_DOWN, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE,       DF(BASE_COLEMAK_DH_LAYER),\
                                                   RRRRRR, RRRRRR,          RRRRRR, RRRRRR
}

/***************************************************************************************************
 * Gaming layer
****************************************************************************************************/
const uint16_t _GAMING_LAYER[] = {
    ______, ______,  KC_W,   ______, ______,            ______, ______, ______, ______, ______,\
    ______, KC_A,    KC_S,   KC_D,   ______,            ______, ______, ______, ______, ______,\
    KC_LCTL, ______, ______, ______, ______,            ______, ______, ______, ______, ______,\

                             ______, ______,            ______, ______
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

typedef struct {
    bool ctrl_nav_layer_pressed = false;
    bool symbols_layer_pressed = false;
} double_layer_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // If both primary layer switches are pressed, activate a new layer
        case MO(CTRL_NAV_LAYER):
            if (record->event.pressed) {
                if (double_layer_state.symbols_layer_pressed) {
                    layer_on(CTRL_MEDIA_LAYER);
                } else {
                    double_layer_state.ctrl_nav_layer_pressed = true;
                    layer_on(CTRL_NAV_LAYER);
                }
            } else {
                double_layer_state.ctrl_nav_layer_pressed = false;
            }
            return false;

        case MO(SYMBOLS_LAYER):
            if (record->event.pressed) {
                if (double_layer_state.ctrl_nav_layer_pressed) {
                    layer_on(CTRL_MEDIA_LAYER);
                } else {
                    double_layer_state.symbols_layer_pressed = true;
                    layer_on(SYMBOLS_LAYER);
                }
            } else {
                double_layer_state.symbols_layer_pressed = false;
            }
            return false;

        default:
            return true;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_LAYER]          = LAYOUT_split_3x5_2(_BASE_LAYER),
    [SYMBOLS_LAYER]       = LAYOUT_split_3x5_2(_SYMBOLS_LAYER),
    [EXTRA_SYMBOLS_LAYER] = LAYOUT_split_3x5_2(_EXTRA_SYMBOLS_LAYER),
    [CTRL_NAV_LAYER]      = LAYOUT_split_3x5_2(_CTRL_NAV_LAYER),
    [CTRL_MEDIA_LAYER]    = LAYOUT_split_3x5_2(_CTRL_MEDIA_LAYER),
    [GAMING_LAYER]        = LAYOUT_split_3x5_2(_GAMING_LAYER)
};
