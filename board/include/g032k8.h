#ifndef F042K6_H_
#define F042K6_H_

#include "common.h"
#include "gpio.h"

/* Notes */
/* 1 Mhz = 1,000,000 CPS */
/* 1 Mhz = 1 CPus */

/* Register Base */
/* Reset and Clock Control (RCC) */
#define RCC_BASE                    ((u32)0X40021000)                   /* RCC base address */

/* General Purpose I/O */
#define GPIOA_BASE                  ((u32)0x50000000)                   /* GPIO Port A base address */
#define GPIOB_BASE                  ((u32)0x50000400)                   /* GPIO Port B base address */
#define GPIOC_BASE                  ((u32)0x50000800)                   /* GPIO Port C base address */
#define GPIOD_BASE                  ((u32)0x50000C00)                   /* GPIO Port D base address */
#define GPIOE_BASE                  ((u32)0x50001000)                   /* GPIO Port E base address */
#define GPIOF_BASE                  ((u32)0x50001400)                   /* GPIO Port F base address */

/* Timers */
#define TIMER1_BASE                 ((u32)0x40012C00)
#define TIMER2_BASE                 ((u32)0x40000000)
#define TIMER3_BASE                 ((u32)0x40000400)
#define TIMER4_BASE                 ((u32)0x40000800)
#define TIMER6_BASE                 ((u32)0x40001000)
#define TIMER7_BASE                 ((u32)0x40001400)
#define TIMER14_BASE                ((u32)0x40002000)
#define TIMER15_BASE                ((u32)0x40014000)
#define TIMER16_BASE                ((u32)0x40014400)
#define TIMER17_BASE                ((u32)0x40014800)

/* USART (Universal Synchronous and Asynchronous Receiver Transmitter) */
#define USART1_BASE                 ((u32)0x40013800)
#define USART2_BASE                 ((u32)0x40004400)     
#define USART3_BASE                 ((u32)0x40004800)
#define USART4_BASE                 ((u32)0x40004C00)     
#define USART5_BASE                 ((u32)0x40005000)

/* Inter-Integrated Circuit (I2C) */
#define I2C1_BASE                   ((u32)0x40005400)
#define I2C2_BASE                   ((u32)0x40005800)

/* Serial Peripheral Interface */
#define SPI1_BASE                   ((u32)0x40013000)
#define SPI2_BASE                   ((u32)0x40003800)
#define SPI2_BASE                   ((u32)0x40003C00)

/* Controller Area Network Interface */
#define CAN_BASE                    ((u32)0x40006400)
#define CAN_RAM_BASE                ((u32)0x40006000)

/* System Control Base */
#define SCS_BASE                    ((u32)0xE000E000)
#define NVIC_BASE                   ((u32)0xE000E100)

/* Reset and Clock Control (RCC) */
#define RCC_GPIOA_AHB2EN            BIT_0                               /* GPIOA Enable is located on AHB2 Board Bit 0 */
#define RCC_GPIOB_AHB2EN            BIT_1                               /* GPIOB Enable is located on AHB2 Board Bit 1 */
#define RCC_GPIOC_AHB2EN            BIT_2                               /* GPIOC Enable is located on AHB2 Board Bit 2 */
#define RCC_GPIOD_AHB2EN            BIT_3                               /* GPIOD Enable is located on AHB2 Board Bit 3 */
#define RCC_GPIOE_AHB2EN            BIT_4                               /* GPIOE Enable is located on AHB2 Board Bit 4 */
#define RCC_GPIOF_AHB2EN            BIT_5                               /* GPIOE Enable is located on AHB2 Board Bit 4 */

