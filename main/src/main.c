/* Main Entry Of Program */
#include "main.h"

INNERProcess_TypeDef ip;

/* Extern Keyword Allows To Be Call */
extern void SystemInit() {
    rcc_write_iopenr(RCC, RCC_GPIOA_IOPENR);        // ENABLE GPIOA
    rcc_write_iopenr(RCC, RCC_GPIOB_IOPENR);        // ENABLE GPIOB
    rcc_write_iopenr(RCC, RCC_GPIOC_IOPENR);        // ENABLE GPIOC
    rcc_write_apbenr1(RCC, RCC_TIMER2_APBENR1);     // ENABLE TIMER 2
    rcc_write_apbenr1(RCC, RCC_TIMER3_APBENR1);     // ENABLE TIMER 3
}

extern void main() {
    ip.reg = 0;
    /* GPIO Setup */
    gpio_type(GPIOC, LED_GRN_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    led_setup();

    timer_open(TIMER2, Timer_Ons, Timer_Upcount);
    timer_ons_delay(TIMER2, 50);
    timer_set_time(TIMER2, 200, 16000, 50);
    timer_start(TIMER2);

    timer_open(TIMER3, Timer_Ons, Timer_Upcount);
    timer_set_interrupt(TIMER3);
    timer_ons_delay(TIMER3, 50);

    timer_set_time(TIMER3, 1000, 16000, 500);
    nvic_enable_interrupt(NVIC, TIM3_IRQ);
    timer_start(TIMER3);

    sr_ptr_vol_bit_u32(&GPIOC->ODR, LED_GRN);

    LED_Recipe_TypeDef recipe = led_template();

    u8 i = 0;
    u16 trigger = 0;

    while (1) {
        if (i >= recipe.cnt) {
            i = 0;

            if (trigger != ip.fields.TRIGGER) {
                if (ip.fields.TRIGGER) {
                    recipe = led_rain_fall();
                } else {
                    recipe = led_template();
                }

                trigger = ip.fields.TRIGGER;
            }
        }

        timer_set_time(TIMER2, recipe.elms[i].time_ms, 16000, recipe.elms[i].prescale);
        timer_start(TIMER2);

        while (!timer_get_flag(TIMER2)) {
            // SPIN
        }

        timer_clr_flag(TIMER2);

        led_set(recipe.elms[i].leds);

        i += 1;
    }
}

extern void TIM3_IRQHandler() {
    timer_clr_flag(TIMER3);
    sr_ptr_vol_bit_u32(&GPIOC->ODR, LED_GRN);

    if (ip.fields.COUNT >= 30) {
        ip.fields.COUNT = 0;
        if (ip.fields.TRIGGER) {
            ip.fields.TRIGGER = 0;
        } else {
            ip.fields.TRIGGER = 1;
        }
    }

    ip.fields.COUNT += 1;

    timer_start(TIMER3);
}

extern void __aeabi_unwind_cpp_pr0() {
    //loop {}
}
