/*
 * display_7seg.h
 *
 *  Created on: Sep 30, 2023
 *      Author: TrongAnh
 */

#ifndef INC_DISPLAY_7SEG_H_
#define INC_DISPLAY_7SEG_H_

extern int STATUS_7SEG;

#define INIT 4
#define SEG0 0
#define SEG1 1
#define SEG2 2
#define SEG3 3

//extern int STATUS_7SEG;
int TIME_7SEG;
extern int led_buffer[];

void setEnableSignal(int type);
void updateBufferWithMode(int MODE);
void displayNumber(int num);
void displaySegment(void);
#endif /* INC_DISPLAY_7SEG_H_ */
