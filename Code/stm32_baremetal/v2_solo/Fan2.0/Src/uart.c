#include <stdint.h>

// define clock
#define AHB1_RCC    (*(volatile uint32_t*)0x40023830)
#define APB1_RCC    (*(volatile uint32_t*)0x40023840)
// pinMode
#define GPIOA_MODER (*(volatile uint32_t*)0x40020000)
#define AFRL   		(*(volatile uint32_t*)0x40020020)
// Define uart registers
#define UART_BRR (*(volatile uint32_t*)0x40004408)
#define UART_CR1 (*(volatile uint32_t*)0x4000440C)
#define UART_SR  (*(volatile uint32_t*)0x40004400)
#define UART_DR  (*(volatile uint32_t*)0x40004404)


void uartInit(){
//	enalbe clock
	AHB1_RCC |= (1 << 0);
	APB1_RCC |= (1 << 17);
//pinMode
    GPIOA_MODER &= ~(3 << 4);  // clear PA2
    GPIOA_MODER |=  (2 << 4);  // AF mode
	AFRL &= ~(0xF << 8);
	AFRL |= (0x7 << 8);
//  configur uart
	UART_BRR = 1667;
	UART_CR1 |= (1 << 3);
	UART_CR1 |= (1 << 13);
}

void printData(char c){
	while(!(UART_SR & (1 << 7)));
	UART_DR = c;
}

void printString(char *string){
	while(*string != '\0'){
		printData(*string);
		string++;
	}
}
