/* Kracko QMK sweep layout
 *
 * Custom Mac OS keymap for the Ferris Sweep
 */
#include QMK_KEYBOARD_H

#include "keymap_danish.h"

#define BASE_QWERTY_LAYER     0
#define BASE_COLEMAK_DH_LAYER 1
#define SYMBOLS_LAYER         2
#define EXTRA_SYMBOLS_LAYER   3
#define CTRL_NAV_LAYER        4
#define CTRL_MEDIA_LAYER      5
#define GAMING_LAYER          6

// Return to base layer if pressed
#define RRRRRR      TG(BASE_LAYER)
#define OSM_SFT_GUI OSM(MOD_LSFT | MOD_LGUI)
#define OSM_CTL_GUI OSM(MOD_LCTL | MOD_LGUI)

#define KC_BRIGHT_UP         KC_PRINT_SCREEN
#define KC_BRIGHT_DOWN       KC_SCROLL_LOCK
#define KC_LPAREN            LSFT(KC_8)
#define KC_RPAREN            LSFT(KC_9)
/* #define KC_LBRACKET          LALT(KC_8) */
/* #define KC_RBRACKET          LALT(KC_9) */
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

#ifdef _USE_QWERTY_BASE_LAYER
    #define BASE_LAYER BASE_QWERTY_LAYER
#else
    #define BASE_LAYER BASE_COLEMAK_DH_LAYER
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_QWERTY_LAYER] = LAYOUT(
        KC_Q,         KC_W,         KC_E, KC_R, KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,
        LCTL_T(KC_A), LSFT_T(KC_S), KC_D, KC_F, KC_G,            KC_H,    KC_J,    KC_K,     KC_L,   KC_QUOTE,
        KC_Z,         KC_X,         KC_C, KC_V, KC_B,            KC_N,    KC_M,    KC_COMMA, KC_DOT, LSFT_T(KC_SLASH),

                        MO(CTRL_NAV_LAYER), KC_SPACE,            KC_BSPC, MO(SYMBOLS_LAYER)
    ),
    [BASE_COLEMAK_DH_LAYER] = LAYOUT(
        KC_Q,         KC_W,         KC_F, KC_P, KC_B,            KC_J,    KC_L,              KC_U,     KC_Y,   KC_QUOTE,
        LCTL_T(KC_A), LSFT_T(KC_R), KC_S, KC_T, KC_G,            KC_M,    KC_N,              KC_E,     KC_I,   KC_O,
        KC_Z,         KC_X,         KC_C, KC_D, KC_V,            KC_K,    KC_H,              KC_COMMA, KC_DOT, LSFT_T(KC_SLSH),

                        MO(CTRL_NAV_LAYER), KC_SPACE,            KC_BSPC, MO(SYMBOLS_LAYER)
    ),
    [SYMBOLS_LAYER] = LAYOUT(
        KC_1,       KC_2,      KC_3,        KC_4,                    KC_5,         KC_6,     KC_7,        KC_8,           KC_9,     KC_0,
        KC_PERCENT, KC_LPAREN, KC_LBRACKET, KC_SLBRACKET,            KC_AMPERSAND, KC_EQUAL, KC_QUESTION, LSFT(KC_MINUS), KC_PLUS,  KC_ASTERISK,
        KC_DOLLAR,  KC_RPAREN, KC_RBRACKET, KC_SRBRACKET,            KC_BAR,       KC_GRAVE, KC_EXCLAIM,  KC_DQUOTE,      KC_MINUS, KC_AT,

                        MO(EXTRA_SYMBOLS_LAYER), _______,            _______,       _______
    ),
    [EXTRA_SYMBOLS_LAYER] = LAYOUT(
        _______, _______, _______, _______,   _______,            _______, _______,       _______, _______, _______,
        _______, _______, _______, KC_SPACE, _______,            _______, KC_COLON,     KC_BACKSLASH, KC_GRAVE, _______,
        _______, _______, _______, _______,   _______,            _______, KC_SEMICOLON, KC_HAT, _______, _______,

                                _______, _______,            _______, _______
    ),
    [CTRL_NAV_LAYER] = LAYOUT(
        _______,   OSM_SFT_GUI,   OSM_CTL_GUI,   _______,        LCMD(KC_SPACE),            TG(CTRL_MEDIA_LAYER), KC_ENTER, KC_ESCAPE, _______, _______,
        _______ /*CAPS_WORD*/, KC_LSFT,       KC_LCMD,       KC_LALT,       KC_SPACE,                   KC_TAB,               KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,
        _______,   OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LALT), _______,                     KC_SFTTAB,            KC_CUT,   KC_COPY,   KC_PASTE, _______,

                                                                _______,  _______,            _______, MO(EXTRA_SYMBOLS_LAYER)
    ),
    [CTRL_MEDIA_LAYER] = LAYOUT(
        _______, _______, QK_BOOTLOADER, _______,              _______,          RRRRRR, _______,         _______,            _______,              _______,
        _______, _______, _______,        _______, _______,          _______, KC_BRIGHT_UP,   KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE, DF(BASE_QWERTY_LAYER),
        _______, _______, _______,        _______,              _______,          _______, KC_BRIGHT_DOWN, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE,       DF(BASE_COLEMAK_DH_LAYER),

                                                    RRRRRR, RRRRRR,          RRRRRR, RRRRRR
    ),
    [GAMING_LAYER] = LAYOUT(
        _______, _______,  KC_W,   _______, _______,            _______, _______, _______, _______, _______,
        _______, KC_A,    KC_S,   KC_D,   _______,            _______, _______, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______,            _______, _______, _______, _______, _______,

                                _______, _______,            _______, _______
    )
};
