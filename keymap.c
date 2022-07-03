/* Kracko QMK sweep layout
 *
 * Custom Mac OS keymap for the Ferris Sweep
 */
#include QMK_KEYBOARD_H

#include "keymap_danish.h"

enum layers {
    BASE_QWERTY_LAYER = 0,
    BASE_COLEMAK_DH_LAYER,
    SYMBOLS_LAYER,
    CTRL_NAV_LAYER,
    NUMBER_LAYER,
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
#define KC_TICK              KC_EQUAL
#define KC_BTICK             LSFT(KC_EQUAL)
#define KC_UMLAUT            KC_RBRC
#define KC_HASH              LSFT(KC_3)
#define DK_DOLLAR            LSFT(RALT(KC_3))

#ifdef _USE_QWERTY_BASE_LAYER
    #define BASE_LAYER BASE_QWERTY_LAYER
#else
    #define BASE_LAYER BASE_COLEMAK_DH_LAYER
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_QWERTY_LAYER] = LAYOUT(
        KC_Q, KC_W, KC_E, KC_R, KC_T,            KC_Y, KC_U, KC_I,     KC_O,   KC_P,
        KC_A, KC_S, KC_D, KC_F, KC_G,            KC_H, KC_J, KC_K,     KC_L,   DK_QUOT,
        KC_Z, KC_X, KC_C, KC_V, KC_B,            KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH_,

         MO(CTRL_NAV_LAYER), KC_BSPC,            KC_SPACE, MO(SYMBOLS_LAYER)
    ),
    [BASE_COLEMAK_DH_LAYER] = LAYOUT(
        KC_Q, KC_W, KC_F, KC_P, KC_B,            KC_J, KC_L, KC_U,     KC_Y,   DK_QUOT,
        KC_A, KC_R, KC_S, KC_T, KC_G,            KC_M, KC_N, KC_E,     KC_I,   KC_O,
        KC_Z, KC_X, KC_C, KC_D, KC_V,            KC_K, KC_H, KC_COMMA, KC_DOT, KC_SLASH_,

         MO(CTRL_NAV_LAYER), KC_BSPC,            KC_SPACE, MO(SYMBOLS_LAYER)
    ),
    [SYMBOLS_LAYER] = LAYOUT(
        DK_DOLLAR, KC_HAT,  KC_TICK,  KC_BTICK, KC_HASH,            DK_DLR,  KC_AE,   KC_OE,   KC_AA,   KC_UMLAUT,
        KC_LABRCK, DK_LPRN, KC_LBRCK, DK_LBRC,  DK_AMPR,            DK_EQL,  DK_QUES, DK_UNDS, DK_PLUS, DK_ASTR,
        KC_RABRCK, DK_RPRN, KC_RBRCK, DK_RBRC,  KC_BAR,             DK_TILD, DK_EXLM, DK_DQUO, DK_MINS, KC_AT_,

                                       _______, _______,            _______,       _______
    ),
    [CTRL_NAV_LAYER] = LAYOUT(
        _______,   OSM_SFT_GUI,   OSM_CTL_GUI,   OSM_ALT_GUI,   LCMD(KC_SPACE),           TG(CTRL_MEDIA_LAYER), KC_ENTER, KC_ESCAPE, _______,  _______,
        CAPS_WORD, KC_LSFT,       KC_LCMD,       KC_LALT,       KC_SPACE,                 KC_TAB,               KC_LEFT,  KC_DOWN,   KC_UP,    KC_RIGHT,
        _______,   OSM(MOD_LSFT), OSM(MOD_LGUI), OSM(MOD_LALT), KC_BSPC,                  KC_SFTTAB,            KC_CUT,   KC_COPY,   KC_PASTE, _______,

                                                             _______,  _______,            _______, _______
    ),
    [NUMBER_LAYER] = LAYOUT(
        XXXXXXX, KC_SPACE, DK_PLUS, DK_MINS, XXXXXXX,            XXXXXXX, DK_ASTR, KC_SLASH_, DK_PERC, XXXXXXX,
        KC_1,    KC_2,     KC_3,    KC_4,    KC_5,               KC_6,    KC_7,    KC_8,      KC_9,    KC_0,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX, KC_COMMA,  KC_DOT,  DK_EQL,

                                    XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX
    ),
    [CTRL_MEDIA_LAYER] = LAYOUT(
        _______, _______,                   _______, _______, QK_BOOTLOADER,            TG(CTRL_MEDIA_LAYER), TG(GAMING_LAYER), _______,           _______,             _______,
        _______, DF(BASE_QWERTY_LAYER),     _______, _______, _______,                  _______,              KC_BRIGHT_UP,     KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE, _______,
        _______, DF(BASE_COLEMAK_DH_LAYER), _______, _______, _______,                  _______,              KC_BRIGHT_DOWN,   KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE,       _______,

                                 TG(CTRL_MEDIA_LAYER), TG(CTRL_MEDIA_LAYER),            TG(CTRL_MEDIA_LAYER), TG(CTRL_MEDIA_LAYER)
    ),
    [GAMING_LAYER] = LAYOUT(
        _______, _______, KC_W,    _______, _______,            _______, TG(GAMING_LAYER), _______, _______, _______,
        _______, KC_A,    KC_S,    KC_D,    _______,            _______, _______,          _______, _______, _______,
        KC_LCTL, _______, _______, _______, _______,            _______, _______,          _______, _______, _______,

                                   _______, _______,            _______, _______
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, CTRL_NAV_LAYER, SYMBOLS_LAYER, NUMBER_LAYER);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Combos
//////////////////////////////////////////////////////////////////////////////////////////

enum combo_events {
  LSFT = 0,
  RSFT,
  LCTL,
  RCTL,
  LSFT_LCMD,
  RSFT_RCMD,
  LGUI,
  RGUI,
  COMBO_LENGTH,
};

uint16_t COMBO_LEN = COMBO_LENGTH;

// For QWERTY
const uint16_t PROGMEM left_shift[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM right_shift[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM left_ctrl[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM right_ctrl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lsft_lcmd[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM rsft_rcmd[] = {KC_M, KC_COMMA, COMBO_END};
const uint16_t PROGMEM lgui[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM rgui[] = {KC_U, KC_I, COMBO_END};

combo_t key_combos[] = {
    [LSFT] = COMBO(left_shift, KC_LSFT),
    [RSFT] = COMBO(right_shift, KC_RSFT),
    [LCTL] = COMBO(left_ctrl, KC_LCTL),
    [RCTL] = COMBO(right_ctrl, KC_RCTL),
    [LSFT_LCMD] = COMBO(lsft_lcmd, LSFT(KC_LGUI)),
    [RSFT_RCMD] = COMBO(rsft_rcmd, RSFT(KC_RGUI)),
    [LGUI] = COMBO(lgui, KC_LGUI),
    [RGUI] = COMBO(rgui, KC_RGUI),
};

//////////////////////////////////////////////////////////////////////////////////////////
// CAPS_WORD configuration
//////////////////////////////////////////////////////////////////////////////////////////

// Custom caps_word implementation to account for Danish underscore
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            // Apply shift to next key.
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case DK_UNDS:
            return true;

        default:
            // Deactivate Caps Word.
            return false;
    }
};
