#pragma once
#include "API.h"

//MOTORS!!!!

#define MOTOR_LEFT_FRONT_WHEEL			2
#define MOTOR_SPOOL						3
#define MOTOR_LEFT_FRONT_WHEEL3			4
#define MOTOR_RIGHT_FRONT_WHEEL			5
#define MOTOR_RIGHT_FRONT_WHEEL2		6
#define MOTOR_TURBINE					7 

//SRC

void slewControlTask(void * parameter);

//Integrated Motor Encoders
#define IME_LEFT_FRONT 2
#define IME_RIGHT_FRONT 4
#define IME_LEFT_REAR 5
#define IME_RIGHT_REAR 6
#define IME_NUMBER 4



//Opcontrol Functions

void manualControl();
void turnControl();
void turbineControl();
void spoolControl();
void shaftEncoder();
void motorCorrection();

//Shaft Encoders

#define QUAD_TOP_PORT 1
#define QUAD_BOTTOM_PORT 2
Encoder encoder;

//Autonomous

extern int straight;
extern int leftTurning;
extern int rightTurning;
void autoDrive(int straight, int leftTurning, int rightTurning);








                

			