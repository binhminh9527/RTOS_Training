/*----------------------------------------------------------------------------
	
	Designers Guide to the Cortex-M Family
	CMSIS RTOS Delay Example

*----------------------------------------------------------------------------*/
#include "STM32F10x.h"
#include <cmsis_os.h>
#include "Board_LED.h"

void delay (unsigned int count)
{
unsigned int index;
	
	for(index =0;index<count;index++)
	{
		;
	}
}

/*----------------------------------------------------------------------------
  Task 1 'ledOn': switches the LED on
 *---------------------------------------------------------------------------*/
void ledOn (void const *argument) 
{
	for (;;) 
	{
		LED_On(1);                          //Toggle LED 1 with a delay of 500 ms
		osDelay(500);
		LED_Off(1);
		osDelay(500);
	}
}

/*----------------------------------------------------------------------------
  Task 2 'ledOff': switches the LED off
 *---------------------------------------------------------------------------*/
void ledOff (void const *argument) 
{
	for (;;) 
	{
    LED_On(2);                          // Toggle LED2 with a delay of 500 ms
		osDelay(100);
		LED_Off(2);
		osDelay(100);
	}
}

osThreadId main_ID;	
osThreadDef(ledOff, osPriorityNormal, 1, 0);
osThreadDef(ledOn, osPriorityNormal, 1, 0);
/*----------------------------------------------------------------------------
  Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void) 
{
	osKernelInitialize ();                    // initialize CMSIS-RTOS

	LED_Initialize ();
	osThreadCreate(osThread(ledOff), NULL);		//Create the LED threads
	osThreadCreate(osThread(ledOn), NULL);
	
	osKernelStart ();                         // start thread execution 
	
	while(1)
	{
		;
	}
}
