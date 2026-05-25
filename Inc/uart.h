/*
 * uart.h
 *
 *  Created on: May 21, 2026
 *      Author: jangm
 */

#ifndef UART_H_
#define UART_H_

uint32_t uartInit();
void uartSendChar(char c);
void sendUartString(char *str);
char hexDigitToChar(uint32_t bins);
void extractHex(uint32_t input);

#endif /* UART_H_ */
