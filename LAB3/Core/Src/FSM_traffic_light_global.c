/*
 * FSM_traffic_light_global.c
 *
 *  Created on: Nov 2, 2023
 *      Author: TrongAnh
 */

#ifndef SRC_FSM_TRAFFIC_LIGHT_GLOBAL_C_
#define SRC_FSM_TRAFFIC_LIGHT_GLOBAL_C_

#include "FSM_traffic_light_global.h"
#include "button_reading.h"
#include "FSM_traffic_light_mode_1.h"
#include "display_7seg.h"
#include "main.h"
#include "software_timer.h"

int FSM_STATUS = INIT;
int valueSetting = 0;
int BLINKY_LED_STATUS = INIT;
//
//This function is used to blink the LED with frequency 2HZ when on MODE2->4 (editing it)
//Param:
//		int LED: the LED will be blinked ( RED, YELLOW, GREEN)

void blinkyLed(int LED) {
	switch(BLINKY_LED_STATUS){
	case INIT:
		// turn off all led
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin | LED_YELLOW_1_Pin |LED_GREEN_1_Pin
						|LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin, OFF);

		if (LED == RED) BLINKY_LED_STATUS = LED;
		if (LED == GREEN) BLINKY_LED_STATUS = GREEN;
		if (LED == YELLOW) BLINKY_LED_STATUS = YELLOW;
		setTimer4(250); // 2Hz
		break;
	case RED:
		if (timer4_flag == 1)
		{
			setTimer4(250);
			HAL_GPIO_TogglePin(GPIOA, LED_RED_1_Pin | LED_RED_2_Pin);
		}
		break;

	case YELLOW:
		if (timer4_flag == 1)
		{
			setTimer4(250);
			HAL_GPIO_TogglePin(GPIOA, LED_YELLOW_1_Pin| LED_YELLOW_2_Pin);
		}
		break;

	case GREEN:
		if (timer4_flag == 1)
		{
			setTimer4(250);
			HAL_GPIO_TogglePin(GPIOA, LED_GREEN_1_Pin | LED_GREEN_2_Pin);
		}
		break;

	default:
		break;
	}
}
void FSMTrafficLightGlobalRun(void)
{
	switch(FSM_STATUS){
		case INIT:
		FSM_STATUS = MODE1;
		updateBufferWithMode(FSM_STATUS);
		displaySegment();
		break;
		case MODE1:
			trafficLightRun();
			updateBufferWithMode(FSM_STATUS);
			displaySegment();

			if (isButton1Pressed()) {
				FSM_STATUS = MODE2;
				valueSetting = timeRed;
				BLINKY_LED_STATUS = INIT;
			}
			break;
		case MODE2:
			blinkyLed(RED);
			updateBufferWithMode(FSM_STATUS);
			displaySegment();
			if (isButton1Pressed()) {
				FSM_STATUS = MODE3;
				valueSetting = timeYellow;
				BLINKY_LED_STATUS = INIT;
			}
			else if (isButton2Pressed()){
				valueSetting++;
				if (valueSetting > 99)
					valueSetting = 1;
			}
			else if (isButton3Pressed()) {
				timeRed = valueSetting;
			}
			break;
		case MODE3:
			blinkyLed(YELLOW);
			updateBufferWithMode(FSM_STATUS);
			displaySegment();
			if (isButton1Pressed()) {
				FSM_STATUS = MODE4;
				valueSetting = timeGreen;
				BLINKY_LED_STATUS = INIT;
			}
			else if (isButton2Pressed()){
				valueSetting++;
				if (valueSetting > 99)
					valueSetting = 1;
			}
			else if (isButton3Pressed()) {
				timeYellow = valueSetting;
			}

			break;
		case MODE4:
			blinkyLed(GREEN);
			updateBufferWithMode(FSM_STATUS);
			displaySegment();
			if (isButton1Pressed()) {
				FSM_STATUS = MODE1;
			}
			else if (isButton2Pressed()){
				valueSetting++;
				if (valueSetting > 99)
					valueSetting = 1;
			}
			else if (isButton3Pressed()) {
				timeGreen = valueSetting;
			}
			break;
		default:
			break;
	}
}


#endif /* SRC_FSM_TRAFFIC_LIGHT_GLOBAL_C_ */
