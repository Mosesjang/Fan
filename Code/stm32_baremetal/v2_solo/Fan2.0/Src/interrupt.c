
//* interrupt.c
#include <stdint.h>
#include  "uart.h"

//Define clocks
#define AHB1_RCC         (*(volatile uint32_t*)0x40023830)
#define APB2_RCC         (*(volatile uint32_t*)0x40023844)
//Define pinMode
#define GPIOC_MODER 	 (*(volatile uint32_t*)0x40020800)
#define GPIOC_PUPDR	 	 (*(volatile uint32_t*)0x4002080C)
//Define pinMode
#define SYSCFG_EXTICR1   (*(volatile uint32_t*)0x40013808)
#define EXTI_FTSR		 (*(volatile uint32_t*)0x40013C0C)
#define EXTI_IMR         (*(volatile uint32_t*)0x40013C00)
#define EXTI_PR          (*(volatile uint32_t*)0x40013C14)
#define NVIC_ISER0		 (*(volatile uint32_t*)0xE000E100)


void interruptInit(){
	// enable clock
	AHB1_RCC |= (1 << 2);
	APB2_RCC |=	(1 << 14);
	// pinMode
	GPIOC_MODER &= ~(3 << 6);
	GPIOC_PUPDR &= ~(3 << 6);
	GPIOC_PUPDR	|=  (1 << 6);
	// Config interrupt
	SYSCFG_EXTICR1 &= ~(0xF << 12);
	SYSCFG_EXTICR1 |= (0x2 << 12);
	EXTI_FTSR |= (1 << 3);
	EXTI_IMR |= (1 << 3);
	NVIC_ISER0 |= (1 << 9);
}

void EXTI3_IRQHandler(void){

	printString("REMOTE PRESSED\r\n");

	EXTI_PR |= (1 << 3);
}
