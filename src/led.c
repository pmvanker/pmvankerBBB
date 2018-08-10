/*
 * led.c
 *
 *  Created on: 15-Dec-2017
 *      Author: ccare
 */
#define led 13
#include "pmvBBB.h"
int main() {
	pinMODE(led, "OUTPUT");
	int k = 5;
	while (k--) {
		digitalWrite(led, 1);
		delay(500);
		digitalWrite(led, 0);
		delay(500);
	}
	unexport(led);
}

