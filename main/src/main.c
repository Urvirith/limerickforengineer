/* Main Entry Of Program */
#include "main.h"

#define RCC         ((RCC_TypeDef *)RCC_BASE)
#define GPIOA       ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB       ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC       ((GPIO_TypeDef *)GPIOC_BASE)
#define TIMER2      ((TIMER_TypeDef *)TIMER2_BASE)


/* Extern Keyword Allows To Be Call */
extern void SystemInit() {
    rcc_write_iopenr(RCC, RCC_GPIOA_IOPENR);        // ENABLE GPIOA
    rcc_write_iopenr(RCC, RCC_GPIOB_IOPENR);        // ENABLE GPIOB
    rcc_write_iopenr(RCC, RCC_GPIOC_IOPENR);        // ENABLE GPIOB
    rcc_write_apbenr1(RCC, RCC_TIMER2_APBENR1);     // ENABLE TIMER 2
}

extern void main() {
    gpio_type(GPIOC, LED_GRN_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_BLB_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_BLF_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_BBL_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_BFL_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_ML_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_TL_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_TB_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_TF_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOB, LED_MF_PIN, Gpio_Output, Gpio_Push_Pull, AF0);
    gpio_type(GPIOA, LED_MB_PIN, Gpio_Output, Gpio_Push_Pull, AF0);


    timer_open(TIMER2, Timer_Cont, Timer_Upcount);
    timer_set_time(TIMER2, 1000, 16000, 1000);
    timer_start(TIMER2);

    u8 i = 0;

    while (1) {
        if (timer_get_flag(TIMER2)) {
            if (i >= 10) {
                i = 0;
            }
            
            if (i == 0) {
                gpio_set_pin(GPIOA, LED_BLB);
                gpio_clr_pin(GPIOA, LED_MB);
            }  else if (i == 1) {
                gpio_set_pin(GPIOA, LED_BLF);
                gpio_clr_pin(GPIOA, LED_BLB);
            }  else if (i == 2) {
                gpio_set_pin(GPIOA, LED_BBL);
                gpio_clr_pin(GPIOA, LED_BLF);
            }  else if (i == 3) {
                gpio_set_pin(GPIOA, LED_BFL);
                gpio_clr_pin(GPIOA, LED_BBL);
            }  else if (i == 4) {
                gpio_set_pin(GPIOA, LED_ML);
                gpio_clr_pin(GPIOA, LED_BFL);
            }  else if (i == 5) {
                gpio_set_pin(GPIOA, LED_TL);
                gpio_clr_pin(GPIOA, LED_ML);
            } else if (i == 6) {
                gpio_set_pin(GPIOB, LED_TB);
                gpio_clr_pin(GPIOA, LED_TL);
            } else if (i == 7) {
                gpio_set_pin(GPIOB, LED_TF);
                gpio_clr_pin(GPIOB, LED_TB);
            } else if (i == 8) {
                gpio_set_pin(GPIOB, LED_MF);
                gpio_clr_pin(GPIOB, LED_TF);
            } else if (i == 9) {
                gpio_set_pin(GPIOA, LED_MB);
                gpio_clr_pin(GPIOB, LED_MF);
            }



            sr_ptr_vol_bit_u32(&GPIOC->ODR, LED_GRN);
            timer_clr_flag(TIMER2);
            i += 1;
        }
    }

}

extern void __aeabi_unwind_cpp_pr0() {
    //loop {}
}
