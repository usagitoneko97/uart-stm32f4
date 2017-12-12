/*
 * Gpio.c

 *
 *  Created on: Oct 27, 2017
 *      Author: user
 */

#include"Gpio.h"



void gpioGConfig(int pin, int mode, int outDriveType, int pullType, int speed){
	/*clear pin mode to 0*/
	GpioG->mode &= ~(3<<(pin*2));
	/*set the mode*/
	GpioG->mode |= (mode<<(pin*2));
	//*gpioGMode = 0xff;

	GpioG->outSpeed   &= ~(3<<(pin*2)); //clear the pin speed
	GpioG->outSpeed  |= speed<<(pin*2); //set the pin speed

	GpioG->pullType = ~(pullType<<(pin*2)); //set the pupd

	GpioG->outType |= (outDriveType<<pin);

}

void gpioConfig(GpioReg *gpio, int pin, int mode, int outDriveType, int pullType, int speed){
	/*clear pin mode to 0*/
	gpio->mode &= ~(3<<(pin*2));
	/*set the mode*/
	gpio->mode |= (mode<<(pin*2));
	//*gpioGMode = 0xff;

	gpio->outSpeed  &= ~(3<<(pin*2)); //clear the pin speed
	gpio->outSpeed  |= speed<<(pin*2); //set the pin speed

	gpio->pullType &= ~(3<<(pin*2)); //clear to 0
	gpio->pullType |= (pullType<<(pin*2)); //set the pupd

	gpio->outType |= (outDriveType<<pin);

}

void gpioAConfig(int pin, int mode, int outDriveType, int pullType, int speed){
	/*clear pin mode to 0*/
	GpioA->mode &= ~(3<<(pin*2));
	/*set the mode*/
	GpioA->mode |= (mode<<(pin*2));
	//*gpioGMode = 0xff;

	GpioA->outSpeed   &= ~(3<<(pin*2)); //clear the pin speed
	GpioA->outSpeed  |= speed<<(pin*2); //set the pin speed

	GpioA->pullType = ~(pullType<<(pin*2)); //set the pupd

	GpioA->outType |= (outDriveType<<pin);

}

void gpioGWrite(int pin, int state){
	if(state == 1){
		GpioG->outData |= 1<<pin;

	}
	else{
		GpioG->outData &= ~(1<<pin);
	}
}

void gpioWrite(GpioReg *gpio, int pin, int state){
	if(state == 1){
		gpio->outData |= 1<<pin;

	}
	else{
		gpio->outData &= ~(1<<pin);
	}
}

void setGpioAlternateFunc(GpioReg *gpio, int pin, int altFunc){

	if(pin < 7)
		gpio->altFuncLo |= (altFunc << (pin * 4));
	else
		gpio->altFuncHi |= (altFunc << ((pin-8) * 4));
//	gpio->pullType &= ~(3 << (pin *2));
}


int gpioARead(int pin){
	return (((GpioA->inData)&0x1) > 0);
}
int gpioRead(GpioReg *gpio, int pin){
	return (((gpio->inData)&(0x1<<pin)) > 0);
}
void gpioToggle(GpioReg *gpio, int pin){
	gpio->outData ^= (1<<pin);
}
