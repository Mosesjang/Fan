
#include <stdint.h>
#include "led.h"
#include "button.h"
#include "motor.h"
#include "uart.h"
#include "IrSensor.h"

uint32_t previous1 = 0;
uint32_t previous2 = 0;
uint32_t previous3 = 0;
uint32_t fanState = 0;

int main(void)
{
	Led_Init();
	button_Init();
	pwmInit();
	uartInit();
	// irSensor
	irInit();
//	sendUartString("");

   while(1){

	   if(checkButton(readButton1(), &previous1)){
		   if(fanState == 0){
			   fanState = 1;
			   setFanState(fanState);
		   }
		   else{
			   fanState = 0;
			   setFanState(fanState);
		   }
	   }

	   if(checkButton(readButton2(), &previous2)){
		   if(fanState == 1 || fanState == 2 || fanState == 3){
			   fanState = 2;
			   setFanState(fanState);

		   }
		   else{
			   fanState = 0;

		   }
	   }

	   if(checkButton(readButton3(), &previous3)){
		   if(fanState == 1 || fanState == 2 || fanState == 3){
			   fanState = 3;
			   setFanState(fanState);
		   }
		   else{
			   fanState = 0;


		   }
	   }

   }


}
