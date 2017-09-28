/*
 * b_traffic_lights.c
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

// TL_SET1: map the leds to GPIOs
gpio_pin_t led0 = {PI_1, GPIOI, GPIO_PIN_1};		//	RED
gpio_pin_t led1 = {PB_14, GPIOB, GPIO_PIN_14};	//	ORANGE
gpio_pin_t led2 = {PB_15, GPIOB, GPIO_PIN_15};	//	GREEN

// TL_SET2: map the leds to GPIOs
gpio_pin_t led3 = {PI_2, GPIOI, GPIO_PIN_2};		//	RED
gpio_pin_t led4 = {PA_15, GPIOA, GPIO_PIN_15};	//	ORANGE
gpio_pin_t led5 = {PA_8, GPIOA, GPIO_PIN_8};	//	GREEN

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
	init_gpio(led3, OUTPUT);
	init_gpio(led4, OUTPUT);
	init_gpio(led5, OUTPUT);
  
  // loop forever ...
  while(1)
  {
		//	PHASE 1
		toggle_gpio(led0);	//	TL_SET1: RED ON
		toggle_gpio(led5);	//	TL_SET2: GREEN ON
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		
		//	PHASE 2
		toggle_gpio(led4);	//	TL_SET2: ORANGE ON
		toggle_gpio(led5);	//	TL_SET2: GREEN OFF
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		
		//	PHASE 3
		toggle_gpio(led4);	//	TL_SET2: ORANGE OFF
		toggle_gpio(led3);	//	TL_SET2: RED ON
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		
		//	PHASE 4
		toggle_gpio(led2);	//	TL_SET1: GREEN ON
		toggle_gpio(led0);	//	TL_SET1: RED OFF
		HAL_Delay(2000);		//	WAIT 2 SECONDS

		//	PHASE 5
		toggle_gpio(led2);	//	TL_SET1: GREEN OFF
		toggle_gpio(led1);	//	TL_SET1: ORANGE ON
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		
		//	PHASE 6
		toggle_gpio(led0);	//	TL_SET1: RED ON
		toggle_gpio(led1);	//	TL_SET1: ORANGE OFF
		HAL_Delay(2000);		//	WAIT 2 SECONDS
		
		//	RESET LEDS
		toggle_gpio(led0);	//	TL_SET1: RED OFF
		toggle_gpio(led3);	//	TL_SET2: RED OFF
  }
}
