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

