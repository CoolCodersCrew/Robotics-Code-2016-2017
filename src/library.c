#include "main.h"
#include "library.h"

//Global Variables
int slewTmp;
int slewTarget[7];

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
	extern int slewTarget[7]; //motors
	while (1) {
		for (int i = 0; i < 7; i++) { //check each motor starting from 0 and adds 1
			slewTmp = motorGet(i + 1); //you never put motor in port 1, starts at port 2
			slewTmp += minimum(15, abs(slewTarget[i] - slewTmp))* \
			(slewTarget[i] - slewTmp) / abs(slewTarget[i] - slewTmp); 
			
			/* If the values in i2 are more than 15 do the math functions else, add speed for slew by 15, so it does not increase by 15 right at the start 
			 Ex. i =1, slewTarget[i] = 2, then slewTmp has a motorGet(), lets say it currently has a speed of 6 for motor prot 3, 
			 So abs(slewTarget[i] - slewTmp)) functions, 4*4/4 equals 4*/
			
			motorSet(i + 1, slewTmp); //now set the speed for that motor
		}
		wait(20);
	}
}
void smartMotorSet(int motor, int cmd) {
	extern int slewTarget[7];
	if (abs(cmd)<15) cmd = 0;
	slewTarget[motor - 1] = cmd;
}

//Autonomas//
void autoDrive(int straight, int leftTurning, int rightTurning)
{
	motorSet(2, straight);  motorSet(3, straight); motorSet(4, straight); motorSet(5, straight); motorSet(6, straight);
	motorSet(2, leftTurning); motorSet(3, leftTurning); motorSet(4, leftTurning);
	motorSet(5, rightTurning); motorSet(6, rightTurning); motorSet(7, rightTurning);
}







