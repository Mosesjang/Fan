

#include <stdint.h>
#include "button.h"
#include "led.h"

// Define clock
#define AHB1_RCC    (*(volatile uint32_t*)0x40023830)
// Define pinMode
#define GPIOA_MODER (*(volatile uint32_t*)0x40020000)
#define GPIOA_IDR   (*(volatile uint32_t*)0x40020010)


void buttonInit(){
	//enable bus clock
	AHB1_RCC |= (1 << 0);
	//set pinMode
	GPIOA_MODER &= ~(3 << 0); //PA0 CLEAR PIN
	GPIOA_MODER |=  (1 << 0); //PA0 SET TO INPUT
	GPIOA_MODER &= ~(3 << 2); //PA1 CLEAR PIN
	GPIOA_MODER |=  (1 << 2); //PA1 SET TO INPUT
	GPIOA_MODER &= ~(3 << 8); //PA4 CLEAR PIN
	GPIOA_MODER |=  (1 << 8); //PA4 SET TO INPUT

}

int readButton(uint32_t buttonPin){

	if(GPIOA_IDR & (1 << buttonPin)){
		return 1;
	}
	return 0;
}


uint32_t buttonPressed(uint32_t buttonNum, uint32_t *prevState){
	//solve for debounce
		uint32_t currentState = readButton(buttonNum);
		uint32_t pressed = (currentState == 1 && *prevState == 0);
		*prevState = currentState;
		 return pressed;

}

