/*
 * Nvic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: user
 */

#ifndef NVIC_H_
#define NVIC_H_

#include <stdint.h>
#define NVIC_BASE_ADDR		0xE000E100
#define Nvic				((NvicReg*)(NVIC_BASE_ADDR))

typedef struct NvicReg NvicReg;

struct NvicReg {
volatile uint32_t ISER[3];
volatile uint32_t RESERVED1[29];
volatile uint32_t ICER[3];
volatile uint32_t RESERVED2[29];
volatile uint32_t ISPR[3];
volatile uint32_t RESERVED3[29];
volatile uint32_t ICPR[3];
volatile uint32_t RESERVED4[29];
volatile uint32_t IABR[3];
volatile uint32_t RESERVED5[61];
volatile uint32_t IPR[21];
volatile uint32_t RESERVED6[683];
volatile uint32_t STIR;
};


#define nvicEnableIrq(irqNum)				(Nvic->ISER[irqNum>>5] |= 1<<(irqNum&0x1f))
#define nvicDisableIrq(irqNum)				(Nvic->ICER[irqNum>>5] |= 1<<irqNum&0x1f)
#define nvicSetPrior(irqNum, prior)			(Nvic->IPR[irqNum>>2] |= prior<<(irqNum&0x3)* 8 + 4)
#endif /* NVIC_H_ */
