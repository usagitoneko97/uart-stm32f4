/*
 * Uart.h
 *
 *  Created on: Dec 12, 2017
 *      Author: user
 */

#ifndef UART_H_
#define UART_H_

#define USART1_BASE_ADDR	0x40011000
#define Usart1				((UsartReg*)(USART1_BASE_ADDR))

#define OVER8_EN		1
#define OVER16_EN	    0

#define USART_WORDLENGTH_8DATA	0
#define USART_WORDLENGTH_9DATA	1

#define USART_STOP_ONE				0
#define USART_STOP_HALF				1
#define USART_STOP_TWO				2
#define USART_STOP_ONE_AND_HALF		3

#define USART_PAR_EN				1
#define USART_PAR_DIS				0

#define USART_PAR_EVEN				0
#define USART_PAR_ODD				1

typedef struct
{
  volatile uint32_t SR;         /*!< USART Status register,                   Address offset: 0x00 */
  volatile uint32_t DR;         /*!< USART Data register,                     Address offset: 0x04 */
  volatile uint32_t BRR;        /*!< USART Baud rate register,                Address offset: 0x08 */
  volatile uint32_t CR1;        /*!< USART Control register 1,                Address offset: 0x0C */
  volatile uint32_t CR2;        /*!< USART Control register 2,                Address offset: 0x10 */
  volatile uint32_t CR3;        /*!< USART Control register 3,                Address offset: 0x14 */
  volatile uint32_t GTPR;       /*!< USART Guard time and prescaler register, Address offset: 0x18 */
} UsartReg;

void setBaudRate(UsartReg *uart, uint32_t baudRate, int overSampling);
void enableAndConfParamUsart(UsartReg *usart, int wordLength, int numStopBit, int overSampling, int baudRate);
void uartSendBytes(UsartReg *usart, uint8_t *byteToSend, uint32_t size);
void configureParityBit(UsartReg *usart, int parityEn, int paritySel);

int uartReceiveUntilEnter(UsartReg *usart, char *rxBuffer);
uint8_t uartReceiveByte(UsartReg *usart);
#endif /* UART_H_ */
