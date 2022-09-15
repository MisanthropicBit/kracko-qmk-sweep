/* Kracko QMK sweep layout
 *
 * Custom Mac OS keymap for the Ferris Sweep
 */
#include QMK_KEYBOARD_H

#include "config.h"
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

// Allow combos on all layers as if they were on the QWERTY layer
#define COMBO_ONLY_FROM_LAYER BASE_QWERTY_LAYER

#define COMBO_SHOULD_TRIGGER
#define COMBO_TERM 50

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
#define KC_APP_CYCLE         LCMD(LSFT(KC_BTICK))

// Add home row mods on number layer for quick access to e.g. CMD + SHIFT + 7
#define _KC_1 LGUI_T(KC_1)
#define _KC_2 LALT_T(KC_2)
#define _KC_3 LCTL_T(KC_3)
#define _KC_4 LSFT_T(KC_4)
#define _KC_7 LSFT_T(KC_7)
#define _KC_8 LCTL_T(KC_8)
#define _KC_9 LALT_T(KC_9)
#define _KC_0 LGUI_T(KC_0)

#ifdef DYNAMIC_TAPPING_TERM_ENABLE
    #define KC_DT_UP   DT_UP
    #define KC_DT_DOWN DT_DOWN
    #define KC_DT_PRNT DT_PRNT
#else
    #define KC_DT_UP   _______
    #define KC_DT_DOWN _______
    #define KC_DT_PRNT _______
#endif

#ifdef KRACKO_USE_COLEMAK_DH_BASE_LAYER
    #define BASE_LAYER BASE_COLEMAK_DH_LAYER
#else
    #define BASE_LAYER BASE_QWERTY_LAYER
#endif

#ifdef KRACKO_HOME_ROW_MODS
    // Colemak DH home row mods
    #define _KC_A LGUI_T(KC_A)
    #define _KC_R LALT_T(KC_R)
    #define _KC_S LCTL_T(KC_S)
    #define _KC_T LSFT_T(KC_T)

    #define _KC_N LSFT_T(KC_N)
    #define _KC_E LCTL_T(KC_E)
    #define _KC_I LALT_T(KC_I)
    #define _KC_O LGUI_T(KC_O)

    // QWERTY home row mods
    #define KC_A_ LGUI_T(KC_A)
    #define KC_S_ LALT_T(KC_S)
    #define KC_D_ LCTL_T(KC_D)
    #define KC_F_ LSFT_T(KC_F)

    #define KC_J_    LSFT_T(KC_J)
    #define KC_K_    LCTL_T(KC_K)
    #define KC_L_    LALT_T(KC_L)
    #define DK_QUOT_ LGUI_T(DK_QUOT)

    #define KC_Z_    LSFT_T(KC_Z)
    #define DK_MINS_  LSFT_T(DK_MINS)
