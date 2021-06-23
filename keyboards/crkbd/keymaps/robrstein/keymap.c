#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;

#endif

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer = 0;
#endif

#ifdef RGB_MATRIX_ENABLE
static uint32_t led_timer = 0;
#endif
extern uint8_t is_master;

int cuenta = 0;
int frgb_aut = 0;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

// Custom keycodes for layer keys
// Dual function escape with left command


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  RGBRST,
  MACRO1,
  MACRO2,
  MACRO3,
  RGBAUT
};

enum {
   //  TD_PC,
    // TD_COMI,
   //  TD_SLA,
    TD_CAPLOCK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 /* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  BSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ñ  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |  ,;  |  .:  |  -_  |RShift|
 * `-----------------------------------------/       /     \      \---------------------e--------------------'
 *                          | GUI | LOWER | /Space  /       \Enter \  RAISE | RALT |
 *                          `----------------------'          '------''------------'
 */

  [_QWERTY] = LAYOUT(
  //|----------------------------------------------------------|                     |-----------------------------------------------------------------|
     KC_TAB        , KC_Q   , KC_W   , KC_E   , KC_R  ,    KC_T,                          KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,    KC_BSPC,
  //|--------------+--------+--------+--------+-------+--------|                     |--------+--------+--------+--------+-----------+-----------------|
     TD(TD_CAPLOCK), KC_A   , KC_S   , KC_D   , KC_F  ,    KC_G,                          KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_LBRC,
  //---------------+--------+--------+--------+-------+--------|                     |--------+--------+--------+--------+-----------+-----------------|
     KC_LCTL       , KC_Z   , KC_X   , KC_C   , KC_V  ,    KC_B,                          KC_N,    KC_M, KC_COMM, KC_DOT ,    KC_SLSH, RSFT_T(KC_ENT),
  //---------------+--------+--------+--------+-------+--------|                     |--------+--------+--------+--------+-----------+-----------------|
                                                KC_LGUI, LOWER ,  KC_SPC,     KC_ENT , RAISE  , KC_RALT
                                    //|----------------------------------|   |--------------------------|


  ),
 /* _LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  1   |  2   |   3  |  4   |   5  |                    |  6   | 7    | 8    |  9   |  0   |  BSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift| HOME | UP   | END  | INS  | PGUP |                    |  F1  |  F2  | F3   | F4   | F5   |  F6  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL | LEFT | DOWN | RIGHT| SUP  | PGDN |                    |  F7  | F8   | F9   | F10  | F11  | F12  |
 * `-----------------------------------------/-------|     |------\-----------------------------------------'
 *                          | LALT |      | /  ENT  /       \Enter \  RAISE | RALT |
 *                          `----------------------'          '------''------------'
 */
  [_LOWER] = LAYOUT(
  //|-----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, KC_HOME,   KC_UP,  KC_END,  KC_INS, KC_PGUP,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_PGDN,                        KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LALT, KC_TRNS, KC_ENT,    KC_ENT, RAISE, KC_RALT
                                      //|--------------------------|  |--------------------------|
  ),

   /* _RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |  !   | "    | #    |  $   |  %   |                    |  &   |  /   |  (   |  )   |  =   |  BSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift| HOME | UP   | END  | INS  | PGUP |                    |  ¿¡  |  '?  | ´¨   |  +*  |  {[  |  }]  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL | LEFT | DOWN | RIGHT| SUP  | PGDN |                    |  ?   |  ¡   |  }   |  *   |   |  |  <>  |
 * `-----------------------------------------/       /     \      \---------------------e--------------------'
 *                          | GUI | LOWER | /Space  /       \Enter \        | RALT |
 *                          `----------------------'          '------''------------'
 */

