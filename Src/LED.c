#include <stdint.h>
#include "LED.h"
#include "button.h"
#include "motor.h"
// port to use: PC10, PC12, PC11
#define clk (*(volatile uint32_t*)0x40023830)
#define ledMode (*(volatile uint32_t*)0x40020800)
#define ledODR (*(volatile uint32_t*)0x40020814)


void Led_Init(void){
	clk |= (1 << 2);
	ledMode &= ~(3 << 20); // led1
	ledMode |= (1 << 20);
	ledMode &= ~(3 << 22); // led2
	ledMode |= (1 << 22);
	ledMode &= ~(3 << 24); // led3
	ledMode |= (1 << 24);
}

void LedOn(volatile uint32_t ledNum){
	ledODR |= (1 << ledNum);
}

void LedOff(volatile uint32_t ledNum){
	ledODR &= ~(1 << ledNum);
}
