#include <stdint.h>
#include <stdio.h>
#include "button.h"


#define clk  (*(volatile uint32_t *)0x40023830)
#define pinMode  (*(volatile uint32_t *)0x40020000)
#define buttonIdr  (*(volatile uint32_t *)0x40020010)
#define Pull (*(volatile uint32_t *)0x4002000C)


void button_Init(){

	//Enable gpioA clock
	clk |= (1 << 0);
	//Clear gpioA mode reg
	pinMode &= ~(3 << 2);
	pinMode &= ~(3 << 0);
	pinMode &= ~(3 << 8);
	//Set PA1 to input 00

}


int readButton1(){

	uint32_t val = buttonIdr;

	if(val & (1 << 4)){
		return 1;
	}
	else{
		return 0;
	}
}

int readButton2(){

	uint32_t val = buttonIdr;

	if(val & (1 << 0)){
		return 1;
	}
	else{
		return 0;
	}
}

int readButton3(){

	uint32_t val = buttonIdr;

	if(val & (1 << 1)){
		return 1;
	}
	else{
		return 0;
	}
}

uint32_t checkButton(uint32_t current, uint32_t *previous){
	uint32_t pressed = (current == 1 && *previous == 0);
	*previous = current;
	return pressed;
}