  [_RAISE] = LAYOUT(
  //|----------------------------------------------------|                    |-----------------------------------------------------|
     KC_ESC,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    KC_LSFT,  KC_HOME,   KC_UP,  KC_END,  KC_INS, KC_PGUP,                       KC_EQL, KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT, KC_BSLS,
  //|------+---------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL, KC_PGDN,                      KC_UNDS, KC_PLUS, KC_NUHS, KC_RCBR, KC_GRV, KC_NUBS,
  //|-------+--------+--------+--------+--------+--------+--------|  |-------+---------+--------+--------+--------+--------+--------|
                                         KC_LGUI,   LOWER,  KC_SPC,    KC_ENT, KC_TRNS, KC_RALT
                                      //|-------------------------|  |--------------------------|
  ),
   /* _ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | RESET| RGB  | RGB  | RGB  | RGB  |RGBTOG|                    | PSCR | STOP | PREV |VOLUP | RWD  |XXXXXX|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RGB  | RGB H| RGB S| RGB V| RGBSP|RGBMOD|                    |MACRO2| PLAY | NEXT |VOLDOW| FFD  |XXXXXX|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RGB  | RGB H| RGB S| RGB V| RGBSP|RGBMOD|-------|    |-------|MACRO1| MIPC | CALC | MUTE | MSEL |MACRO3|
 * `-----------------------------------------/       /     \      \---------------------e--------------------'
 *                          | GUI | LOWER | /Space  /       \Enter \  RAISE | RALT |
 *                          `----------------------'          '------''------------'
 */
  [_ADJUST] = LAYOUT(
  //|----------------------------------------------------|                    |---------------------------------------------------------------|
       RESET,RGB_M_P, RGB_M_B, RGB_M_SW,  RGBRST, RGB_TOG,                          KC_PSCR,    KC_MSTP,  KC_MPRV, KC_VOLU,KC_MRWD,XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|                    |------------+------------+---------+--------+-------+--------|
    RGB_M_R, RGB_HUI, RGB_SAI, RGB_VAI, RGB_SPI, RGB_MOD,                           MACRO2,    KC_MPLY,  KC_MNXT, KC_VOLD,KC_MFFD,  XXXXXXX,
  //|-------+--------+--------+--------+--------+--------|                    |------------+------------+---------+--------+-------+--------|
     RGBAUT, RGB_HUD, RGB_SAD, RGB_VAD, RGB_SPD,RGB_RMOD,                           MACRO1,    KC_MYCM,  KC_CALC, KC_MUTE,KC_MSEL,MACRO3,
  //|-------+--------+--------+--------+--------+--------+--------|   |--------+-----------+-----------+---------+--------+-------+--------|
                                         KC_LCTL, KC_TRNS, KC_SPC,       KC_SPC,    KC_TRNS, KC_RALT 
                                      //|--------------------------|  |------------------------------|
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

int RGB_current_mode;

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
    if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
        layer_on(layer3);
    } else {
        layer_off(layer3);
    }
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
        RGB_current_mode = rgblight_config.mode;
    #endif
}

void rgb_matrix_indicators_user(void) {
    #ifdef RGB_MATRIX_ENABLE
   
        switch (biton32(layer_state)) {
            case _RAISE:
                //rgb_matrix_set_color_all(255, 0, 0);
                for (int i = 0; i < 6; i++) {
                    rgb_matrix_set_color(i, 255, 0, 0 ); // rojo
                }
                break;

            case _LOWER:
                for (int i = 0; i < 6; i++) {
                    rgb_matrix_set_color(i, 0, 0, 255); //azul
                }
                //rgb_matrix_set_color_all(244, 208, 63);
                break;

            default:
                //rgb_matrix_set_color_all(255, 0, 0);
                if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
                    rgb_matrix_set_color_all(0, 255, 0);
                }
                break;
        }

        if (led_timer == 0) led_timer = timer_read32();
        if (timer_elapsed32(led_timer) >= 60000 && (frgb_aut == 1)) {
            rgb_matrix_step_noeeprom();
           led_timer = timer_read32(); 
        }

    #endif
}

