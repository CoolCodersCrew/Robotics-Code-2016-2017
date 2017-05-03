#pragma once
#include "API.h"

//MOTORS!!!!

#define MOTOR_LEFTFRONT_WHEEL			2
#define MOTOR_LEFTFRONT_WHEEL2			3
#define MOTOR_LEFTFRONT_WHEEL3			4 //not working interfering with gears
#define MOTOR_RIGHTFRONT_WHEEL			5
#define MOTOR_RIGHTFRONT_WHEEL2			6
#define MOTOR_RIGHTFRONT_WHEEL3			7 //not working interfering with gears

//SRC
void slewControlTask(void * parameter);



//Autonomous
extern int straight;
extern int leftTurning;
extern int rightTurning;
void autoDrive(int straight, int leftTurning, int rightTurning);






                

			