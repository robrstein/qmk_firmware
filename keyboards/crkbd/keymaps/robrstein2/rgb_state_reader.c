#ifdef RGBLIGHT_ENABLE

#include QMK_KEYBOARD_H
#include <stdio.h>

extern rgblight_config_t rgblight_config;
char rbf_info_str[24];
char rbf_info_str2[6];

const char *read_rgb_info2(void) {

  snprintf(rbf_info_str, sizeof(rbf_info_str), "%s %2d h%3d s%3d v%3d",
    rgblight_config.enable ? "on" : "- ", rgblight_config.mode,
    rgblight_config.hue, rgblight_config.sat, rgblight_config.val);

  return rbf_info_str;
}

const char *read_rgb_on_off(void) {

  snprintf(rbf_info_str2, sizeof(rbf_info_str2), "%s,%2d",
    rgblight_config.enable ? "on" : "--", rgblight_config.mode);

  return rbf_info_str2;
}

#endif

#ifdef RGB_MATRIX_ENABLE
#include QMK_KEYBOARD_H
#include <stdio.h>

char mtx_info_str[24];
char mtx_info_str2[6];

const char *read_mtx_info(void) {

  snprintf(mtx_info_str, sizeof(mtx_info_str), "%s %2d h%3d s%3d v%3d",
    rgb_matrix_is_enabled() ? "on" : "- ", rgb_matrix_get_mode(),
    rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());

  return mtx_info_str;
}

const char *read_mtx_on_off(void) {
  
  snprintf(mtx_info_str2, sizeof(mtx_info_str2), "%s,%2d ",
    rgb_matrix_is_enabled() ? "on" : "--", rgb_matrix_get_mode());

  return mtx_info_str2;
}
#endif

