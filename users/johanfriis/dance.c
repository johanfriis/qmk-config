#include "johanfriis.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

enum {
    TD_FIX_NAV,
};

void td_fix_nav(tap_dance_state_t *state, void *user_data) { \
  if (state->count == 2) { \
    default_layer_set((layer_state_t)1 << _NAV); \
  } \
}





tap_dance_action_t tap_dance_actions[] = {
    /* [TD_FIX_NAV] = ACTION_TAP_DANCE_DOUBLE(KC_NO, KC_LGUI), */
    [TD_FIX_NAV] = ACTION_TAP_DANCE_FN(td_fix_nav),
};
