/*
 * LED.h
 *
 *  Created on: May 6, 2026
 *      Author: jangm
 */

#ifndef LED_H_
#define LED_H_


void Led_Init(void);
void delay(void);
int Toggle_Led(uint32_t buttonState, uint32_t ledOn, uint32_t ledOff1, uint32_t ledOff2, uint32_t index);
void LedOn(volatile uint32_t ledNum);
void LedOff(volatile uint32_t ledNum);

#endif /* LED_H_ */