/* General Purpose I/O */
/* NUCLEO BOARD PIN OUT SPECIFICS - NUCLEO - G031K8 */
#define GPIOC_PIN7                  (u32)7                              /* USER GREEN LED on GPIO C Bus, Pin 7  */
#define LED_GRN_PIN                 GPIOC_PIN7                          /* USER GREEN LED on GPIO C Bus, Pin 7  */
#define LED_GRN                     BIT_7                               /* USER GREEN LED on GPIO C Bus, Pin 7  */
#define GPIOB_PIN7                  (u32)7                              /* USER BLUE LED on GPIO B Bus, Pin 7   */
#define LED_BLU_PIN                 GPIOB_PIN7                          /* USER BLUE LED on GPIO B Bus, Pin 7   */
#define LED_BLU                     BIT_7                               /* USER BLUE LED on GPIO B Bus, Pin 7   */
#define GPIOA_PIN9                  (u32)9                              /* USER RED LED on GPIO A Bus, Pin 9    */
#define LED_RED_PIN                 GPIOA_PIN9                          /* USER RED LED on GPIO A Bus, Pin 9    */
#define LED_RED                     BIT_9                               /* USER RED LED on GPIO A Bus, Pin 9    */

/* PWM Motor Driver Pins */
#define GPIOF_PIN7                  (u32)7                              /* USER PIN on GPIO F Bus, Pin 7        */
#define GPIOF_PIN8                  (u32)8                              /* USER PIN on GPIO F Bus, Pin 8        */
#define GPIOF_PIN9                  (u32)9                              /* USER PIN on GPIO F Bus, Pin 9        */
#define GPIOE_PIN2                  (u32)2                              /* USER PIN on GPIO E Bus, Pin 2       */
#define AXIS_ENABLE                 GPIOE_PIN2
#define DIR_Z_AXIS                  GPIOF_PIN8
#define DIR_Y_AXIS                  GPIOF_PIN7
#define DIR_X_AXIS                  GPIOF_PIN9
#define AXIS_ENABLE_PIN             BIT_2
#define DIR_Z_AXIS_PIN              BIT_8
#define DIR_Y_AXIS_PIN              BIT_7
#define DIR_X_AXIS_PIN              BIT_9

/* TIMER3 PWM CH1 */
#define GPIOE_PIN3                  (u32)3                              /* PWM TIMER 3 on GPIO E Bus, Pin 3   */
#define TIM3_PWM1_PIN               GPIOE_PIN3                          /* PWM TIMER 3 on GPIO E Bus, Pin 3   */
#define TIM3_PWM1_AF                AF2                                 /* PWM TIMER 3 on GPIO E Bus, Pin 3   */

/* TIMER3 PWM CH2 */
#define GPIOE_PIN4                  (u32)4                              /* PWM TIMER 3 on GPIO E Bus, Pin 4   */
#define TIM3_PWM2_PIN               GPIOE_PIN4                          /* PWM TIMER 3 on GPIO E Bus, Pin 4   */
#define TIM3_PWM2_AF                AF2                                 /* PWM TIMER 3 on GPIO E Bus, Pin 4   */

/* TIMER3 PWM CH3 */
#define GPIOE_PIN5                  (u32)5                              /* PWM TIMER 3 on GPIO E Bus, Pin 5   */
#define TIM3_PWM3_PIN               GPIOE_PIN5                          /* PWM TIMER 3 on GPIO E Bus, Pin 5   */
#define TIM3_PWM3_AF                AF2                                 /* PWM TIMER 3 on GPIO E Bus, Pin 5   */

/* TIMER3 PWM CH4 */
#define GPIOE_PIN6                  (u32)6                              /* PWM TIMER 3 on GPIO E Bus, Pin 6   */
#define TIM3_PWM4_PIN               GPIOE_PIN6                          /* PWM TIMER 3 on GPIO E Bus, Pin 6   */
#define TIM3_PWM4_AF                AF2                                 /* PWM TIMER 3 on GPIO E Bus, Pin 6   */

/* Timer */
#define RCC_TIMER2_APB1R1EN         BIT_0
#define RCC_TIMER3_APB1R1EN         BIT_1
#define RCC_TIMER4_APB1R1EN         BIT_2

/* USART (Universal Synchronous and Asynchronous Receiver Transmitter) */
#define RCC_USART3_APB1R1EN         BIT_18
#define GPIOD_PIN8                  (u32)8                              /* GPIO Bus D Pin 8 TX - D1   */
#define GPIOD_PIN9                  (u32)9                              /* GPIO Bus D Pin 9 RX - D0   */
#define USART3_TX                   GPIOD_PIN8
#define USART3_RX                   GPIOD_PIN9

