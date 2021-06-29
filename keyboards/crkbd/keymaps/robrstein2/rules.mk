RGBLIGHT_ENABLE    = no
RGB_MATRIX_ENABLE  = WS2812 #WS2812 o no
MOUSEKEY_ENABLE    = no
NKRO_ENABLE        = no
OLED_DRIVER_ENABLE = yes #yes o no
EXTRAKEY_ENABLE = yes 
TAP_DANCE_ENABLE = yes

LTO_ENABLE = yes

SRC +=  ./keymaps/robrstein2/keylogger.c \
		./keymaps/robrstein2/rgb_state_reader.c \