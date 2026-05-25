#include <stdint.h>
#include "LED.h"

//clock
#define ABH1 (*(volatile uint32_t *)0x40023830)
#define APB1 (*(volatile uint32_t*)0x40023840)
//MODE
#define GPIOA (*(volatile uint32_t*)0x40020000)
#define AFRH  (*(volatile uint32_t*)0x40020024)
//TIM2
#define PSC   (*(volatile uint32_t*)0x40000028)
#define ARR   (*(volatile uint32_t*)0x4000002C)
#define CCR1  (*(volatile uint32_t*)0x40000034)
#define CCMR1 (*(volatile uint32_t*)0x40000018)
#define CCER  (*(volatile uint32_t*)0x40000020)
#define CR1   (*(volatile uint32_t*)0x40000000)

void pwmInit(){
// Enable clock
	ABH1 |= (1 << 0);
	APB1 |= (1 << 0);
// Set MODE
	GPIOA &= ~(3 << 30);
	GPIOA |=  (2 << 30);
	AFRH  &= ~(0xF << 28);
	AFRH |= (0x1 << 28);
// Configurations
	PSC = 15;
	ARR = 999;

// PWM mode
    CCMR1 &= ~(0xFF << 0);
    CCMR1 |=  (0x68 << 0);
// Enable output
    CCER |= (1 << 0);
// Enable Timer and
    CR1 |= (1 << 7);
    CR1 |= (1 << 0);

}

// Instead of Toggle_Led, create:
void setFanState(uint8_t newState){
    switch(newState){
        case 0: // OFF
        	CCR1 = 0;
        	LedOff(10);
        	LedOff(11);
        	LedOff(12);
            // turn off all LEDs
            break;
        case 1: // Speed 1
        	CCR1 = 500;
        	LedOn(10);
        	LedOff(11);
        	LedOff(12);
            // LED1 ON, others OFF
            break;
        case 2: // Speed 2
        	CCR1 = 750;
        	LedOff(10);
        	LedOn(11);
        	LedOff(12);
            // LED2 ON, others OFF
            break;
        case 3: // Speed 3
        	CCR1 = 950;
        	LedOff(10);
        	LedOff(11);
        	LedOn(12);
            // LED3 ON, others OFF
            break;
    }
}
