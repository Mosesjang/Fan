#include <stdint.h>
#include "button.h"
#include "led.h"
#include "uart.h"
//define clock
#define AHB1_RCC 	(*(volatile uint32_t*)0x40023830)
#define APB1_RCC 	(*(volatile uint32_t*)0x40023840)
//define pinMode
#define GPIOA_MODER (*(volatile uint32_t*)0x40020000)
#define AFHR		(*(volatile uint32_t*)0x40020024)

//DEFINE TIMER
#define TIM2_PSC        (*(volatile uint32_t*)0x40000028)
#define TIM2_ARR        (*(volatile uint32_t*)0x4000002C)
#define TIM2_CCR1       (*(volatile uint32_t*)0x40000034)
#define TIM2_CCMR1      (*(volatile uint32_t*)0x40000018)
#define TIM2_CR1        (*(volatile uint32_t*)0x40000000)
#define TIM2_CCER       (*(volatile uint32_t*)0x40000020)

void pwmInit(){
	//enable clock
	AHB1_RCC |= (1 << 0);
	APB1_RCC |= (1 << 0);
	//set pinMode
	GPIOA_MODER &= ~(3 << 30);
	GPIOA_MODER |=  (2 << 30);
	AFHR &= ~(0xF << 28);
	AFHR |= (0x1 << 28);
	//timer setup
	TIM2_PSC = 15;
	TIM2_ARR = 1000;

	TIM2_CCMR1 &= ~(0xFF << 0);
	TIM2_CCMR1 |= (0x68 << 0);
	TIM2_CR1 |= (1 << 7);
	TIM2_CR1 |= (1 << 0);
	TIM2_CCER |= (1 << 0);
}


void stateMachine(uint32_t newState){
	switch(newState){
	case 0:
		TIM2_CCR1 = 0;
		LedOff(10);
		LedOff(11);
		LedOff(12);
		break;
	case 1:
		TIM2_CCR1 = 500;
		LedOn(10);
		LedOff(11);
		LedOff(12);
		break;
	case 2:
		TIM2_CCR1 = 750;
		LedOff(10);
		LedOn(11);
		LedOff(12);
		break;
	case 3:
		TIM2_CCR1 = 950;
		LedOff(10);
		LedOff(11);
		LedOn(12);
		break;
	}
}
