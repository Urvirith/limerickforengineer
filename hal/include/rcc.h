#ifndef RCC_H_
#define RCC_H_

#include "common.h"
#include "pointer.h"

// RCC DRIVER
// ARM RCC MODULE
// RCC Description - is on pg 93
// RCC Register Map - is on pg 135

/* Reset and Clock Control (RCC) */
typedef struct {
    volatile u32 CR;                // Clock Control Register
    volatile u32 ICSCR;             // Internal Clock Source Calibration Register
    volatile u32 CFGR;              // Clock Configuration Register
    volatile u32 PLLCFGR;           // PLL Configuration Register
    volatile u32 RESERVED0;         // Reserved Register
    volatile u32 CRRCR;             // Clock Recovery RC Register
    volatile u32 CIER;              // Clock Interrupt Enable Register
    volatile u32 CIFR;              // Clock Interrupt Flag Register 
    volatile u32 CICR;              // Clock Interrupt Clear Register
    volatile u32 IOPRSTR;           // I/O Port Reset Register    
    volatile u32 AHBRSTR;           // AHB Peripheral Reset Register
    volatile u32 APBRSTR1;          // APB Peripheral Reset Register 1
    volatile u32 APBRSTR2;          // APB Peripheral Reset Register 2
    volatile u32 IOPENR;            // I/O Port Clock Enable Register 2
    volatile u32 AHBENR;            // AHB Peripheral Clock Enable Register
    volatile u32 APBENR1;           // APB Peripheral Clock Enable Register 1
    volatile u32 APBENR2;           // APB Peripheral Clock Enable Register 2
    volatile u32 IOPSMENR;          // I/O Port Clock Enable In Sleep Stop Register
    volatile u32 AHBSMENR;          // AHB Peripheral Clock Enable In Sleep Stop Register
    volatile u32 APBSMENR1;         // APB Peripheral Clock Enable In Sleep Stop Register 1
    volatile u32 APBSMENR2;         // APB Peripheral Clock Enable In Sleep Stop Register 2
    volatile u32 CCIPR;             // Peripherals Independant Clock Configuration Register
    volatile u32 CCIPR2;            // Peripherals Independant Clock Configuration Register
    volatile u32 BDCR;              // RTC Domain Control Register
    volatile u32 CSR;               // Control Status Register
} RCC_TypeDef;

typedef enum rcc_syssrc {
    RCC_HSI,                        // HSI Selected As System Clock
    RCC_HSE,                        // HSE Selected As System Clock
    RCC_PLL,                        // PLL Selected As System Clock
    RCC_HSI48,                      // HSI48 Selected As System Clock
} RCC_SYSSrc;

typedef enum rcc_pllsrc {
    RCC_HSI_2,
    RCC_HSI_PREDIV,
    RCC_HSE_PREDIV,
    RCC_HSI48_PREDIV,
} RCC_PLLSrc;

typedef enum rcc_plldiv {
    RCC_PLLMul2,
    RCC_PLLMul3,
    RCC_PLLMul4,
    RCC_PLLMul5,
    RCC_PLLMul6,
    RCC_PLLMul7,
    RCC_PLLMul8,
    RCC_PLLMul9,
    RCC_PLLMul10,
    RCC_PLLMul11,
    RCC_PLLMul12,
    RCC_PLLMul13,
    RCC_PLLMul14,
    RCC_PLLMul15,
    RCC_PLLMul16,
} RCC_PLLMul;

typedef enum rcc_prediv {
    RCC_PREDiv1,
    RCC_PREDiv2,
    RCC_PREDiv3,
    RCC_PREDiv4,
    RCC_PREDiv5,
    RCC_PREDiv6,
    RCC_PREDiv7,
    RCC_PREDiv8,
    RCC_PREDiv9,
    RCC_PREDiv10,
    RCC_PREDiv11,
    RCC_PREDiv12,
    RCC_PREDiv13,
    RCC_PREDiv14,
    RCC_PREDiv15,
    RCC_PREDiv16,
} RCC_PREDiv;

/* Public Functions */
void rcc_sys_clk(RCC_TypeDef *ptr, RCC_SYSSrc src);
void rcc_set_pll(RCC_TypeDef *ptr, RCC_PLLSrc src, RCC_PREDiv prediv, RCC_PLLMul pllmul);
void rcc_write_ahb_enr(RCC_TypeDef *ptr, u32 val);
void rcc_write_apb1_enr(RCC_TypeDef *ptr, u32 val);
void rcc_write_apb2_enr(RCC_TypeDef *ptr, u32 val);

#endif /* RCC_H_ */
