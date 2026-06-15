//main.c

#include <stdint.h>
#include "led.h"
#include "button.h"
#include "motor.h"
#include "uart.h"
#include "interrupt.h"

int main(void)
{	static uint8_t buttonNum1 = 4;
	static uint8_t buttonNum2 = 0;
	static uint8_t buttonNum3 = 1;
	uint32_t previousState1 = 0;
	uint32_t previousState2 = 0;
	uint32_t previousState3 = 0;
	uint32_t fanState = 0;
	Led_Init();
	buttonInit();
	pwmInit();
	uartInit();
	interruptInit();


	while(1){
		if(buttonPressed(buttonNum1, &previousState1)){
			if(fanState == 0){
				fanState = 1;
				stateMachine(fanState);
			}
			else{
				fanState = 0;
				stateMachine(fanState);
				printString("off\r\n");
			}
		}

		if(buttonPressed(buttonNum2, &previousState2)){
			if(fanState == 1 || fanState == 2 || fanState == 3){
				fanState = 2;
				stateMachine(fanState);
			}

		}
		if(buttonPressed(buttonNum3, &previousState3)){
			if(fanState == 1 || fanState == 2  || fanState == 3){
				fanState = 3;
				stateMachine(fanState);
			}

		}

	}

}
