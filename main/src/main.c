/* Main Entry Of Program */
#include "main.h"

/* Extern Keyword Allows To Be Call */
extern void SystemInit() {
    rcc_write_iopenr(RCC, RCC_GPIOA_IOPENR);        // ENABLE GPIOA
    rcc_write_iopenr(RCC, RCC_GPIOB_IOPENR);        // ENABLE GPIOB
    rcc_write_iopenr(RCC, RCC_GPIOC_IOPENR);        // ENABLE GPIOB
    rcc_write_apbenr1(RCC, RCC_TIMER2_APBENR1);     // ENABLE TIMER 2
}

extern void main() {
    /* GPIO Setup */
    gpio_type(GPIOC, LED_GRN_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    led_setup();

    LED_TypeDef leds;
    leds.reg = 0;

    timer_open(TIMER2, Timer_Cont, Timer_Upcount);
    timer_set_time(TIMER2, 200, 16000, 50);
    timer_start(TIMER2);

    u8 i = 0;

    while (1) {
        if (timer_get_flag(TIMER2)) {
            if (i >= 20) {
                leds.reg = 0;
                i = 0;
            }
            
            if (i == 0) {
                leds.fields.LOWER_LEFT_FRONT = 1;
            }  else if (i == 1) {
                leds.fields.LOWER_LEFT_BACK = 1;
            }  else if (i == 2) {
                leds.fields.LOWER_BACK_LEFT = 1;
            }  else if (i == 3) {
                leds.fields.LOWER_BACK_RIGHT = 1;
            }  else if (i == 4) {
                leds.fields.LOWER_RIGHT_BACK = 1;
            }  else if (i == 5) {
                leds.fields.LOWER_RIGHT_FRONT = 1;
            } else if (i == 6) {
                leds.fields.LOWER_FRONT_RIGHT = 1;
            } else if (i == 7) {
                leds.fields.LOWER_FRONT_LEFT = 1;
            } else if (i == 8) {
                leds.reg = 0;
                leds.fields.MIDDLE_LEFT = 1;
            } else if (i == 9) {
                leds.fields.MIDDLE_BACK = 1;
            } else if (i == 10) {
                leds.fields.MIDDLE_RIGHT = 1;
            } else if (i == 11) {
                leds.fields.MIDDLE_FRONT = 1;
            } else if (i == 12) {
                leds.reg = 0;
                leds.fields.UPPER_LEFT = 1;
            } else if (i == 13) {
                leds.fields.UPPER_BACK = 1;
            } else if (i == 14) {
                leds.fields.UPPER_RIGHT = 1;
            } else if (i == 15) {
                leds.fields.UPPER_FRONT = 1;
            } else if (i == 16) {
                leds.reg = 0;
                leds.fields.LOWER_LEFT_FRONT = 1;
                leds.fields.LOWER_LEFT_BACK = 1;
                leds.fields.LOWER_BACK_LEFT = 1;
                leds.fields.LOWER_BACK_RIGHT = 1;
                leds.fields.LOWER_RIGHT_BACK = 1;
                leds.fields.LOWER_RIGHT_FRONT = 1;
                leds.fields.LOWER_FRONT_RIGHT = 1;
                leds.fields.LOWER_FRONT_LEFT = 1;
            } else if (i == 17) {
                leds.fields.MIDDLE_LEFT = 1;
                leds.fields.MIDDLE_BACK = 1;
                leds.fields.MIDDLE_RIGHT = 1;
                leds.fields.MIDDLE_FRONT = 1;
            } else if (i == 18) {
                leds.fields.UPPER_LEFT = 1;
                leds.fields.UPPER_BACK = 1;
                leds.fields.UPPER_RIGHT = 1;
                leds.fields.UPPER_FRONT = 1;
            } else if (i == 19) {
                leds.fields.MIDDLE_LEFT = 0;
                leds.fields.MIDDLE_BACK = 0;
                leds.fields.MIDDLE_RIGHT = 0;
                leds.fields.MIDDLE_FRONT = 0;
            }

            led_set(leds);

            sr_ptr_vol_bit_u32(&GPIOC->ODR, LED_GRN);
            timer_clr_flag(TIMER2);
            i += 1;
        }
    }

}

extern void __aeabi_unwind_cpp_pr0() {
    //loop {}
}