#else
    #define _KC_A    KC_A
    #define _KC_R    KC_R
    #define _KC_S    KC_S
    #define _KC_T    KC_T
    #define _KC_N    KC_N
    #define _KC_E    KC_E
    #define _KC_I    KC_I
    #define _KC_O    KC_O

    #define KC_A_    KC_A
    #define KC_S_    KC_S
    #define KC_D_    KC_D
    #define KC_F_    KC_F
    #define KC_J_    KC_J
    #define KC_K_    KC_K
    #define DK_QUOT_ DK_QUOT
    #define KC_L_    KC_L

    #define KC_Z_    KC_Z
    #define DK_MINS_ DK_MINS
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE_QWERTY_LAYER] = LAYOUT(
        KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,            KC_Y, KC_U,  KC_I,     KC_O,   KC_P,
        KC_A_, KC_S_, KC_D_, KC_F_, KC_G,            KC_H, KC_J_, KC_K_,    KC_L_,  DK_QUOT_,
        KC_Z_, KC_X,  KC_C,  KC_V,  KC_B,            KC_N, KC_M,  KC_COMMA, KC_DOT, DK_MINS_,

     LT(CTRL_NAV_LAYER, KC_TAB), KC_BSPC,            KC_SPACE, LT(SYMBOLS_LAYER, KC_ENTER)
    ),
    [BASE_COLEMAK_DH_LAYER] = LAYOUT(
        KC_Q,  KC_W,  KC_F,  KC_P,  KC_B,            KC_J, KC_L,  KC_U,     KC_Y,   DK_QUOT,
        _KC_A, _KC_R, _KC_S, _KC_T, KC_G,            KC_M, _KC_N, _KC_E,    _KC_I,  _KC_O,
        KC_Z_, KC_X,  KC_C,  KC_D,  KC_V,            KC_K, KC_H,  KC_COMMA, KC_DOT, DK_MINS_,

     LT(CTRL_NAV_LAYER, KC_TAB), KC_BSPC,            KC_SPACE, LT(SYMBOLS_LAYER, KC_ENTER)
    ),
    #ifdef KRACKO_OVERLOADED_PUNCTUATION
        // With overloaded punctuation, we can replace some duplicate symbols on the symbols layer
        [SYMBOLS_LAYER] = LAYOUT(
            KC_HAT,    XXXXXXX, KC_BTICK,  KC_TICK, KC_HASH,            XXXXXXX, KC_AE,   KC_OE,   KC_AA,   KC_UMLAUT,
            KC_LABRCK, DK_DQUO, DK_DOLLAR, DK_AMPR, DK_TILD,            XXXXXXX, DK_EXLM, DK_PERC, DK_QUES, XXXXXXX,
            KC_RABRCK, DK_EQL,  KC_RBRCK,  KC_BAR,  KC_SLASH_,          XXXXXXX, XXXXXXX, XXXXXXX, DK_PLUS, KC_AT_,

                                             _______, _______,          _______,       _______
        ),
    #else
        [SYMBOLS_LAYER] = LAYOUT(
            KC_HAT,    DK_DOLLAR, KC_BTICK, KC_TICK,  KC_HASH,            XXXXXXX, KC_AE,   KC_OE,   KC_AA,   KC_UMLAUT,
            KC_LABRCK, DK_LPRN,   KC_LBRCK, DK_LBRC,  DK_AMPR,            XXXXXXX, DK_EXLM, DK_DQUO, DK_PERC, DK_QUES,
            KC_RABRCK, DK_RPRN,   KC_RBRCK, DK_RBRC,  KC_BAR,             XXXXXXX, DK_TILD, DK_EQL,  DK_PLUS, KC_AT_,

                                             _______, _______,            _______,       _______
        ),
    #endif
    [CTRL_NAV_LAYER] = LAYOUT(
        _______,       _______,       _______,       _______,       _______,             _______, KC_ENTER, KC_ESCAPE, TG(CTRL_MEDIA_LAYER), _______,
        KC_LCMD,       KC_LALT,       KC_LCTL,       KC_LSFT,       KC_SPACE,            KC_LEFT, KC_DOWN,  KC_UP,     KC_RIGHT,             KC_APP_CYCLE,
        OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT), KC_BSPC,             KC_TAB,  KC_J,     KC_K,      CAPS_WORD,            _______,

                                                           _______,  _______,            _______, _______
    ),
    [NUMBER_LAYER] = LAYOUT(
        XXXXXXX, KC_SPACE, DK_PLUS, DK_MINS, XXXXXXX,            XXXXXXX, DK_ASTR, KC_SLASH_, DK_PERC, XXXXXXX,
        _KC_1,   _KC_2,    _KC_3,   _KC_4,   KC_5,               KC_6,    _KC_7,   _KC_8,     _KC_9,   _KC_0,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,            XXXXXXX, DK_EQL,  KC_COMMA,  KC_DOT,  XXXXXXX,

                                    XXXXXXX, XXXXXXX,            XXXXXXX, XXXXXXX
    ),
    [CTRL_MEDIA_LAYER] = LAYOUT(
        _______, _______,                   KC_DT_UP,   _______, QK_BOOTLOADER,            TG(CTRL_MEDIA_LAYER), TG(GAMING_LAYER), _______,           _______,             _______,
        _______, DF(BASE_QWERTY_LAYER),     KC_DT_DOWN, _______, _______,                  _______,              KC_BRIGHT_UP,     KC_AUDIO_VOL_UP,   KC_MEDIA_PLAY_PAUSE, _______,
        _______, DF(BASE_COLEMAK_DH_LAYER), KC_DT_PRNT, _______, _______,                  _______,              KC_BRIGHT_DOWN,   KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE,       _______,

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
  #ifdef KRACKO_HOME_ROW_MODS
    /* LCAPS_WORD = 0, */
    /* RCAPS_WORD, */
  #else
    LSFT = 0,
    RSFT,
    LCTL,
    RCTL,
    LSFT_LCMD,
    RSFT_RCMD,
    LGUI,
    RGUI,
  #endif
  COMBO_LENGTH,
};

const uint16_t COMBO_LEN = COMBO_LENGTH;

// For QWERTY
#define COMBO_KEYS(name, keycodes...) const uint16_t PROGMEM name##_combo[] = { keycodes, COMBO_END }
#define MAKE_COMBO(combo, name, keycode) [combo] = COMBO(name##_combo, keycode)

#ifdef KRACKO_HOME_ROW_MODS
    /* #ifdef KRACKO_USE_COLEMAK_DH_BASE_LAYER */
    /*     COMBO_KEYS(lcaps_word, KC_F, KC_P); */
    /*     COMBO_KEYS(rcaps_word, KC_L, KC_U); */
    /* #else */
    /*     COMBO_KEYS(lcaps_word, KC_E, KC_R); */
    /*     COMBO_KEYS(rcaps_word, KC_U, KC_I); */
    /* #endif */