/* GPIO SETUP */
#define USART_MODE                  Gpio_Alternate
#define USART_OTYPE                 Gpio_Push_Pull
#define USART_AF                    AF7

/* SPI (Serial Peripheral Interface) */
/* SPI 1*/
/* RCC */
#define RCC_SPI1_APB2REN            BIT_12
#define GPIOB_PIN4                  (u32)4                              /* GPIO Bus B Pin 4 MISO  */
#define GPIOB_PIN5                  (u32)5                              /* GPIO Bus B Pin 5 MOSI  */
#define GPIOB_PIN3                  (u32)3                              /* GPIO Bus B Pin 3 SCK   */
#define GPIOA_PIN4                  (u32)4                              /* GPIO Bus A Pin 4 NSS   */
#define GPIOA_PIN7                  (u32)7                              /* GPIO Bus A Pin 7 SS - D11  */
#define SPI1_MISO                   GPIOB_PIN4
#define SPI1_MOSI                   GPIOB_PIN5
#define SPI1_SCK                    GPIOB_PIN3
#define SPI1_NSS                    GPIOA_PIN4
#define SPI1_SS                     GPIOA_PIN7                          /* This Is An Input */

/* GPIO SETUP */
#define SPI_MODE                    Gpio_Alternate
#define SPI_OTYPE                   Gpio_Push_Pull
#define SPI_AF                      AF5

enum nvic_irq {
    WWDG_IRQ,                       /*  0       Window Watchdog */
    PDV_VDDIO2_IRQ,                 /*  1       PVD and VDDIO2 Supply comparator interrupts */
    RTC_IRQ,                        /*  2       RTC interrupts (EXTI line 17, 19, 20) */
    FLASH_IRQ,                      /*  3       Flash interrupt */
    RCC_IRQ,                        /*  4       RCC interrupt */ 
    EXTI0_1_IRQ,                    /*  5       EXTI Line 0 and 1 interrupt */
    EXTI2_3_IRQ,                    /*  6       EXTI Line 2 and 3 interrupt */
    EXTI4_15_IRQ,                   /*  7       EXTI Line 4 - 15 interrupt */
    DMA1_CHANNEL1_IRQ = 9,          /*  9       DMA1 Channel 1 */
    DMA1_CHANNEL2_3_IRQ,            /*  10      DMA1 Channel 2 and Channel 3 interrupt */
    DMA1_CHANNEL4_5_IRQ,            /*  11      DMA1 Channel 4 and Channel 5 interrupt */
    ADC1_IRQ,                       /*  12      ADC1 interrupt */ 
    TIM1_BRK_UP_TRG_COM_IRQ,        /*  13      TIM1 Break, Update, Trigger and Commutation interrupt */
    TIM1_CC_IRQ,                    /*  14      TIM1 Capture Compare interrupt */
    TIM2_IRQ,                       /*  15      TIM2 interrupt */
    TIM3_IRQ,                       /*  16      TIM3 interrupt */
    LPTIM1_IRQ,                     /*  17      LPTIM1 interrupt */
    LPTIM2_IRQ,                     /*  18      LPTIM2 interrupt */
    TIM14_IRQ,                      /*  19      TIM14 interrupt */
    TIM16_IRQ = 21,                 /*  21      TIM16 interrupt */
    TIM17_IRQ,                      /*  22      TIM17 interrupt */
    I2C1_IRQ,                       /*  23      I2C1 interrupt */
    I2C2_IRQ,                       /*  24      I2C1 interrupt */
    SPI1_IRQ,                       /*  25      SPI1 interrupt */
    SPI2_IRQ,                       /*  26      SPI2 interrupt */
    USART1_IRQ,                     /*  27      USART1 interrupt */
    USART2_IRQ,                     /*  28      USART2 interrupt */
    LPUART1_IRQ,                    /*  29      LPUART1 interrupt */
};

#endif /* F042K6_H_ */