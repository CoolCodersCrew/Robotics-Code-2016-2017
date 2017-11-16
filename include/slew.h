#pragma once

#ifndef _SLEW_H_
#define _SLEW_H_


/*Testing based on little knowledge ik about this, ik it only involve P as of right now
	Will replace slewcontroltask*/


int imeLeft;
int imeRight;
int imeLcor;
int imeRcor;
int k;
float lPow;
float rPow;
int target;
void rIME();
void pDrive();
void mSet();

#endif