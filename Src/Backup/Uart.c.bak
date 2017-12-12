/*
 * Uart.c
 *
 *  Created on: Dec 12, 2017
 *      Author: user
 */
#include <math.h>
#include <stm32f4xx.h>
#include "Uart.h"


/**
 * this function helps to calculate value to put in BRR reg by given baudrate
 */
void setBaudRate(UsartReg *uart, uint32_t baudRate, int overSampling){
	//FIXME ignore fractional part
	uint32_t usartDiv = (HAL_RCC_GetPCLK2Freq()/(8 * (2-overSampling) * baudRate));
	uint32_t mantissa = round(usartDiv);

	MODIFY_REG(uart->BRR, USART_BRR_DIV_Mantissa_Msk, mantissa << USART_BRR_DIV_Mantissa_Pos);
//	usartDiv = (usartDiv << 4) & 0xf;
	MODIFY_REG(uart->BRR, USART_BRR_DIV_Fraction_Msk, (9) << USART_BRR_DIV_Fraction_Pos);

}

void enableAndConfParamUsart(UsartReg *usart, int wordLength, int numStopBit, int overSampling, int baudRate){
	//enable usart by writing UE
	SET_BIT(usart->CR1, USART_CR1_UE);
	//define word length
	CLEAR_BIT(usart->CR1, USART_CR1_M);
	SET_BIT(usart->CR1, wordLength << USART_CR1_M_Pos);
	//program number of stop bit
	MODIFY_REG(usart->CR2, USART_CR2_STOP_Msk, numStopBit << USART_CR2_STOP_Pos);
	//program overSampling
	CLEAR_BIT(usart->CR1, USART_CR1_OVER8);
	SET_BIT(usart->CR1, overSampling << USART_CR1_OVER8_Pos);
	//calculate and set the baudrate
	setBaudRate(usart, baudRate, 0);
}

void configureParityBit(UsartReg *usart, int parityEn, int paritySel){
	//enable parity control bit
	CLEAR_BIT(usart->CR1, USART_CR1_PCE);
	CLEAR_BIT(usart->CR1, USART_CR1_PS);
	if(parityEn == 1){
		SET_BIT(usart->CR1, USART_CR1_PCE);
		SET_BIT(usart->CR1, paritySel << USART_CR1_PS_Pos);
	}

}

void uartSendBytes(UsartReg *usart, uint8_t *byteToSend, uint32_t size){
	//set the TE bit to enable transmission
	SET_BIT(usart->CR1, USART_CR1_TE);
	while(size-- >0){
		//write data to be send in DR reg
		WRITE_REG(usart->DR, *(byteToSend++));
		while(READ_BIT(usart->SR, USART_SR_TXE) == 0);
	}
	while(READ_BIT(usart->SR, USART_SR_TC) == 0);

}

int uartReceiveUntilEnter(UsartReg *usart, char *rxBuffer){
	//set the RE bit to enable reception
	SET_BIT(usart->CR1, USART_CR1_RE);
	*(rxBuffer) = uartReceiveByte(usart);
	int count = 0;
	while(*(rxBuffer) != 0xd){
		count ++;
		rxBuffer ++;
		*(rxBuffer) = uartReceiveByte(usart);
	}
	*(rxBuffer) = 0;
	return count;
}

uint8_t uartReceiveByte(UsartReg *usart){
	while(READ_BIT(usart->SR, USART_SR_RXNE) == 0);

	return (uint8_t)usart->DR;
}

