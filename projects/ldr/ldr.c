/*
 * ldr.c
 *
 *  Created on: 17-Dec-2017
 *      Author: ccare
 */

#include"pmvBBB.h"
int main()
{
	analog_init();
	int A0;
	while(1)
	{
		A0=analogRead(0);
		printf("LDR = %d \n",A0);
		delay(200);
	}
}



