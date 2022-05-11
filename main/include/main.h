#ifndef MAIN_H_
#define MAIN_H_

#include "g032k8.h"
#include "rcc.h"
#include "gpio.h"
#include "timer.h"
#include "nvic.h"
#include "led.h"

/* Define Memory Mapped I/O Used */
#define RCC         ((RCC_TypeDef *)RCC_BASE)
#define GPIOA       ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB       ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC       ((GPIO_TypeDef *)GPIOC_BASE)
#define TIMER2      ((TIMER_TypeDef *)TIMER2_BASE)
#define TIMER3      ((TIMER_TypeDef *)TIMER3_BASE)
#define NVIC        ((NVIC_TypeDef *)NVIC_BASE)

#endif /* MAIN_H_ */