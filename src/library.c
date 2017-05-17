#include "main.h"
#include "library.h"

//Global Variables
int slewTmp;
int slewTarget[6];

//SRC 
int minimum(int i1, int i2){
  if(i1>=i2) return i2; // if less than 15 do math functions in parameter i2 (Check slewControlTask)
  else return i1;
}
int maxinum(int i1, int i2) {
	if (i1 <= i2) return i2;
	else return i1;
}
void slewControlTask(void * parameter) {
	extern int slewTmp;
	extern int slewTarget[6]; // motors
	while (1) {
		for (int i = 0; i < 6; i++) { // check each motor starting from 0 and adds 1
			slewTmp = motorGet(i + 1); // you never put motor in port 1, starts at port 2
			slewTmp += minimum(15, abs(slewTarget[i] - slewTmp))* \
			(slewTarget[i] - slewTmp) / abs(slewTarget[i] - slewTmp); 
			
			/* If the values in i2 are more than 15 do the math functions else, add speed for slew by 15, so it does not increase by 15 right at the start 
			 Ex. i =1, slewTarget[i] = 2, then slewTmp has a motorGet(), lets say it currently has a speed of 6 for motor prot 3, 
			 So abs(slewTarget[i] - slewTmp)) functions, 4*4/4 equals 4*/
			
			motorSet(i + 1, slewTmp); // now set the speed for that motor
		}
		wait(20);
	}
}
void smartMotorSet(int motor, int cmd) {
	extern int slewTarget[6];
	if (abs(cmd)<15) cmd = 0;
	slewTarget[motor - 1] = cmd;
}

//Autonomous//
/**
* Straight Autonomous function 
* @param Power of motors
*/
void autoStraight(int straight)
{
	int time = millis();
	while (true)
	{
		while (millis() - time < 2000)
		{
			motorSet(2, straight); motorSet(4, straight); motorSet(5, straight); motorSet(6, straight);
			wait(100);
		}
	}
}
/**
* Left Autonomous function
* @param Power of motors
*/
void autoLeft(int left)
{
	int time = millis();
	while (true)
	{
		while (millis() - time < 2000)
		{
			motorSet(2, left); motorSet(4, left);
			wait(100);
		}
	}
}
/**
* Right Autonomous function
* @param Power of motors
*/
void autoRight(int right)
{
	int time = millis();
	while (true)
	{
		while (millis() - time < 2000)
		{
			motorSet(5, -right); motorSet(6, right);
			wait(100);
		}
	}
}
/**
* Arc Turn Autonomous function
* @param Power of left motors
* @param Power of right motors
*/
void autoArc(int left, int right)
{
	int time = millis();

	while (millis() - time < 4000) 
	{
		motorSet(2, left); motorSet(4, -left);
		motorSet(5, -right); motorSet(6, right);
		wait(100);
	}

}

//Manual Control//
/**
* Normal Driver control function
*/
void manualControl() // Drive Control
{
	//Defining function
	//LF WHEEL//
		if (abs(joystickGetAnalog(1, 3)) > 15) 
		{
			motorSet(2, joystickGetAnalog(1, 3));
			motorSet(4, -joystickGetAnalog(1, 3));
		}
		else
		{
			motorSet(2, 0);
			motorSet(4, 0);
		}
	//RF WHEEL//
		if (abs(joystickGetAnalog(1, 2)) > 15)
		{
			motorSet(5, -joystickGetAnalog(1, 2));
			motorSet(6, joystickGetAnalog(1, 2));
		}
		else
		{
			motorSet(5, 0);
			motorSet(6, 0);
		}
	
}

// Turn Control //
/*Not being utilized*/
void turnControl()
{
	if (joystickGetDigital(1, 6, JOY_UP))
	{
		motorSet(2, 0);
		motorSet(4, 0);
		motorSet(5, 127 - (abs(joystickGetAnalog(1, 2) > 15)));
		motorSet(6, 127 - (abs(joystickGetAnalog(1, 2) > 15)));
	}
	else
	{
		manualControl();
	}
}

// Turbine Control // 
void turbineControl() // Gear with zipties so it can do multiple laps in after just going sround once
{
	{ 
		if (joystickGetDigital(1, 5, JOY_DOWN))
		{
			motorSet(7, -127);
		}

		else if (joystickGetDigital(1, 5, JOY_UP))
		{
			motorSet(7, 127);
		}

		else
		{
			motorSet(7, 0);
		}
	}
}

// Spool Control //
/*Being replaced by shaft encoder*/
void spoolControl()
{
	if (joystickGetDigital(1, 5, JOY_DOWN)) // rope control so robot can technically be in 4 squares
	{
		motorSet(3, 100); // wind
	}

	else if (joystickGetDigital(1, 5, JOY_UP))
	{
		motorSet(3, -127); // unwind
	}
	else if (joystickGetDigital(1, 6, JOY_UP))
	{
		motorSet(3, -50); // slower unwind
	}
	else
	{
		motorSet(3, 0);
	}

}

