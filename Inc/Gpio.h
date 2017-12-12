/*
 * Gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include "stm32f4xx.h"
#define GPIOA_BASE_ADDR				0x40020000
#define GPIOB_BASE_ADDR				0x40020400
#define GPIOC_BASE_ADDR				0x40020800
#define GPIOD_BASE_ADDR				0x40020c00
#define GPIOE_BASE_ADDR				0x40021000
#define GPIOF_BASE_ADDR				0x40021400
#define GPIOG_BASE_ADDR 			0x40021800
#define GPIOH_BASE_ADDR				0x40021c00
#define GPIOI_BASE_ADDR				0x40022000

#define GpioA     ((GpioReg*)(GPIOA_BASE_ADDR))
#define GpioB     ((GpioReg*)(GPIOB_BASE_ADDR))
#define GpioC     ((GpioReg*)(GPIOC_BASE_ADDR))
#define GpioD     ((GpioReg*)(GPIOD_BASE_ADDR))
#define GpioE     ((GpioReg*)(GPIOE_BASE_ADDR))
#define GpioF     ((GpioReg*)(GPIOF_BASE_ADDR))
#define GpioG     ((GpioReg*)(GPIOG_BASE_ADDR))
#define GpioH     ((GpioReg*)(GPIOH_BASE_ADDR))
#define GpioI     ((GpioReg*)(GPIOI_BASE_ADDR))


typedef struct GpioReg GpioReg;
struct GpioReg{
	volatile uint32_t mode;
	volatile uint32_t outType;
  volatile uint32_t outSpeed;
  volatile uint32_t pullType;
  volatile uint32_t inData;
  volatile uint32_t outData;
  volatile uint32_t bitData;
  volatile uint32_t lock;
  volatile uint32_t altFuncLo;
  volatile uint32_t altFuncHi;
};



#define  GPIO_MODE_IN   	0x00000000U   /*!< Input Floating Mode                   */
#define  GPIO_MODE_OUT		0x00000001U   /*!< Output Push Pull Mode                 */
#define  GPIO_MODE_AF	    0x00000002U   /*!< Alternate Function Push Pull Mode     */
#define  GPIO_MODE_AN		3

#define GPIO_PUSH_PULL			0
#define GPIO_OPEN_DRAIN			1

#define GPIO_L_SPEED			0
#define GPIO_M_SPEED			1
#define GPIO_H_SPEED			2
#define GPIO_VH_SPEED			3

#define  GPIO_NOPULL        0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_PULLUP        0x00000001U   /*!< Pull-up activation                  */
#define  GPIO_PULLDOWN      0x00000002U   /*!< Pull-down activation*/

#define	GPIO_SET_ALTFUNCL(gpio, pin, x)			MODIFY_REG(gpio->altFuncLo, 0xff<<(pin*4), x<<(pin*4))

void gpioConfig(GpioReg *gpio, int pin, int mode, int outDriveType, int pullType, int speed);
void gpioWrite(GpioReg *gpio, int pin, int state);

void gpioGConfig(int pin, int mode, int outDriveType, int pullType, int speed);
void gpioGWrite(int pin, int state);
int gpioARead(int pin);
int gpioRead(GpioReg *gpio, int pin);
void gpioAConfig(int pin, int mode, int outDriveType, int pullType, int speed);
void gpioToggle(GpioReg *gpio, int pin);
void setGpioAlternateFunc(GpioReg *gpio, int pin, int altFunc);
extern uint32_t *gpioAIdr;
#endif /* GPIO_H_ */
