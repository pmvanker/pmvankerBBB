/*
 * switch.c
 *
 *  Created on: 16-Dec-2017
 *      Author: ccare
 */
#define sw 13
#include"pmvBBB.h"
int main()
{
	pinMODE(sw,"INPUT");
	int j=5;
	while(j--)
	{
		if(digitalRead(sw))
		printf("Switch NOT press\n");
		else
		printf("Switch press\n");
		delay(500);
	}
	unexport(sw);
}