// Shaft Encoder (Precise string layer) //

void shaftEncoder()
{
  
	if (joystickGetDigital(1, 6, JOY_UP))
	{
		while (abs(encoderGet(encoder)) < 5)
		{
			motorSet(7, 127);
			motorSet(2, 0);
			motorSet(4, 0);
			motorSet(5, 0);
			motorSet(6, 0);
			printf("Enc value: %d\r\n", encoderGet(encoder));
		}
		while (joystickGetDigital(1, 6, JOY_UP))
		{
			motorSet(7, 0);
			wait(20);
		}
	}
	else if (joystickGetDigital(1, 6, JOY_DOWN))
	{
		while (abs(encoderGet(encoder)) < 5)
		{
			motorSet(7, -127);
			motorSet(2, 0);
			motorSet(4, 0);
			motorSet(5, 0);
			motorSet(6, 0);
			printf("Enc value: %d\r\n", encoderGet(encoder));
		}
		while (joystickGetDigital(1, 6, JOY_DOWN))
		{
			motorSet(7, 0);
			wait(20);
		}
	}
		else
		{
			encoderReset(encoder);
			motorSet(7, 0);
		}
  
}

	
// IME Stable Manual not yet // 
void motorCorrection()
{
	int encLeftFront;
	int encRightFront;
	int encLeftRear;
	int encRightRear;
	int K = 0; // temporary value

	while (1)
	{
		imeReset(IME_LEFT_FRONT);
		imeReset(IME_LEFT_REAR);
		imeReset(IME_RIGHT_FRONT);
		imeReset(IME_RIGHT_REAR);
		if (abs(joystickGetAnalog(1, 3)) > 15)
		{
			motorSet(2, joystickGetAnalog(1, 3) - K*(imeGet(IME_RIGHT_FRONT, &encRightFront) - imeGet(IME_LEFT_FRONT, &encLeftFront))); // LF Wheel
			motorSet(4, -joystickGetAnalog(1, 3) - K*(imeGet(IME_RIGHT_REAR, &encRightRear) - imeGet(IME_LEFT_REAR, &encLeftRear)));  // LB Wheel 
			printf("IME LF value: %d\r\n", imeGet(IME_LEFT_FRONT, &encLeftFront));
			printf("IME RF value: %d\r\n", imeGet(IME_RIGHT_FRONT, &encRightFront));
			printf("IME RB value: %d\r\n", imeGet(IME_RIGHT_REAR, &encRightRear));
			printf("IME LB value: %d\r\n", imeGet(IME_LEFT_REAR, &encLeftRear));
		}
		else if (abs(joystickGetAnalog(1, 3)) < 15)
		{
			motorSet(2, 0);
			motorSet(4, 0);
			imeReset(IME_LEFT_FRONT);
			imeReset(IME_LEFT_REAR);
			imeReset(IME_RIGHT_FRONT);
			imeReset(IME_RIGHT_REAR);
		}
		if (abs(joystickGetAnalog(1, 3)) > 15)
		{
			motorSet(5, -joystickGetAnalog(1, 2) - K*(imeGet(IME_LEFT_FRONT, &encLeftFront) - imeGet(IME_RIGHT_FRONT, &encRightFront))); // RF Wheel
			motorSet(6, joystickGetAnalog(1, 2) - K*(imeGet(IME_LEFT_REAR, &encLeftRear) - imeGet(IME_RIGHT_REAR, &encRightRear)));	// LF Wheel
			printf("IME LF value: %d\r\n", imeGet(IME_LEFT_FRONT, &encLeftFront));
			printf("IME RF value: %d\r\n", imeGet(IME_RIGHT_FRONT, &encRightFront));
			printf("IME RB value: %d\r\n", imeGet(IME_RIGHT_REAR, &encRightRear));
			printf("IME LB value: %d\r\n", imeGet(IME_LEFT_REAR, &encLeftRear));
		}
		else if (abs(joystickGetAnalog(1, 3)) < 15)
		{
			motorSet(5, 0);
			motorSet(6, 0);
			imeReset(IME_LEFT_FRONT);
			imeReset(IME_LEFT_REAR);
			imeReset(IME_RIGHT_FRONT);
			imeReset(IME_RIGHT_REAR);
		}
		/*if (abs(joystickGetAnalog(1, 3)) < 20 && abs(joystickGetAnalog(1, 3)) < 20)
		{
			motorSet(2, joystickGetAnalog(1, 3));
			motorSet(4, -joystickGetAnalog(1, 3));
			motorSet(5, -joystickGetAnalog(1, 2));
			motorSet(6, joystickGetAnalog(1, 2));
		}*/
		else
		{
			motorSet(2, 0);
			motorSet(4, 0);
			motorSet(5, 0);
			motorSet(6, 0);
			imeReset(IME_LEFT_FRONT);
			imeReset(IME_LEFT_REAR);
			imeReset(IME_RIGHT_FRONT);
			imeReset(IME_RIGHT_REAR);
		}
	}
}


