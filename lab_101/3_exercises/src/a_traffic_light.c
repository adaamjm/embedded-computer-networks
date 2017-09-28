/*
 * a_traffic_lights.c
 *
 * this is the main application skeleton for the student exercises in task 3
 *
 */

// include the hal drivers
#include "stm32f7xx_hal.h"

// include the shu bsp libraries for the stm32f7 discovery board
#include "pinmappings.h"
#include "clock.h"
#include "gpio.h"

// map the led to GPIO PA8
gpio_pin_t led0 = {PI_1, GPIOI, GPIO_PIN_1};
gpio_pin_t led1 = {PB_14, GPIOB, GPIO_PIN_14};
gpio_pin_t led2 = {PB_15, GPIOB, GPIO_PIN_15};

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
  
  // initialise the gpio pin
  init_gpio(led0, OUTPUT);
	init_gpio(led1, OUTPUT);
	init_gpio(led2, OUTPUT);
  
  // loop forever ...
  while(1)
  {
    // toggle the led on the gpio pin
    toggle_gpio(led0);	//	RED ON
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		toggle_gpio(led1);	//	ORANGE ON
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		toggle_gpio(led0);	//	RED OFF
		toggle_gpio(led1);	//	ORANGE OFF
		toggle_gpio(led2);	//	GREEN ON
		HAL_Delay(10000);		//	WAIT 10 SECONDS
		toggle_gpio(led2);	//	GREEN OFF
		toggle_gpio(led1);	//	ORANGE ON
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		toggle_gpio(led0);	//	RED ON
		toggle_gpio(led1);	//	ORANGE OFF
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		toggle_gpio(led0);	//	RED OFF
  }
}