#ifdef OLED_DRIVER_ENABLE
    oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

    void render_space(void) {
        oled_write_P(PSTR("     "), false);
    }

    void render_mod_status_gui_alt(uint8_t modifiers) {
        static const char PROGMEM gui_off_1[] = {0x85, 0x86, 0};
        static const char PROGMEM gui_off_2[] = {0xa5, 0xa6, 0};
        static const char PROGMEM gui_on_1[] = {0x8d, 0x8e, 0};
        static const char PROGMEM gui_on_2[] = {0xad, 0xae, 0};

        static const char PROGMEM alt_off_1[] = {0x87, 0x88, 0};
        static const char PROGMEM alt_off_2[] = {0xa7, 0xa8, 0};
        static const char PROGMEM alt_on_1[] = {0x8f, 0x90, 0};
        static const char PROGMEM alt_on_2[] = {0xaf, 0xb0, 0};

        // fillers between the modifier icons bleed into the icon frames
        static const char PROGMEM off_off_1[] = {0xc5, 0};
        static const char PROGMEM off_off_2[] = {0xc6, 0};
        static const char PROGMEM on_off_1[] = {0xc7, 0};
        static const char PROGMEM on_off_2[] = {0xc8, 0};
        static const char PROGMEM off_on_1[] = {0xc9, 0};
        static const char PROGMEM off_on_2[] = {0xca, 0};
        static const char PROGMEM on_on_1[] = {0xcb, 0};
        static const char PROGMEM on_on_2[] = {0xcc, 0};

        if(modifiers & MOD_MASK_GUI) {
            oled_write_P(gui_on_1, false);
        } else {
            oled_write_P(gui_off_1, false);
        }

        if ((modifiers & MOD_MASK_GUI) && (modifiers & MOD_MASK_ALT)) {
            oled_write_P(on_on_1, false);
        } else if(modifiers & MOD_MASK_GUI) {
            oled_write_P(on_off_1, false);
        } else if(modifiers & MOD_MASK_ALT) {
            oled_write_P(off_on_1, false);
        } else {
            oled_write_P(off_off_1, false);
        }

        if(modifiers & MOD_MASK_ALT) {
            oled_write_P(alt_on_1, false);
        } else {
            oled_write_P(alt_off_1, false);
        }

        if(modifiers & MOD_MASK_GUI) {
            oled_write_P(gui_on_2, false);
        } else {
            oled_write_P(gui_off_2, false);
        }

        if (modifiers & MOD_MASK_GUI & MOD_MASK_ALT) {
            oled_write_P(on_on_2, false);
        } else if(modifiers & MOD_MASK_GUI) {
            oled_write_P(on_off_2, false);
        } else if(modifiers & MOD_MASK_ALT) {
            oled_write_P(off_on_2, false);
        } else {
            oled_write_P(off_off_2, false);
        }

        if(modifiers & MOD_MASK_ALT) {
            oled_write_P(alt_on_2, false);
        } else {
            oled_write_P(alt_off_2, false);
        }
    }


    void render_mod_status_ctrl_shift(uint8_t modifiers) {
        static const char PROGMEM ctrl_off_1[] = {0x89, 0x8a, 0};
        static const char PROGMEM ctrl_off_2[] = {0xa9, 0xaa, 0};
        static const char PROGMEM ctrl_on_1[] = {0x91, 0x92, 0};
        static const char PROGMEM ctrl_on_2[] = {0xb1, 0xb2, 0};

        static const char PROGMEM shift_off_1[] = {0x8b, 0x8c, 0};
        static const char PROGMEM shift_off_2[] = {0xab, 0xac, 0};
        static const char PROGMEM shift_on_1[] = {0xcd, 0xce, 0};
        static const char PROGMEM shift_on_2[] = {0xcf, 0xd0, 0};

        // fillers between the modifier icons bleed into the icon frames
        static const char PROGMEM off_off_1[] = {0xc5, 0};
        static const char PROGMEM off_off_2[] = {0xc6, 0};
        static const char PROGMEM on_off_1[] = {0xc7, 0};
        static const char PROGMEM on_off_2[] = {0xc8, 0};
        static const char PROGMEM off_on_1[] = {0xc9, 0};
        static const char PROGMEM off_on_2[] = {0xca, 0};
        static const char PROGMEM on_on_1[] = {0xcb, 0};
        static const char PROGMEM on_on_2[] = {0xcc, 0};

        if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(ctrl_on_1, false);
        } else {
            oled_write_P(ctrl_off_1, false);
        }

        if ((modifiers & MOD_MASK_CTRL) && (modifiers & MOD_MASK_SHIFT)) {
            oled_write_P(on_on_1, false);
        } else if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(on_off_1, false);
        } else if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(off_on_1, false);
        } else {
            oled_write_P(off_off_1, false);
        }

        if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(shift_on_1, false);
        } else {
            oled_write_P(shift_off_1, false);
        }

        if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(ctrl_on_2, false);
        } else {
            oled_write_P(ctrl_off_2, false);
        }

        if (modifiers & MOD_MASK_CTRL & MOD_MASK_SHIFT) {
            oled_write_P(on_on_2, false);
        } else if(modifiers & MOD_MASK_CTRL) {
            oled_write_P(on_off_2, false);
        } else if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(off_on_2, false);
        } else {
            oled_write_P(off_off_2, false);
        }

        if(modifiers & MOD_MASK_SHIFT) {
            oled_write_P(shift_on_2, false);
        } else {
            oled_write_P(shift_off_2, false);
        }
    }

    void render_logo(void) {
        static const char PROGMEM corne_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
        oled_write_P(corne_logo, false);
        oled_write_P(PSTR("corne"), false);
    }

    void render_logo_i(void) {
        static const char PROGMEM corne_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
        oled_write_P(corne_logo, false);
        oled_write_P(PSTR("Mati "), false);
    }

        void render_logo_d(void) {
        static const char PROGMEM corne_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
        oled_write_P(corne_logo, false);
        oled_write_P(PSTR("Urra "), false);
    }

    void render_logo_ri(void) {
        static const char PROGMEM corne_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
        oled_write_P(corne_logo, false);
        //oled_write_P(PSTR("Mati "), false);
          oled_write_P(PSTR("Rober"), false);
    }

        void render_logo_rw(void) {
        static const char PROGMEM corne_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84,
            0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
            0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0};
        oled_write_P(corne_logo, false);
         //oled_write_P(PSTR("Mati "), false);
           oled_write_P(PSTR("ReeW "), false);
    }

    void render_layer_state(void) {
        static const char PROGMEM default_layer[] = {
            0x20, 0x94, 0x95, 0x96, 0x20,
            0x20, 0xb4, 0xb5, 0xb6, 0x20,
            0x20, 0xd4, 0xd5, 0xd6, 0x20, 0};
        static const char PROGMEM raise_layer[] = {
            0x20, 0x97, 0x98, 0x99, 0x20,
            0x20, 0xb7, 0xb8, 0xb9, 0x20,
            0x20, 0xd7, 0xd8, 0xd9, 0x20, 0};
        static const char PROGMEM lower_layer[] = {
            0x20, 0x9a, 0x9b, 0x9c, 0x20,
            0x20, 0xba, 0xbb, 0xbc, 0x20,
            0x20, 0xda, 0xdb, 0xdc, 0x20, 0};
        static const char PROGMEM adjust_layer[] = {
            0x20, 0x9d, 0x9e, 0x9f, 0x20,
            0x20, 0xbd, 0xbe, 0xbf, 0x20,
            0x20, 0xdd, 0xde, 0xdf, 0x20, 0};
        if(layer_state_is(_ADJUST)) {
            oled_write_P(adjust_layer, false);
        } else if(layer_state_is(_LOWER)) {
            oled_write_P(lower_layer, false);
        } else if(layer_state_is(_RAISE)) {
            oled_write_P(raise_layer, false);
        } else {
            oled_write_P(default_layer, false);
        }
    }

    void render_status_main(void) {
        //render_logo_i();
        render_logo_rw();
        render_space();
        render_layer_state();
        render_space();
        render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
        render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
    }

    void render_status_secondary(void) {
         //render_logo_d();
         render_logo_rw();
         render_space();
         render_layer_state();
         render_space();
         render_mod_status_gui_alt(get_mods()|get_oneshot_mods());
         render_mod_status_ctrl_shift(get_mods()|get_oneshot_mods());
         // oled_write_P(PSTR("rober"), false);
    }

    void oled_task_user(void) {
        if (timer_elapsed32(oled_timer) > 1800000) {
            oled_off();
            return;
        }
        #ifndef SPLIT_KEYBOARD
            else { oled_on(); }
        #endif

        if (is_master) {
            render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        } else {
            render_status_secondary();
        }
    }

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        #ifdef OLED_DRIVER_ENABLE
            oled_timer = timer_read32();
        #endif
    // set_timelog();
    }

    switch (keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
            } 
            return false;
        case ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case MACRO1:
            if (record->event.pressed) {
                    SEND_STRING("853211utc");           
                }
                return false;
        case MACRO2:
            if (record->event.pressed) {
                    SEND_STRING("select } from ");                
                }
                return false;
        case MACRO3:
            if (record->event.pressed) {
                    SEND_STRING("13700724K");
                }
            return false;
        case RGBAUT:
             #ifdef RGB_MATRIX_ENABLE
             if (record->event.pressed) {
                led_timer = timer_read32();
                if (frgb_aut == 0 ) {
                    rgb_matrix_enable_noeeprom();
                    rgb_matrix_step_noeeprom();
                    frgb_aut = 1;
                 } else {
                    //{rgb_matrix_disable_noeeprom();
                    frgb_aut = 0; 
                 }
             }
            #endif
            return false;
        case RGBRST:
            #ifdef RGBLIGHT_ENABLE
                if (record->event.pressed) {
                    eeconfig_update_rgblight_default();
                    rgblight_enable();
                    RGB_current_mode = rgblight_config.mode;
                }
            #endif
            #ifdef RGB_MATRIX_ENABLE
                if (record->event.pressed) {
                    eeconfig_update_rgb_matrix_default();
                    rgb_matrix_enable();
                }
            #endif
            break;
    }
    return true;
}

#ifdef RGB_MATRIX_ENABLE

    void suspend_power_down_user(void) {
        rgb_matrix_set_suspend_state(true);
    }

    void suspend_wakeup_init_user(void) {
        rgb_matrix_set_suspend_state(false);
    }

#endif
