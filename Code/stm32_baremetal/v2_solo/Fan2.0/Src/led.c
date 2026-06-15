#include <stdint.h>

//Define our clock register address
#define AHB1_RCC    (*(volatile uint32_t*)0x40023830)
//Define our PinMode register address
#define GPIOC_MODER (*(volatile uint32_t*)0x40020800) //
#define GPIOC_ODR   (*(volatile uint32_t*)0x40020814)

void Led_Init(){
	// turn on bus clock for GPIO C
	AHB1_RCC |= (1 << 2);
	//set pinMode to output
	GPIOC_MODER &= ~(3 << 20); //first clear just in case one or both bit are on
	GPIOC_MODER |=  (1 << 20); // Set pin PC10 to output.
	GPIOC_MODER &= ~(3 << 22); // PC11
	GPIOC_MODER |=  (1 << 22); // PC11
	GPIOC_MODER &= ~(3 << 24); // PC12
	GPIOC_MODER |=  (1 << 24); // PC12
}

void LedOn(uint32_t ledPin){
	GPIOC_ODR |= (1 << ledPin);
}

void LedOff(uint32_t ledPin){
	GPIOC_ODR &= ~(1 << ledPin);
}
