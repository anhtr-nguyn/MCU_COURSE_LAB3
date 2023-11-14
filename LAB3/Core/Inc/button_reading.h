/*
 * button_reading.h
 *
 *  Created on: Nov 2, 2023
 *      Author: TrongAnh
 */

#ifndef INC_BUTTON_READING_H_
#define INC_BUTTON_READING_H_

#define PRESSED		0
#define RELEASED 	1

void getButtonValue(void);
int isButton1Pressed(void);
int isButton2Pressed(void);
int isButton3Pressed(void);

#endif /* INC_BUTTON_READING_H_ */
