/*
 * 16x2lcd_4bit.c
 *
 *  Created on: 17-Dec-2017
 *      Author: ccare
 */

#include "lcd.h"

int main()
{
	lcd_init();
	int i = 0;
	while(i<100)
	{
		i++;
		lcd_cmd(0x80);
		delay(200);
		lcd_data('P');
		delay(200);
	}
	lcd_unexport();
}



