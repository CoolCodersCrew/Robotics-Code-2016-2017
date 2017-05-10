#pragma once
#include "API.h"

//MOTORS!!!!

#define MOTOR_LEFTFRONT_WHEEL			2
#define MOTOR_SPOOL						3
#define MOTOR_LEFTFRONT_WHEEL3			4
#define MOTOR_RIGHTFRONT_WHEEL			5
#define MOTOR_RIGHTFRONT_WHEEL2			6
#define MOTOR_TURBINE					7 

//SRC
void slewControlTask(void * parameter);

//Opcontrol
void manualControl();
void turnControl();
void turbineControl();
void spoolControl();

//Autonomous
extern int straight;
extern int leftTurning;
extern int rightTurning;
void autoDrive(int straight, int leftTurning, int rightTurning);






                

			