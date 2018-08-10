/*
 * pwm.c
 *
 *  Created on: 18-Dec-2017
 *      Author: ccare
 */
#include "pmvBBB.h"

#define pin "P9_22"

int main()
{
	pwm_init(pin);

	while(1)
	{
		int i;
		for(i=0;i<100;i++)
		{
				pwm_write(pin,i*100);
				delay(100);
		}
	}

}



