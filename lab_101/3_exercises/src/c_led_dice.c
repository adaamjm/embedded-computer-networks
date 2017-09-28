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
#include "random_numbers.h"

/*
*				A						B
*				
*				C			D			E
*
*				F						G
*
*				ONE		= D
*				TWO		= A, G
* 			THREE	= A, D, G
* 			FOUR	= A, B, F, G
* 			FIVE	= A, B, D, F, G
*				SIX		= A, B, C, E, F, G
*/


gpio_pin_t led0 = {PI_1, GPIOI, GPIO_PIN_1};		//	A
gpio_pin_t led1 = {PB_14, GPIOB, GPIO_PIN_14};	//	B
gpio_pin_t led2 = {PB_15, GPIOB, GPIO_PIN_15};	//	C
gpio_pin_t led3 = {PB_9, GPIOB, GPIO_PIN_9};		//	D
gpio_pin_t led4 = {PA_15, GPIOA, GPIO_PIN_15};	//	E
gpio_pin_t led5 = {PA_8, GPIOA, GPIO_PIN_8};		//	F
gpio_pin_t led6 = {PI_3, GPIOI, GPIO_PIN_3};		//	G

gpio_pin_t but = {PB_8, GPIOB, GPIO_PIN_8};		//	BUTTON

int prnd; // Store random number

// this is the main method
int main()
{
  // we need to initialise the hal library and set up the SystemCoreClock 
  // properly
  HAL_Init();
  init_sysclk_216MHz();
	init_random();
  
  // initialise the gpio pins
  init_gpio(led0, OUTPUT);
	init_gpio(led1, OUTPUT);
	init_gpio(led2, OUTPUT);
	init_gpio(led3, OUTPUT);
	init_gpio(led4, OUTPUT);
	init_gpio(led5, OUTPUT);
	init_gpio(led6, OUTPUT);
	init_gpio(but, INPUT);
  
  // loop forever ...
  while(1)
  {
		// RESET ALL PINS
		write_gpio(led0, LOW);
		write_gpio(led1, LOW);
		write_gpio(led2, LOW);
		write_gpio(led3, LOW);
		write_gpio(led4, LOW);
		write_gpio(led5, LOW);
		write_gpio(led6, LOW);
		
		//	generate random number
		uint32_t rnd = (get_random_int() % 6) + 1;
		
		if (prnd == rnd) {
			uint32_t rnd = (get_random_int() % 6) + 1;
		}
		else {
			if (rnd == 1){
				write_gpio(led3, HIGH);
			}
			if (rnd == 2){
				write_gpio(led0, HIGH);
				write_gpio(led6, HIGH);
			}
			if (rnd == 3){
				write_gpio(led0, HIGH);
				write_gpio(led3, HIGH);
				write_gpio(led6, HIGH);
			}
			if (rnd == 4){
				write_gpio(led0, HIGH);
				write_gpio(led1, HIGH);
				write_gpio(led5, HIGH);
				write_gpio(led6, HIGH);
			}
			if (rnd == 5){
				write_gpio(led0, HIGH);
				write_gpio(led1, HIGH);
				write_gpio(led3, HIGH);
				write_gpio(led5, HIGH);
				write_gpio(led6, HIGH);
			}
			if (rnd == 6){
				write_gpio(led0, HIGH);
				write_gpio(led1, HIGH);
				write_gpio(led2, HIGH);
				write_gpio(led4, HIGH);
				write_gpio(led5, HIGH);
				write_gpio(led6, HIGH);
			}
		}
		prnd = rnd;
		HAL_Delay(1000);
  }
}
