// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(zpm_static)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// e.g: A simple effect, self-contained within a single method
/*
static bool zpm_static(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0xff, 0xff, 0x00);
  }
  return rgb_matrix_check_finished_leds(led_max);
}

// e.g: A more complex effect, relying on external methods and state, with
// dedicated init and run methods
static bool is_done;
static void zpm_static_init(effect_params_t* params) {
  some_global_state = 1;
}
static bool my_cool_effect2_complex_run(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (uint8_t i = led_min; i < led_max; i++) {
    rgb_matrix_set_color(i, 0xff, some_global_state++, 0xff);
  }
  return rgb_matrix_check_finished_leds(led_max);
}
static bool my_cool_effect2(effect_params_t* params) {
  if (params->init) my_cool_effect2_complex_init(params);
  return my_cool_effect2_complex_run(params);
}

*/

#define LEN_YELLOW 4
#define LEN_BLACK 32
#define LEN_BLUE  70

typedef struct {
    int col;
    int row;
} KeyPos;


static KeyPos pos_yellow[4] = {
    {0, 0},
    {0, 14},
    {3, 13},
    {5, 3}
};
static KeyPos pos_black[33] = {
    {0, 5},
    {0, 6},
    {0, 7},
    {0, 8},
    {0, 13},
    {1, 13}, // BkSp
    {1, 14},
    {1, 15},
    {1, 16},
    {1, 17},
    {1, 18},
    {1, 19},
    {1, 20},
    {2, 0},
    {2, 14},
    {2, 15},
    {2, 16},
    {3, 0},
    {3, 20},
    {4, 0},
    {4, 12},
    {4, 13},
    {5, 0},
    {5, 1},
    {5, 2},
    {5, 4},
    {5, 5},
    {5, 6},
    {5, 7},
    {5, 8},
    {5, 9},
    {5, 10},
    {5, 13}
};
static KeyPos pos_blue[71] = {
    {0, 1},
    {0, 2},
    {0, 3},
    {0, 4},
    {0, 9},
    {0, 10},
    {0, 11},
    {0, 12},
    {0, 16},
    {0, 17},
    {0, 18},
    {0, 19},
    {1, 0},
    {1, 1},
    {1, 2},
    {1, 3},
    {1, 4},
    {1, 5},
    {1, 6},
    {1, 7},
    {1, 8},
    {1, 9},
    {1, 10},
    {1, 11},
    {1, 12},
    {2, 1},
    {2, 2},
    {2, 3},
    {2, 4},
    {2, 5},
    {2, 6},
    {2, 7},
    {2, 8},
    {2, 9},
    {2, 10},
    {2, 11},
    {2, 12},
    {2, 17},
    {2, 18},
    {2, 19},
    {3, 1},
    {3, 2},
    {3, 3},
    {3, 4},
    {3, 5},
    {3, 6},
    {3, 7},
    {3, 8},
    {3, 9},
    {3, 10},
    {3, 11},
    {3, 12},
    {3, 16},
    {3, 17},
    {3, 18},
    {4, 1},
    {4, 2},
    {4, 3},
    {4, 4},
    {4, 5},
    {4, 6},
    {4, 7},
    {4, 8},
    {4, 9},
    {4, 10},
    {4, 11},
    {4, 17},
    {4, 18},
    {4, 19},
    {5, 11},
    {5, 12}
};


static bool zpm_static_init(effect_params_t* params) {
    if (params->init) {
        int i;

        for (i = 0; i < LEN_YELLOW; i++) {
            rgb_matrix_set_color(
                g_led_config.matrix_co[pos_yellow[i].row, pos_yellow[i].col],
                255,
                255,
                0
            );

        }

        for (i = 0; i < LEN_BLACK; i++) {
            rgb_matrix_set_color(
                g_led_config.matrix_co[pos_black[i].row, pos_black[i].col],
                255,
                255,
                255
            );

        }

        for (i = 0; i < LEN_BLUE; i++) {
            rgb_matrix_set_color(
                g_led_config.matrix_co[pos_blue[i].row, pos_blue[i].col],
                100,
                100,
                255
            );

        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

static bool zpm_static(effect_params_t* params) {
    if (params->init) zpm_static_init(params);
    //TODO: add key animations here
    return rgb_matrix_check_finished_leds(led_max);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
