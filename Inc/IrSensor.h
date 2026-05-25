/*
 * IrSensor.h
 *
 *  Created on: May 24, 2026
 *      Author: jangm
 */

#ifndef IRSENSOR_H_
#define IRSENSOR_H_

void irInit();
void timerInit();
extern volatile uint32_t irCode;
extern volatile uint8_t irReady;


#endif /* IRSENSOR_H_ */
