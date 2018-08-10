/*
 * taping.c
 *
 *  Created on: 16-Dec-2017
 *      Author: ccare
 */

#include"pmvBBB.h"

#define sw 11
#define led 12

int main()
{
	pinMODE(led,"OUTPUT");
	pinMODE(sw,"INPUT");
	int c=0,s=0;
	while(1)
	{
		if(digitalRead(sw)==0)
		{
			c++;
			if(c==2)
			{
				c=0;
				(s==0)?(s=1):(s=0);
				digitalWrite(led,s);
			}
		}
		else
		delay(100);
	}
}



