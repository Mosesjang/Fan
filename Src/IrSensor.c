/*
 * IrSensor.c
 *
 *  Created on: May 24, 2026
 *      Author: jangm
 */
#include <stdint.h>
#include "uart.h"
#include "LED.h"
#include "motor.h"

					//define//
// clock
#define AHB1_RCC   (*(volatile uint32_t*)0x40023830) // for PC3
#define APB1_RCC   (*(volatile uint32_t*)0x40023840)//
#define APB2_RCC   (*(volatile uint32_t*)0x40023844)
// pinMode
#define GPIO_MODER (*(volatile uint32_t*)0x40020800)
#define GPIO_PUPDR (*(volatile uint32_t*)0x4002080C)
//SYSCFG
#define SYSCFG_EXTICR1 (*(volatile uint32_t*)0x40013808) // tell which port we are using
#define EXTI_RTSR      (*(volatile uint32_t*)0x40013C08)
#define EXTI_FTSR      (*(volatile uint32_t*)0x40013C0C)
#define EXTI_IMR       (*(volatile uint32_t*)0x40013C00)
#define EXTI_PR        (*(volatile uint32_t*)0x40013C14)
#define NVIC_ISER0     (*(volatile uint32_t*)0xE000E100)



//Initiate
void irInit(){
	AHB1_RCC |= (1 << 2); //turn gpioC register on
	APB2_RCC |= (1 << 14); // ENABLE SYSCFG
	//pinMode
	GPIO_PUPDR &= ~(3 << 6); // clear
	GPIO_PUPDR |=  (1 << 6); // set pull-up
	GPIO_MODER &= ~ (3 << 6);
	//
	SYSCFG_EXTICR1 &= ~(0xF << 12); // clear first!
	SYSCFG_EXTICR1 |=  (0x2 << 12); // then set PC!
	EXTI_FTSR |= (1 << 3);
	EXTI_IMR |= (1 << 3);
	NVIC_ISER0 |= (1 << 9);

}


void EXTI3_IRQHandler(void){

        setFanState(0);  // turn on at full speed!

    EXTI_PR |= (1 << 3);
}
