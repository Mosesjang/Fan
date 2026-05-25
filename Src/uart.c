/*
 * uart.c
 *
 *  Created on: May 21, 2026
 *      Author: jangm
 */
// clock

#include <stdint.h>
#include "uart.h"

#define APB1_RCC (*(volatile uint32_t*)0x40023840)
#define AHB1_RCC (*(volatile uint32_t*)0x40023830)
// PinMode
#define MODER (*(volatile uint32_t*)0x40020000)
#define AFLR (*(volatile uint32_t*)0x40020020)
// Uart
#define USART_CR1 (*(volatile uint32_t*)0x4000440C)
#define USART_BRR (*(volatile uint32_t*)0x40004408)
#define USART_SR (*(volatile uint32_t*)0x40004400)
#define USART_DR (*(volatile uint32_t*)0x40004404)

uint32_t uartInit(){
	//ENABLE CLOCK
	APB1_RCC |= (1 << 17);
	AHB1_RCC |= (1 << 0);
	//SET PIN MODE
	MODER &= ~(3 << 4);
	MODER |= (2 << 4);
	AFLR &= ~(0xF << 8);
	AFLR |= (7 << 8);
	// Baud rate
	USART_BRR = 1667;
	//UART
	USART_CR1 |= (1 << 13);// uart enable
	USART_CR1 |= (1 << 3);// enable transmister

	return 0;
}

void uartSendChar(char c){

	// SR
	while(!(USART_SR & (1 << 7 ))){} // do nothing when TXE is 0 cause it is busy.
	//DR
	USART_DR= c;

}

void sendUartString(char *str){ // it takes input strings and store them their addresses.
	while(*str != '\0'){		// while the thing in the first address is doesn't equal to new line-
		uartSendChar(*str);		// print it.
		str++;					//move to the next address/
	}
}

char hexDigitToChar(uint32_t bins){
	if(bins <= 9){
		bins = bins + 48; // adding 48 to number less than 10 will give you the ASCII value corresponding to the letter or number in hex.
	}
	else{
		bins = bins + 55;
	}
	char character = bins;
	return character;
}

void extractHex(uint32_t input){
	int started = 0; // L77

	for(int x = 28; x >= 0; x = x - 4){// this shift x 4bits so we can check it
	uint32_t temp = (input >> x) & 0xF;// we shift our input to the msf position then extract it
	// 	 printf("%b\n", temp);
		char character = hexDigitToChar(temp); // this convert our number to char
		//Removing unwanted zeros from the print
		if(temp != 0){started = 1;}// it works cause in the second loop even when temp is zero nothing happens started is still 1
		if(started){
			uartSendChar(character);// this print it on putty}
		}
	}

	uartSendChar('\r');
	uartSendChar('\n');
}
