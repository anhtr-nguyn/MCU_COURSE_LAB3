/*
 * button_reading.c
 *
 *  Created on: Nov 2, 2023
 *      Author: TrongAnh
 */

#include "button_reading.h"
#include "main.h"
#include "software_timer.h"

struct ButtonType{
	int key0;
	int key1;
	int key2;
	int oldState;
	int flag;
};

//INIT 3 button
struct ButtonType button1 = { RELEASED,RELEASED, RELEASED, RELEASED, 0};
struct ButtonType button2 = { RELEASED,RELEASED, RELEASED, RELEASED, 0};
struct ButtonType button3 = { RELEASED,RELEASED, RELEASED, RELEASED, 0};
void getbutton1Value(void){
	button1.key2 = button1.key1;
	button1.key1 = button1.key0;
	button1.key0 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

	if (button1.key2 == button1.key1 && button1.key1 == button1.key0){
		if (button1.key2 != button1.oldState){
			button1.oldState = button1.key2;
			if (button1.key2 == PRESSED)
			{
				button1.flag = 1;
			}
		}
		else {
			// maybe long press, not need to handle
		}
	}
}

void getbutton2Value(void){
	button2.key2 = button2.key1;
	button2.key1 = button2.key0;
	button2.key0 = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);

	if (button2.key2 == button2.key1 && button2.key1 == button2.key0){
		if (button2.key2 != button2.oldState){
			button2.oldState = button2.key2;
			if (button2.key2 == PRESSED)
			{
				button2.flag = 1;
			}
		}
		else {
			// maybe long press, not need to handle
		}
	}
}

void getbutton3Value(void){
	button3.key2 = button3.key1;
	button3.key1 = button3.key0;
	button3.key0 = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

	if (button3.key2 == button3.key1 && button3.key1 == button3.key0){
		if (button3.key2 != button3.oldState){
			button3.oldState = button3.key2;
			if (button3.key2 == PRESSED)
			{
				button3.flag = 1;
			}
		}
		else {
			// maybe long press, not need to handle
		}
	}
}
//Function is used to check the button 1 is pressed or not
// Return:
//		1: pressed
//		2: released
int isButton1Pressed(void){
	if (button1.flag == 1)
	{
		button1.flag = 0;
		return 1;
	}
	else return 0;
}

//Function is used to check the button 2 is pressed or not
// Return:
//		1: pressed
//		2: released
int isButton2Pressed(void){
	if (button2.flag == 1){
		button2.flag = 0;
		return 1;
	}
	else return 0;
}

//Function is used to check the button 3 is pressed or not
// Return:
//		1: pressed
//		2: released
int isButton3Pressed(void){
	if (button3.flag == 1){
		button3.flag = 0;
		return 1;
	}
	else return 0;
}

//Get value of three button
void getButtonValue(void){
	getbutton1Value();
	getbutton2Value();
	getbutton3Value();
}


