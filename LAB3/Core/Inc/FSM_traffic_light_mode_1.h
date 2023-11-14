/*
 * traffic_light.h
 *
 *  Created on: Nov 2, 2023
 *      Author: TrongAnh
 */

#ifndef INC_FSM_TRAFFIC_LIGHT_MODE_1_H_
#define INC_FSM_TRAFFIC_LIGHT_MODE_1_H_

// time of each color led, could be edit when change mode
extern int timeRed;
extern int timeYellow;
extern int timeGreen;

extern int counter_first_2SEG; // Counting for one way traffic
extern int counter_latter_2SEG; // Counting for another way traffic
int led1_status; // For one way traffic: have 3 status RED, YELLOW, GREEN
int led2_status; // For another way traffic: have 3 status RED, YELLOW, GREEN

#define RED		1
#define	YELLOW	2
#define GREEN	3

// set ON OFF for writing led negative pin
#define ON 	0
#define OFF	1

// for mode 1 only
void trafficLightRun(void);
#endif /* INC_FSM_TRAFFIC_LIGHT_MODE_1_H_ */
