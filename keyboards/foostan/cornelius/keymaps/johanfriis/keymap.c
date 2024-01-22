#include QMK_KEYBOARD_H

#include "johanfriis.c"

enum {
    TD_FIX_BSE,
    TD_FIX_NAV,
    TD_FIX_NUM,
};

void td_fix_nav(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << _NAV); \
  } \
}

void td_fix_bse(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << _BSE); \
  } \
}

void td_fix_num(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << _NUM); \
  } \
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_FIX_BSE] = ACTION_TAP_DANCE_FN(td_fix_bse),
    [TD_FIX_NAV] = ACTION_TAP_DANCE_FN(td_fix_nav),
    [TD_FIX_NUM] = ACTION_TAP_DANCE_FN(td_fix_num),
};

#define FIX_BSE TD(TD_FIX_BSE)
#define FIX_NAV TD(TD_FIX_NAV)
#define FIX_NUM TD(TD_FIX_NUM)

#define L_BKSPC LT(_NUM, KC_BSPC)
#define L_SPACE LT(_NAV, KC_SPC)

    /* [_NUM] = LAYOUT( */
    /*     XXXXXXX, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, XXXXXXX, */
    /*     XXXXXXX, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, XXXXXXX, */
    /*     XXXXXXX, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, XXXXXXX, */
    /*     _______, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, _______ */
    /* ), */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BSE] = LAYOUT(
        XXXXXXX, ___Q___, ___W___, ___F___, ___P___, ___B___,      ___J___, ___L___, ___U___, ___Y___, _QUOTE_, XXXXXXX,
        XXXXXXX, ___A___, ___R___, ___S___, ___T___, ___G___,      ___M___, ___N___, ___E___, ___I___, ___O___, XXXXXXX,
        XXXXXXX, ___Z___, ___X___, ___C___, ___D___, ___V___,      ___K___, ___H___, _COMMA_, __DOT__, _SLASH_, XXXXXXX,
        _______, _______, _______, __ESC__, L_SPACE, __TAB__,      _ENTER_, L_BKSPC, __DEL__, _______, _______, MO(_OPS)
    ),

    [_NAV] = LAYOUT(
        XXXXXXX, _______, _______, FIX_BSE, FIX_NAV, _______,      _REDO__, _PASTE_, _COPY__, __CUT__, _UNDO__, XXXXXXX,
        XXXXXXX, _L_GUI_, _L_OPT_, _L_CTL_, _L_SFT_, _______,      _______, _C_LFT_, _C_DWN_, _C_UP__, _C_RGT_, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______,      __INS__, _HOME__, _PGDN__, _PGUP__, __END__, XXXXXXX,
        _______, _______, _______, _______, _HODOR_, _______,      _______, _______, _______, _______, _______, _______
    ),

    [_NUM] = LAYOUT(
        XXXXXXX, _LBRAC_, ___7___, ___8___, ___9___, _RBRAC_,      _______, FIX_NUM, FIX_BSE, _______, _______, XXXXXXX,
        XXXXXXX, _SEMIC_, ___4___, ___5___, ___6___, _EQUAL_,      _______, _L_SFT_, _L_CTL_, _L_OPT_, _L_GUI_, XXXXXXX,
        XXXXXXX, _GRAVE_, ___1___, ___2___, ___3___, _BSLSH_,      _______, _______, _______, _______, _______, XXXXXXX,
        _______, _______, _______, __DOT__, ___0___, _MINUS_,      _______, _______, _______, _______, _______, _______
    ),

    [_OPS] = LAYOUT(
        XXXXXXX, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, _______, _______,      _______, _______, _______, _______, _______, XXXXXXX,
        _______, _______, QK_BOOT, _______, _______, _______,      _______, _______, _______, _______, _______, _______
    ),
};

/*
 * #define MIRYOKU_ALTERNATIVES_NUM \
 * KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
 * KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,            U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
 * KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,           U_NA,              TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    KC_ALGR,           U_NA,              \
 * U_NP,              U_NP,              KC_DOT,            KC_0,              KC_MINS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP
 */

/* 
 * #define MIRYOKU_ALTERNATIVES_NAV \
 * TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
 * KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              CW_TOGG,           KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           \
 * U_NA,              KC_ALGR,           TD(U_TD_U_NUM),    TD(U_TD_U_NAV),    U_NA,              KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            \
 * U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_ENT,            KC_BSPC,           KC_DEL,            U_NP,              U_NP
 */ 

/* 
 * #define MIRYOKU_ALTERNATIVES_TAP_COLEMAKDHK \
 * KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,              KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,           \
 * LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),      \
 * LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH),\
 * U_NP,              U_NP,              LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), LT(U_FUN,KC_DEL),  U_NP,              U_NP
 */

/* 
 * #define MIRYOKU_ALTERNATIVES_MOUSE \
 * TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
 * KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           \
 * U_NA,              KC_ALGR,           TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  U_NA,              U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           \
 * U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
 */

/* 
 * #define MIRYOKU_ALTERNATIVES_MEDIA \
 * TD(U_TD_BOOT),     TD(U_TD_U_TAP),    TD(U_TD_U_EXTRA),  TD(U_TD_U_BASE),   U_NA,              RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           \
 * KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,              U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           \
 * U_NA,              KC_ALGR,           TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  U_NA,              OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,              \
 * U_NP,              U_NP,              U_NA,              U_NA,              U_NA,              KC_MSTP,           KC_MPLY,           KC_MUTE,           U_NP,              U_NP
 */

/* 
 * #define MIRYOKU_ALTERNATIVES_SYM \
 * KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
 * KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
 * KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,           U_NA,              TD(U_TD_U_SYM),    TD(U_TD_U_MOUSE),  KC_ALGR,           U_NA,              \
 * U_NP,              U_NP,              KC_LPRN,           KC_RPRN,           KC_UNDS,           U_NA,              U_NA,              U_NA,              U_NP,              U_NP
 */

/* 
 * #define MIRYOKU_ALTERNATIVES_FUN \
 * KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,           U_NA,              TD(U_TD_U_BASE),   TD(U_TD_U_EXTRA),  TD(U_TD_U_TAP),    TD(U_TD_BOOT),     \
 * KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,           U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
 * KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,           U_NA,              TD(U_TD_U_FUN),    TD(U_TD_U_MEDIA),  KC_ALGR,           U_NA,              \
 * U_NP,              U_NP,              KC_APP,            KC_SPC,            KC_TAB,            U_NA,              U_NA,              U_NA,              U_NP,              U_NP
 */

/* 
 * #define MIRYOKU_ALTERNATIVES_BUTTON \
 * U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
 * KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,              U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           \
 * U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,             U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             \
 * U_NP,              U_NP,              KC_BTN3,           KC_BTN1,           KC_BTN2,           KC_BTN2,           KC_BTN1,           KC_BTN3,           U_NP,              U_NP
 */
