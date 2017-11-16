
#include "main.h"

void rIME() // Will implement with motor corrections
{
	// Reset
	imeReset(1);
	imeGet(1, &imeLeft);
	
	imeReset(2);
	imeGet(2, &imeRight);
}

void pDrive(int k)
{
	k = .8; // Constant
	
	// Get Ime Values
	imeGet(1, &imeLeft);
	imeGet(2, &imeRight);

	imeLcor = target - imeLeft;
	imeRcor = target - imeRight;

	lPow = imeLcor * k;
	rPow = imeRcor * k;
}