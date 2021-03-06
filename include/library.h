#pragma once
#include "API.h"

// MOTORS!!!!

#define MOTOR_LEFT_FRONT_WHEEL			2
#define MOTOR_SPOOL						3
#define MOTOR_LEFT_FRONT_WHEEL3			4
#define MOTOR_RIGHT_FRONT_WHEEL			5
#define MOTOR_RIGHT_FRONT_WHEEL2		6
#define MOTOR_TEST_1					7 
#define MOTOR_TEST_2					8

/*SRC

void slewControlTask(void * parameter);
void smartMotorSet(int motor, int cmd);
#define mininum(a,b) (((a) > (b)) ? (a) : (b)) */

// Integrated Motor Encoders
#define IME_LEFT_FRONT		1
#define IME_RIGHT_FRONT		2
#define IME_NUMBER			4


/* Opcontrol Functions
	Declaring functions*/
void manualControl();
void turnControl();
void spoolControl();
void shaftEncoder();
void motorCorrection();
void testMotors();

// Shaft Encoders

#define QUAD_TOP_PORT		1
#define QUAD_BOTTOM_PORT	2
#define QUAD_TOP_PORT2		3
#define QUAD_BOTTOM_PORT2	4
#define QUAD_TOP_PORT3		5
#define QUAD_BOTTOM_PORT3	6


Encoder encoder;
Encoder driveEncoder;
Encoder driveEncoder2;

// Autonomous

/*extern int straight;
extern int leftTurning;
*/
int rightTurning;
void autoStraight(int left, int right);
void autoLeft(int left);
void autoRight(int right);
void autoArc(int left, int right, int length);
void speaker();

/*8-14-17

void cfunction();
int a;

*/








                

			