#else
    COMBO_KEYS(left_shift,  KC_D, KC_F);
    COMBO_KEYS(right_shift, KC_J, KC_K);
    COMBO_KEYS(left_ctrl,   KC_S, KC_D);
    COMBO_KEYS(right_ctrl,  KC_K, KC_L);
    COMBO_KEYS(lsft_lcmd,   KC_C, KC_V);
    COMBO_KEYS(rsft_rcmd,   KC_M, KC_COMMA);
    COMBO_KEYS(lgui,        KC_E, KC_R);
    COMBO_KEYS(rgui,        KC_U, KC_I);
#endif

combo_t key_combos[] = {
    #ifdef KRACKO_HOME_ROW_MODS
        /* MAKE_COMBO(LCAPS_WORD, lcaps_word, CAPS_WORD), */
        /* MAKE_COMBO(RCAPS_WORD, rcaps_word, CAPS_WORD), */
    #else
        MAKE_COMBO(LSFT,      left_shift,  KC_LSFT),
        MAKE_COMBO(RSFT,      right_shift, KC_RSFT),
        MAKE_COMBO(LCTL,      left_ctrl,   KC_LCTL),
        MAKE_COMBO(RCTL,      right_ctrl,  KC_RCTL),
        MAKE_COMBO(LSFT_LCMD, lsft_lcmd,   LSFT(KC_LGUI)),
        MAKE_COMBO(RSFT_RCMD, rsft_rcmd,   RSFT(KC_RGUI)),
        MAKE_COMBO(LGUI,      lgui,        KC_LGUI),
        MAKE_COMBO(RGUI,      rgui,        KC_RGUI),
    #endif
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Allow all combos only on the following layers
    return layer_state_is(BASE_QWERTY_LAYER) || layer_state_is(BASE_COLEMAK_DH_LAYER) || layer_state_is(NUMBER_LAYER);
}

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

#ifdef KRACKO_OVERLOADED_PUNCTUATION
    #define KRACKO_OVERLOADED_PUNCTUATION_CASE(mod, target_keycode)\
        {\
            int mod_activated = (get_mods() & mod) == mod;\
            \
            if (mod_activated) {\
                if (record->event.pressed) {\
                    register_code16(target_keycode);\
                } else {\
                    unregister_code16(target_keycode);\
                }\
            }\
            \
            return !mod_activated;\
        }

    bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        bool lctl_mod_activated = (get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL);
        bool lalt_mod_activated = (get_mods() & MOD_BIT(KC_LALT)) == MOD_BIT(KC_LALT);

        switch (keycode) {
            case KC_COMMA: {
                if (lctl_mod_activated && lalt_mod_activated) {
                    if (record->event.pressed) {
                        const uint8_t _real_mods = get_mods();
                        clear_mods();
                        register_code16(KC_LBRCK);
                        set_mods(_real_mods);
                    } else {
                        unregister_code16(KC_LBRCK);
                    }
                } else if (lctl_mod_activated) {
                    if (record->event.pressed) {
                        const uint8_t _real_mods = get_mods();
                        clear_mods();
                        register_code16(DK_LPRN);
                        set_mods(_real_mods);
                    } else {
                        unregister_code16(DK_LPRN);
                    }
                } else if (lalt_mod_activated) {
                    if (record->event.pressed) {
                        const uint8_t _real_mods = get_mods();
                        clear_mods();
                        register_code16(DK_LBRC);
                        set_mods(_real_mods);
                    } else {
                        unregister_code16(DK_LBRC);
                    }
                }

                return !(lctl_mod_activated || lalt_mod_activated);
            }

            case KC_DOT: {
                if (lctl_mod_activated && lalt_mod_activated) {
                    if (record->event.pressed) {
                        const uint8_t _real_mods = get_mods();
                        clear_mods();
                        register_code16(KC_RBRCK);
                        set_mods(_real_mods);
                    } else {
                        unregister_code16(KC_RBRCK);
                    }
                } else if (lctl_mod_activated) {
                    if (record->event.pressed) {
                        const uint8_t _real_mods = get_mods();
                        clear_mods();
                        register_code16(DK_RPRN);
                        set_mods(_real_mods);
                    } else {
                        unregister_code16(DK_RPRN);
                    }
                } else if (lalt_mod_activated) {
                    if (record->event.pressed) {
                        const uint8_t _real_mods = get_mods();
                        clear_mods();
                        register_code16(DK_RBRC);
                        set_mods(_real_mods);
                    } else {
                        unregister_code16(DK_LBRC);
                    }
                }

                return !(lctl_mod_activated || lalt_mod_activated);
            }

            case DK_MINS: {
                if (lctl_mod_activated) {
                    if (record->event.pressed) {
                        const uint8_t _real_mods = get_mods();
                        clear_mods();
                        register_code16(KC_SLASH_);
                        set_mods(_real_mods);
                    } else {
                        unregister_code16(KC_SLASH_);
                    }
                }

                return !lctl_mod_activated;
            }
        }

        return true;
    }
#endif
