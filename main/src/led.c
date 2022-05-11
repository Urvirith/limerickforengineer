#include "led.h"

void led_setup() {
    gpio_type(GPIOA, LED_LLB_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_LLF_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_LBL_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_LFL_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_ML_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_UL_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_UB_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_UF_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_MF_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_MB_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_UR_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_LBR_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_MR_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_LFR_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_LRB_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_LRF_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
}

void led_set(LED_TypeDef leds) {

    if (leds.fields.LOWER_LEFT_FRONT) {
        gpio_set_pin(GPIOA, LED_LLF);
    } else {
        gpio_clr_pin(GPIOA, LED_LLF);
    }

    if (leds.fields.LOWER_LEFT_BACK) {
        gpio_set_pin(GPIOA, LED_LLB);
    } else {
        gpio_clr_pin(GPIOA, LED_LLB);
    }

    if (leds.fields.LOWER_FRONT_LEFT) {
        gpio_set_pin(GPIOA, LED_LFL);
    } else {
        gpio_clr_pin(GPIOA, LED_LFL);
    }

    if (leds.fields.LOWER_FRONT_RIGHT) {
        gpio_set_pin(GPIOA, LED_LFR);
    } else {
        gpio_clr_pin(GPIOA, LED_LFR);
    }

    if (leds.fields.LOWER_BACK_LEFT) {
        gpio_set_pin(GPIOA, LED_LBL);
    } else {
        gpio_clr_pin(GPIOA, LED_LBL);
    }

    if (leds.fields.LOWER_BACK_RIGHT) {
        gpio_set_pin(GPIOB, LED_LBR);
    } else {
        gpio_clr_pin(GPIOB, LED_LBR);
    }

    if (leds.fields.LOWER_RIGHT_FRONT) {
        gpio_set_pin(GPIOB, LED_LRF);
    } else {
        gpio_clr_pin(GPIOB, LED_LRF);
    }

    if (leds.fields.LOWER_RIGHT_BACK) {
        gpio_set_pin(GPIOA, LED_LRB);
    } else {
        gpio_clr_pin(GPIOA, LED_LRB);
    }

    if (leds.fields.MIDDLE_LEFT) {
        gpio_set_pin(GPIOA, LED_ML);
    } else {
        gpio_clr_pin(GPIOA, LED_ML);
    }

    if (leds.fields.MIDDLE_FRONT) {
        gpio_set_pin(GPIOB, LED_MF);
    } else {
        gpio_clr_pin(GPIOB, LED_MF);
    }

    if (leds.fields.MIDDLE_BACK) {
        gpio_set_pin(GPIOA, LED_MB);
    } else {
        gpio_clr_pin(GPIOA, LED_MB);
    }

    if (leds.fields.MIDDLE_RIGHT) {
        gpio_set_pin(GPIOB, LED_MR);
    } else {
        gpio_clr_pin(GPIOB, LED_MR);
    }

    if (leds.fields.UPPER_LEFT) {
        gpio_set_pin(GPIOA, LED_UL);
    } else {
        gpio_clr_pin(GPIOA, LED_UL);
    }

    if (leds.fields.UPPER_FRONT) {
        gpio_set_pin(GPIOB, LED_UF);
    } else {
        gpio_clr_pin(GPIOB, LED_UF);
    }

    if (leds.fields.UPPER_BACK) {
        gpio_set_pin(GPIOB, LED_UB);
    } else {
        gpio_clr_pin(GPIOB, LED_UB);
    }

    if (leds.fields.UPPER_RIGHT) {
        gpio_set_pin(GPIOB, LED_UR);
    } else {
        gpio_clr_pin(GPIOB, LED_UR);
    }
}


LED_Recipe_TypeDef led_template() {
    LED_Recipe_TypeDef recipe;
    
    recipe.cnt = 21;
    recipe.elms[0].time_ms = 500;
    recipe.elms[0].prescale = recipe.elms[0].time_ms / 2;
    recipe.elms[0].leds.reg = 0;
    recipe.elms[0].leds.fields.LOWER_LEFT_FRONT = 1;

    recipe.elms[1].time_ms = 500;
    recipe.elms[1].prescale = recipe.elms[1].time_ms / 2;
    recipe.elms[1].leds.reg = recipe.elms[0].leds.reg;
    recipe.elms[1].leds.fields.LOWER_LEFT_BACK = 1;

    recipe.elms[2].time_ms = 500;
    recipe.elms[2].prescale = recipe.elms[2].time_ms / 2;
    recipe.elms[2].leds.reg = recipe.elms[1].leds.reg;
    recipe.elms[2].leds.fields.LOWER_BACK_LEFT = 1;

    recipe.elms[3].time_ms = 500;
    recipe.elms[3].prescale = recipe.elms[3].time_ms / 2;
    recipe.elms[3].leds.reg = recipe.elms[2].leds.reg;
    recipe.elms[3].leds.fields.LOWER_BACK_RIGHT = 1;

    recipe.elms[4].time_ms = 500;
    recipe.elms[4].prescale = recipe.elms[4].time_ms / 2;
    recipe.elms[4].leds.reg = recipe.elms[3].leds.reg;
    recipe.elms[4].leds.fields.LOWER_RIGHT_BACK = 1;

    recipe.elms[5].time_ms = 500;
    recipe.elms[5].prescale = recipe.elms[5].time_ms / 2;
    recipe.elms[5].leds.reg = recipe.elms[4].leds.reg;
    recipe.elms[5].leds.fields.LOWER_RIGHT_FRONT = 1;

    recipe.elms[6].time_ms = 500;
    recipe.elms[6].prescale = recipe.elms[6].time_ms / 2;
    recipe.elms[6].leds.reg = recipe.elms[5].leds.reg;
    recipe.elms[6].leds.fields.LOWER_FRONT_RIGHT = 1;

    recipe.elms[7].time_ms = 500;
    recipe.elms[7].prescale = recipe.elms[7].time_ms / 2;
    recipe.elms[7].leds.reg = recipe.elms[6].leds.reg;
    recipe.elms[7].leds.fields.LOWER_FRONT_LEFT = 1;

    recipe.elms[8].time_ms = 250;
    recipe.elms[8].prescale = recipe.elms[8].time_ms / 2;
    recipe.elms[8].leds.reg = 0;
    recipe.elms[8].leds.fields.MIDDLE_LEFT = 1;

    recipe.elms[9].time_ms = 250;
    recipe.elms[9].prescale = recipe.elms[9].time_ms / 2;
    recipe.elms[9].leds.reg = recipe.elms[8].leds.reg;
    recipe.elms[9].leds.fields.MIDDLE_BACK = 1;

    recipe.elms[10].time_ms = 250;
    recipe.elms[10].prescale = recipe.elms[10].time_ms / 2;
    recipe.elms[10].leds.reg = recipe.elms[9].leds.reg;
    recipe.elms[10].leds.fields.MIDDLE_RIGHT = 1;

    recipe.elms[11].time_ms = 250;
    recipe.elms[11].prescale = recipe.elms[11].time_ms / 2;
    recipe.elms[11].leds.reg = recipe.elms[10].leds.reg;
    recipe.elms[11].leds.fields.MIDDLE_FRONT = 1;

    recipe.elms[12].time_ms = 100;
    recipe.elms[12].prescale = recipe.elms[12].time_ms / 2;
    recipe.elms[12].leds.reg = 0;
    recipe.elms[12].leds.fields.UPPER_LEFT = 1;

    recipe.elms[13].time_ms = 100;
    recipe.elms[13].prescale = recipe.elms[13].time_ms / 2;
    recipe.elms[13].leds.reg = recipe.elms[12].leds.reg;
    recipe.elms[13].leds.fields.UPPER_BACK = 1;

    recipe.elms[14].time_ms = 100;
    recipe.elms[14].prescale = recipe.elms[14].time_ms / 2;
    recipe.elms[14].leds.reg = recipe.elms[13].leds.reg;
    recipe.elms[14].leds.fields.UPPER_RIGHT = 1;

    recipe.elms[15].time_ms = 100;
    recipe.elms[15].prescale = recipe.elms[15].time_ms / 2;
    recipe.elms[15].leds.reg = recipe.elms[14].leds.reg;
    recipe.elms[15].leds.fields.UPPER_FRONT = 1;

    recipe.elms[16].time_ms = 1000;
    recipe.elms[16].prescale = recipe.elms[16].time_ms / 2;
    recipe.elms[16].leds.reg = 0;
    recipe.elms[16].leds.fields.LOWER_LEFT_FRONT = 1;
    recipe.elms[16].leds.fields.LOWER_LEFT_BACK = 1;
    recipe.elms[16].leds.fields.LOWER_BACK_LEFT = 1;
    recipe.elms[16].leds.fields.LOWER_BACK_RIGHT = 1;
    recipe.elms[16].leds.fields.LOWER_RIGHT_BACK = 1;
    recipe.elms[16].leds.fields.LOWER_RIGHT_FRONT = 1;
    recipe.elms[16].leds.fields.LOWER_FRONT_RIGHT = 1;
    recipe.elms[16].leds.fields.LOWER_FRONT_LEFT = 1;

    recipe.elms[17].time_ms = 500;
    recipe.elms[17].prescale = recipe.elms[17].time_ms / 2;
    recipe.elms[17].leds.reg = recipe.elms[16].leds.reg;
    recipe.elms[17].leds.fields.MIDDLE_LEFT = 1;
    recipe.elms[17].leds.fields.MIDDLE_BACK = 1;
    recipe.elms[17].leds.fields.MIDDLE_RIGHT = 1;
    recipe.elms[17].leds.fields.MIDDLE_FRONT = 1;

    recipe.elms[18].time_ms = 250;
    recipe.elms[18].prescale = recipe.elms[18].time_ms / 2;
    recipe.elms[18].leds.reg = recipe.elms[17].leds.reg;
    recipe.elms[18].leds.fields.UPPER_LEFT = 1;
    recipe.elms[18].leds.fields.UPPER_BACK = 1;
    recipe.elms[18].leds.fields.UPPER_RIGHT = 1;
    recipe.elms[18].leds.fields.UPPER_FRONT = 1;

    recipe.elms[19].time_ms = 1000;
    recipe.elms[19].prescale = recipe.elms[19].time_ms / 2;
    recipe.elms[19].leds.reg = recipe.elms[18].leds.reg;
    recipe.elms[19].leds.fields.MIDDLE_LEFT = 1;
    recipe.elms[19].leds.fields.MIDDLE_BACK = 1;
    recipe.elms[19].leds.fields.MIDDLE_RIGHT = 1;
    recipe.elms[19].leds.fields.MIDDLE_FRONT = 1;

    recipe.elms[20].time_ms = 50;
    recipe.elms[20].prescale = recipe.elms[20].time_ms / 2;
    recipe.elms[20].leds.reg = 0;

    return recipe;
}
