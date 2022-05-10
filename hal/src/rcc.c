/* Reset and Clock Control (RCC) */
#include "rcc.h"

/* Register Masks */
/* CFGR */
#define SW_MASK         MASK_2_BIT
#define PLLSRC_MASK     MASK_2_BIT
#define PLLMUL_MASK     MASK_4_BIT

/* CFGR 2 */
#define PREDIV_MASK     MASK_4_BIT

/* Register Bits */
/* CR */
#define HSION           BIT_0       
#define MSIRGSEL        BIT_3
#define PLLON           BIT_24
#define PLLRDY          BIT_25

/* PLLxxx */
#define PLLPEN          BIT_17
#define PLLP            BIT_18
#define PLLQEN          BIT_20
#define PLLREN          BIT_24


/* Register Offsets */
/* CR */    
#define MSIRANGE_OFFSET 4 

/* CFGR */
#define SW_OFFSET       0
#define SWS_OFFSET      2
#define PLLSRC_OFFSET   15
#define PLLMUL_OFFSET   18

/* CFGR 2 */
#define PREDIV_OFFSET   0

/* Local Functions */
static inline void set_prediv(RCC_TypeDef *ptr, RCC_PREDiv prediv);

/* Set system clock source */
void rcc_sys_clk(RCC_TypeDef *ptr, RCC_SYSSrc src) {
    set_ptr_vol_u32(&ptr->CFGR, SW_OFFSET, SW_MASK, src);
    while (get_ptr_vol_u32(&ptr->CFGR, SWS_OFFSET, SW_MASK) != src) {
        // SPIN WHILE CLOCK IS NOT SET TO SYSTEM CLOCK SOURCE REQUEST
    };
}

/* Set PLL Source And Multiplier */
void rcc_set_pll(RCC_TypeDef *ptr, RCC_PLLSrc src, RCC_PREDiv prediv, RCC_PLLMul pllmul) {
    clr_ptr_vol_bit_u32(&ptr->CR, PLLON);
    while(get_ptr_vol_bit_u32(&ptr->CR, PLLRDY)){
        // Spin Dead Until PLL Not Ready
    };
    
    set_prediv(ptr, prediv);                                            // Set PreDiv
    set_ptr_vol_u32(&ptr->CFGR, PLLSRC_OFFSET, PLLSRC_MASK, src);       // Set Clock Source
    set_ptr_vol_u32(&ptr->CFGR, PLLMUL_OFFSET, PLLMUL_MASK, pllmul);    // Set Multplier Factor 2<=PLLMUL<=16 

    set_ptr_vol_bit_u32(&ptr->CR, PLLON);
    while(!get_ptr_vol_bit_u32(&ptr->CR, PLLRDY)){
        // Spin Dead Until PLL Ready
    };
}

void rcc_write_iopenr(RCC_TypeDef *ptr, u32 val) {
    set_ptr_vol_bit_u32(&ptr->IOPENR, val);
}

void rcc_write_ahbenr(RCC_TypeDef *ptr, u32 val) {
    set_ptr_vol_bit_u32(&ptr->AHBENR, val);
}

void rcc_write_apbenr1(RCC_TypeDef *ptr, u32 val) {
    set_ptr_vol_bit_u32(&ptr->APBENR1, val);
}

void rcc_write_apbenr2(RCC_TypeDef *ptr, u32 val) {
    set_ptr_vol_bit_u32(&ptr->APBENR2, val);
}

/* Set PREDIV */
static inline void set_prediv(RCC_TypeDef *ptr, RCC_PREDiv prediv) {
    set_ptr_vol_u32(&ptr->CFGR, PREDIV_OFFSET, PREDIV_MASK, prediv);
}