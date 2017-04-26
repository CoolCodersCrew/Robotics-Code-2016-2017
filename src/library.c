#include "main.h"
#include "library.h"

//Global Variables
int slewTmp;
int slewTarget[10];

//Helpers
int min(int i1, int i2){
  if(i1>=i2) return i2;
  else return i1;
}
int max(int i1, int i2) {
	if (i1 <= i2) return i2;
	else return i1;
}
void slewControlTask(void * parameter) {
	extern int slewTmp;
	extern int slewTarget[10];
	while (1) {
		for (int i = 0; i < 10; i++) {
			slewTmp = motorGet(i + 1);
			slewTmp += min(15, abs(slewTarget[i] - slewTmp))*(slewTarget[i] - slewTmp) / abs(slewTarget[i] - slewTmp);
			motorSet(i + 1, slewTmp);
		}
		wait(20);
	}
}
void smartMotorSet(int motor, int cmd) {
	extern int slewTarget[10];
	if (abs(cmd)<15) cmd = 0;
	slewTarget[motor - 1] = cmd;
}

void autoDrive(int straight, int leftTurning, int rightTurning)
{
	motorSet(2, straight);  motorSet(3, straight); motorSet(5, straight); motorSet(6, straight);
	motorSet(2, leftTurning); motorSet(3, leftTurning);
	motorSet(5, rightTurning); motorSet(6, rightTurning);
}







