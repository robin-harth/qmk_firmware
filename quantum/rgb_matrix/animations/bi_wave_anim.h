//#ifdef ENABLE_RGB_MATRIX_BI_WAVE
RGB_MATRIX_EFFECT(BI_WAVE)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV BI_WAVE_math(HSV hsv, uint8_t i, uint8_t time) {
    float ampl = 43;
    float period = 255/(2*3.14);
    float elevation = 212;
    float sinus = ampl*sin(((float)g_led_config.point[i].x-time)/period)+elevation;
    hsv.h = sinus;
    return hsv;
}

bool BI_WAVE(effect_params_t* params) {
  return effect_runner_i(params, &BI_WAVE_math);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
//#endif     // ENABLE_RGB_MATRIX_BI_WAVE
