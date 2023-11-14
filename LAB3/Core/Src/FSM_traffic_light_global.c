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

int FSM_STATUS = INIT;
int valueSetting = 0;

void blinkyLed(int LED) {
	HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin | LED_GREEN_2_Pin | LED_RED_1_Pin | LED_RED_2_Pin
			|LED_YELLOW_1_Pin | LED_YELLOW_2_Pin, OFF);
}
void FSMTrafficLightGlobalRun(void)
{
	switch(FSM_STATUS){
		case INIT:
		FSM_STATUS = MODE1;
		updateBufferWithMode(FSM_STATUS);
		displaySegment();
		case MODE1:
			trafficLightRun();
			updateBufferWithMode(FSM_STATUS);
			displaySegment();

			if (isButton1Pressed()) {
				FSM_STATUS = MODE2;
				valueSetting = timeRed;
			}
			break;
		case MODE2:
			blinkyLed(RED);
			updateBufferWithMode(FSM_STATUS);
			displaySegment();
			if (isButton1Pressed()) {
				FSM_STATUS = MODE3;
				valueSetting = timeYellow;
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
