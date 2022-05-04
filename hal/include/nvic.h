#ifndef NVIC_H_
#define NVIC_H_

#include "common.h"
#include "pointer.h"

// NVIC DRIVER
// ARM NVIC MODULE
// NVIC Description - is on pg 209
// NVIC Registers (Programming Manual) - is on 76

/* Nested vectored interrupt controller (NVIC) */
typedef struct {
	volatile u32   ISER[1];			// Interrupt Set-Enable register
	volatile u32   Reserved0[31];	// Offset
	volatile u32   ICER[1]; 	    // Interrupt Clear-Enable register
	volatile u32   Reserved1[31];  	// Offset
	volatile u32   ISPR[1];			// Interrupt Set-Pending Registers
	volatile u32   Reserved2[31];	// Offset
	volatile u32   ICPR[1];			// Interrupt Clear-Pending Registers
	volatile u32   Reserved3[95];	// Offset
	volatile u8    IPR[32];			// Interrupt Priority Registers
} NVIC_TypeDef;

/* Public Functions */
void nvic_enable_interrupt(NVIC_TypeDef *ptr, u32 irq_num);
void nvic_set_priority(NVIC_TypeDef *ptr, u32 irq_num, u8 priority, u8 sub_priority);

#endif /* NVIC_H_ */
