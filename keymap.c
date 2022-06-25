/* Kracko QMK sweep layout
 *
 * Custom Mac OS keymap for the Ferris Sweep
 */
#include QMK_KEYBOARD_H

#include "keymap_danish.h"

enum Layers {
    BASE_QWERTY_LAYER = 0,
    BASE_COLEMAK_DH_LAYER,
    SYMBOLS_LAYER,
    CTRL_NAV_LAYER,
    EXTRA_SYMBOLS_LAYER,
    CTRL_MEDIA_LAYER,
    GAMING_LAYER,
};

#define OSM_SFT_GUI OSM(MOD_LSFT | MOD_LGUI)
#define OSM_CTL_GUI OSM(MOD_LCTL | MOD_LGUI)
#define OSM_ALT_GUI OSM(MOD_LALT | MOD_LGUI)

#define KC_BRIGHT_UP         KC_PAUSE
#define KC_BRIGHT_DOWN       KC_SCROLL_LOCK
#define KC_LPAREN            LSFT(KC_8)
#define KC_RPAREN            LSFT(KC_9)
#define KC_LBRCK             LSFT(LALT(KC_8))
#define KC_RBRCK             LSFT(LALT(KC_9))
#define KC_DQUOTE            LSFT(KC_QUOTE)
#define KC_COPY              LGUI(KC_C)
#define KC_PASTE             LGUI(KC_V)
#define KC_CUT               LGUI(KC_X)
#define KC_SFTTAB            LSFT(KC_TAB)
#define KC_AMPERSAND         LSFT(KC_7)
#define KC_BAR               LALT(KC_I)
#define KC_HAT               LSFT(KC_RBRC)
#define KC_AE                KC_SEMICOLON
#define KC_OE                KC_QUOTE
#define KC_AA                KC_LBRC
#define KC_AT_               LALT(KC_BACKSLASH)
#define KC_SLASH_            LSFT(KC_7)
#define KC_BKSL              LALT(LSFT(KC_7))
#define KC_LABRCK            KC_GRAVE
#define KC_RABRCK            LSFT(KC_GRAVE)

#ifdef _USE_QWERTY_BASE_LAYER
    #define BASE_LAYER BASE_QWERTY_LAYER
#else
    #define BASE_LAYER BASE_COLEMAK_DH_LAYER
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_QWERTY_LAYER] = LAYOUT(
        KC_Q,         KC_W,         KC_E, KC_R, KC_T,            KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,
        LCTL_T(KC_A), LSFT_T(KC_S), KC_D, KC_F, KC_G,            KC_H,    KC_J,    KC_K,     KC_L,   DK_QUOT,
        KC_Z,         KC_X,         KC_C, KC_V, KC_B,            KC_N,    KC_M,    KC_COMMA, KC_DOT, LSFT_T(KC_SLASH_),

                         MO(CTRL_NAV_LAYER), KC_BSPC,            KC_SPACE, MO(SYMBOLS_LAYER)
    ),
    [BASE_COLEMAK_DH_LAYER] = LAYOUT(
        KC_Q,         KC_W,         KC_F, KC_P, KC_B,            KC_J,    KC_L, KC_U,     KC_Y,   KC_QUOTE,
        LCTL_T(KC_A), LSFT_T(KC_R), KC_S, KC_T, KC_G,            KC_M,    KC_N, KC_E,     KC_I,   KC_O,
        KC_Z,         KC_X,         KC_C, KC_D, KC_V,            KC_K,    KC_H, KC_COMMA, KC_DOT, LSFT_T(KC_SLSH),

                         MO(CTRL_NAV_LAYER), KC_BSPC,            KC_SPACE, MO(SYMBOLS_LAYER)
    ),
    [SYMBOLS_LAYER] = LAYOUT(
        KC_1,      KC_2,    KC_3,     KC_4,    KC_5,               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_LABRCK, DK_LPRN, KC_LBRCK, DK_LBRC, DK_AMPR,            DK_EQL,  DK_QUES, DK_UNDS, DK_PLUS, DK_ASTR,
        KC_RABRCK, DK_RPRN, KC_RBRCK, DK_RBRC, KC_BAR,             DK_TILD, DK_EXLM, DK_DQUO, DK_MINS, KC_AT_,

                                      _______, _______,            _______,       _______
    ),
    [CTRL_NAV_LAYER] = LAYOUT(
              _______, OSM_SFT_GUI,   OSM_CTL_GUI,   OSM_ALT_GUI,   LCMD(KC_SPACE),           TG(CTRL_MEDIA_LAYER), KC_ENTER, KC_ESCAPE, _______, _______,
/*CAPS_WORD*/ _______, KC_LSFT,       KC_LCMD,       KC_LALT,       KC_SPACE,                 KC_TAB,               KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,
              _______, OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LALT), _______,                  KC_SFTTAB,            KC_CUT,   KC_COPY,   KC_PASTE, _______,

                                                                 _______,  _______,            _______, _______
    ),
    [EXTRA_SYMBOLS_LAYER] = LAYOUT(
        _______, _______, _______,  _______,  _______,            _______,      KC_AE,         KC_OE,   KC_AA,     _______,
        _______, KC_LSFT, KC_SPACE, KC_BSPC,  _______,            LALT(KC_GRV), LSFT(KC_3),    KC_BKSL, KC_SLASH_, _______,
        _______, _______, _______,  _______,  _______,            KC_GRV,       LSFT(KC_LBRC), KC_HAT,  _______,   _______,

                                _______, _______,            _______, _______
    ),
    [CTRL_MEDIA_LAYER] = LAYOUT(
        _______, _______,                   _______, _______, QK_BOOTLOADER,    TG(CTRL_MEDIA_LAYER), _______,        _______,           _______,             _______,
        _______, DF(BASE_QWERTY_LAYER),     _______, _______, _______,          _______,              KC_BRIGHT_UP,   KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE, _______,
        _______, DF(BASE_COLEMAK_DH_LAYER), _______, _______, _______,          _______,              KC_BRIGHT_DOWN, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE,       _______,

                           TG(CTRL_MEDIA_LAYER), TG(CTRL_MEDIA_LAYER),          TG(CTRL_MEDIA_LAYER), TG(CTRL_MEDIA_LAYER)
    ),
    [GAMING_LAYER] = LAYOUT(
        _______, _______,  KC_W,   _______, _______,            _______, _______, _______, _______, _______,
        _______, KC_A,    KC_S,   KC_D,   _______,            _______, _______, _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______,            _______, _______, _______, _______, _______,

                                _______, _______,            _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, CTRL_NAV_LAYER, SYMBOLS_LAYER, EXTRA_SYMBOLS_LAYER);
}
