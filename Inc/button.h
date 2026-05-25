/*
 * button.c
 *
 *  Created on: May 7, 2026
 *      Author: jangm
 */

#ifndef BUTTON_C_
#define BUTTON_C_

void button_Init();
int readButton1();
int readButton2();
int readButton3();
uint32_t checkButton(uint32_t current, uint32_t *previous);


#endif /* BUTTON_C_ */
