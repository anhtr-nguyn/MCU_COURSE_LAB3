/*
 * software_timer.h
 *
 *  Created on: Sep 30, 2023
 *      Author: TrongAnh
 */

#include "software_timer.h"

int TIME_CYCLE = 10;

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;

int timer4_counter = 0;
int timer4_flag = 0;

void setTimer1(int duration){
	timer1_counter =  duration / TIME_CYCLE;
	timer1_flag = 0;
}

void setTimer2(int duration){
	timer2_counter =  duration / TIME_CYCLE;
	timer2_flag = 0;
}

void setTimer3(int duration){
	timer3_counter =  duration / TIME_CYCLE;
	timer3_flag = 0;
}

void setTimer4(int duration){
	timer4_counter = duration / TIME_CYCLE;
	timer4_flag = 0;
}
void timer1Run(){
	if (timer1_counter > 0){
		timer1_counter--;
		if (timer1_counter <= 0){
			timer1_flag = 1;
		}
	}
}

void timer2Run(){
	if (timer2_counter > 0){
		timer2_counter--;
		if (timer2_counter <= 0){
			timer2_flag = 1;
		}
	}
}

void timer3Run(){
	if (timer3_counter > 0){
		timer3_counter--;
		if (timer3_counter <= 0){
			timer3_flag = 1;
		}
	}
}

void timer4Run(){
	if (timer4_counter > 0){
		timer4_counter--;
		if (timer4_counter <= 0){
			timer4_flag = 1;
		}
	}
}

void timerRun(){
	timer1Run();
	timer2Run();
	timer3Run();
//	timer4Run();
}
