#pragma once
#include "API.h"
//Whoa MOTORS!!!!

#define MOTOR_LEFTBACK_WHEEL			1
#define MOTOR_LEFTBACK_WHEEL2			2
#define MOTOR_LEFTBACK_WHEEL3			3
#define MOTOR_RIGHTBACK_WHEEL			4
#define MOTOR_RIGHTBACK_WHEEL2			5
#define MOTOR_RIGHTBACK_WHEEL3			6
#define MOTOR_LEFTFRONT_WHEEL			7
#define MOTOR_LEFTFRONT_WHEEL2			8
#define MOTOR_LEFTFRONT_WHEEL3			9
#define MOTOR_RIGHTFRONT_WHEEL			10
#define MOTOR_RIGHTFRONT_WHEEL2			11
#define MOTOR_RIGHTFRONT_WHEEL3			12





//Nothing
extern int straight;
extern int leftTurning;
extern int rightTurning;


void autoDrive(int straight, int leftTurning, int rightTurning);




                

			