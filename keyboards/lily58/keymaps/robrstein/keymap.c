#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};
 
 enum custom_keycodes {
  MACRO1,
  MACRO2,
  MACRO3,
  TD_CAPLOCK
};

#define RE_MAY TD(TD_CAPLOCK)
#define RE_CPY RCTL(KC_C)
#define RE_PST RCTL(KC_V)
#define RE_CEN RCTL(KC_ENT)
#define RE_TES RGB_MODE_RGBTEST

#define RE_NUBS LSFT(KC_NUBS)
#define RE_QUOT LSFT(KC_QUOT)
#define RE_BSLS LSFT(KC_BSLS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1!  |  2"  |  3#  |  4$  |  5 % |                    |  6&  |  7/  |  8(  |  9)  |  0=  |  BSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ñ  |  '   |
 * |------+------+------+------+------+------|  DEL  |    |CTR+ENT|------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,;  |  .:  |  -_  |RShift|
 * `-----------------------------------------/       /     \      \---------------------e--------------------'
 *                   | copy | paste |LOWER | /Space  /       \Enter \  RAISE | RGUI | RALT |
  *                   `----------------------------'          '------''--------------------'
 */

 [_QWERTY] = LAYOUT( 
  KC_ESC  ,  KC_1,   KC_2,    KC_3,    KC_4,  KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
  KC_TAB  ,  KC_Q,   KC_W,    KC_E,    KC_R,  KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
  RE_MAY  ,  KC_A,   KC_S,    KC_D,    KC_F,  KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_MINS, 
  KC_LCTRL,  KC_Z,   KC_X,    KC_C,    KC_V,  KC_B,  KC_DEL ,           RE_CEN, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, 
                              RE_CPY , RE_PST, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_RGUI, KC_RALT
),
/* LOWER     
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  |°  | HOME |  UP  |  END |  INS | PGUP |                    |   /  |  *   |   7  |  8   |   9  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift| LEFT | DOWN | RIGHT|  DEL | PGDW |-------.    ,-------|   .  |  ,   |   4  |  5   |   6  |  -   |
 * |------+------+------+------+------+------| BSP   |    |       |------+------+------+------+------+------|
 * |   <  |  >   |  {   |  }   |  [   |  ]   |-------|    |-------|      |   0  |   1  |  2   |   3  | ENT  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | LGUI |LOWER | /Enter  /       \ Enter \    |RAISE | RGUI | RAlt |
 *                   `----------------------------'           '------''-----------------------'
 */
[_LOWER] = LAYOUT( 
   KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6,                                 KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,
  KC_GRV, KC_HOME,KC_UP,  KC_END, KC_INS,  KC_PGUP,                             KC_PSLS, KC_PAST, KC_P7, KC_P8,  KC_P9,  KC_PPLS,
  _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_DEL,  KC_PGDN,                             KC_PDOT, KC_COMM, KC_P4, KC_P5,  KC_P6,  KC_PMNS, 
  KC_NUBS,RE_NUBS,KC_QUOT,KC_BSLS,RE_QUOT, RE_BSLS, KC_BSPC,     _______, _______, KC_P0,   KC_P1, KC_P2,  KC_P3,  KC_ENT, 
                     KC_LALT,KC_LGUI   , _______,     KC_ENT , _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  |°  | HOME |  UP  |  END |  INS | PGUP |                    | PSCR |      |      |      |      |MACRO3|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift| LEFT | DOWN | RIGHT|  DEL | PGDW |-------.    ,-------| ¿¡   |  '?  |  ´¨  |  +*  |      |MACRO2|
 * |------+------+------+------+------+------| BSP   |    |       |------+------+------+------+------+------|
 * |   <  |  >   |  {   |  }   |  [   |  ]   |-------|    |-------| ?    |  ¡   |  }   |   *  |      |MACRO1|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |LAlt  | LGUI |LOWER | /Enter  /       \ Enter \    |RAISE | RGUI | RAlt |
 *                   `----------------------------'           '------''-----------------------'
 */

[_RAISE] = LAYOUT( 
  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,   KC_F6,                           KC_F7,    KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  KC_GRV, KC_HOME,KC_UP,  KC_END, KC_INS,  KC_PGUP,                       KC_PSCR, _______, _______, _______, _______,  MACRO3,
  _______,KC_LEFT,KC_DOWN,KC_RGHT,KC_DEL,  KC_PGDN,                       KC_EQL , KC_MINS, KC_LBRC, KC_RBRC, _______,  MACRO2, 
  KC_NUBS,RE_NUBS,KC_QUOT,KC_BSLS,RE_QUOT, RE_BSLS, KC_BSPC,     _______, KC_UNDS, KC_PLUS, KC_NUHS, KC_RCBR, _______,  MACRO1, 
                                KC_LALT,KC_LGUI      , _______,       KC_ENT ,     _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RESET|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |MACRO3|RGB ON|RGBRST|      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|MACRO2|MODE+ |SPEED+| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|MACRO1|MODE- |SPEED-| HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   `----------------------------'           '------''--------------------'
 */ 

  [_ADJUST] = LAYOUT( 
  RESET  , XXXXXXX, XXXXXXX, XXXXXXX, RGB_M_X, RGB_M_G,                   RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K, 
  XXXXXXX, BL_TOGG, BL_STEP, BL_BRTG, BL_ON, BL_INC,                   MACRO3, RGB_TOG,  XXXXXXX, RE_TES,RGB_M_T, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BL_OFF, BL_DEC,                   MACRO2, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MACRO1,RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,
                             _______, _______, _______, _______, _______,  _______, _______, _______ 
  )
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for ;, twice for :
   //  [TD_PC] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, LSFT(KC_SCLN)),
    // [TD_COMI] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, LSFT(KC_QUOT)),
    // [TD_SLA] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, LSFT(KC_SLSH)),
    [TD_CAPLOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }

  switch (keycode) {
        case MACRO1:
            if (record->event.pressed) {
                    SEND_STRING("853211ip");
            }
            return false;
        case MACRO2:
            if (record->event.pressed) {
                    SEND_STRING("select } from dual "); 
                }
                return false;
        case MACRO3:
            if (record->event.pressed) {
                    SEND_STRING("13700724K");
                }
            return false;

        break;
    }


  return true;
}
