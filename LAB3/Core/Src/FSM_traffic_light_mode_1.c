/*
 * FSM_traffic_light.c
 *
 *  Created on: Nov 2, 2023
 *      Author: TrongAnh
 */

#include "FSM_traffic_light_mode_1.h"
#include "software_timer.h"
#include "main.h"
#include "display_7seg.h"

int led1_status = INIT;
int led2_status = INIT;
int timeRed = 5;
int timeYellow = 2;
int timeGreen = 3;
int counter_first_2SEG = 5;
int counter_latter_2SEG = 3;

// Function of mode 1: traffic Light system will run automatically
void trafficLightRun(void){
	switch (led1_status){
		case INIT:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, OFF);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, OFF);
			led1_status = RED;
			counter_first_2SEG = timeRed;
			setTimer1(1000);
			break;

		case RED:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, ON);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, OFF);

//			HAL_GPIO_TogglePin(TEST_LED_GPIO_Port, TEST_LED_Pin);
			if (timer1_flag == 1){
//				HAL_GPIO_TogglePin(TEST_LED_GPIO_Port, TEST_LED_Pin);
				setTimer1(1000);
				counter_first_2SEG--;
				if (counter_first_2SEG <= 0){
					led1_status = GREEN;
					counter_first_2SEG = timeGreen;
				}
			}
			break;

		case YELLOW:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, OFF);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, ON);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, OFF);

			if (timer1_flag == 1){
				setTimer1(1000);
				counter_first_2SEG--;
				if (counter_first_2SEG <= 0){
					led1_status = RED;
					counter_first_2SEG = timeRed;
				}
			}
			break;

		case GREEN:
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, OFF);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, OFF);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, ON);

			if (timer1_flag == 1){
				setTimer1(1000);
				counter_first_2SEG--;
				if (counter_first_2SEG <= 0){
					led1_status = YELLOW;
					counter_first_2SEG = timeYellow;
				}
			}
			break;

		default:
			break;
	}

	switch(led2_status){
		case INIT:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, OFF);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, OFF);
			led2_status = GREEN;
			counter_latter_2SEG = timeGreen;
			setTimer2(1000);
			break;

		case RED:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, ON);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, OFF);

			if (timer2_flag == 1){
				setTimer2(1000);
				counter_latter_2SEG--;

				if (counter_latter_2SEG <= 0){
					led2_status = GREEN;
					counter_latter_2SEG = timeGreen;
				}
			}
			break;

		case YELLOW:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, OFF);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, ON);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, OFF);

			if (timer2_flag == 1){
				setTimer2(1000);
				counter_latter_2SEG--;
				if (counter_latter_2SEG <= 0){
					led2_status = RED;
					counter_latter_2SEG = timeRed;
				}
			}
			break;

		case GREEN:
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, OFF);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, OFF);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, ON);

			if (timer2_flag == 1){
				setTimer2(1000);
				counter_latter_2SEG--;
				if (counter_latter_2SEG <= 0){
					led2_status = YELLOW;
					counter_latter_2SEG = timeYellow;
				}
			}
			break;

		default:
			break;
	}
}
