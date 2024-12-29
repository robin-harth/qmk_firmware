/* RGB_MATRIX_EFFECT(my_cool_effect)
RGB_MATRIX_EFFECT(coordinate_test)
RGB_MATRIX_EFFECT(runner) */
//RGB_MATRIX_EFFECT(bi_wave)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

/* static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
  }
  return rgb_matrix_check_finished_leds(led_max);
}


static bool coordinate_test(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        int16_t dx  = g_led_config.point[i].x;
        RGB rgb;
        rgb.g = 0x00;
        if (dx < 80) {
            rgb.r = 0xff;
            rgb.b = 0x00;
        } else {
            rgb.r = 0x00;
            rgb.b = 0xff;
        }
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static HSV runner_math(HSV hsv, uint8_t i, uint8_t time) {
    uint8_t color8 = 169-(time%225);
    uint16_t color = color8 + g_led_config.point[i].x;
    while (color < 169 || color > 255) {
        if (color < 169) {
            color = 169 + (169 - color);
        } else {
            color = 255 - (color - 255);
        }
    }
    hsv.h = color;
    return hsv;
}

bool runner(effect_params_t* params) {
  return effect_runner_i(params, &runner_math);
} */


/* static HSV bi_wave_math(HSV hsv, uint8_t i, uint8_t time) {
    float ampl = 43;
    float period = 255/(2*3.14);
    float elevation = 212;
    float sinus = ampl*sin(((float)g_led_config.point[i].x-time)/period)+elevation;
    hsv.h = sinus;
    return hsv;
}

bool bi_wave(effect_params_t* params) {
  return effect_runner_i(params, &bi_wave_math);
} */
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
