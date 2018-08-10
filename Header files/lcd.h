/*
 * lcd.h
 *
 *  Created on: 17-Dec-2017
 *      Author: ccare
 */

#ifndef SRC_LCD_H_
#define SRC_LCD_H_

#include "pmvBBB.h"

#define rs 11
#define en 12

#define P0 13
#define P1 14
#define P2 15
#define P3 16

void lcd_unexport()
{
	int i;
	for(i=11;i<=16;i++)
	unexport(i);
}
void lcd_port(int x)
{
	digitalWrite(P3,(x>>3)&1);
	digitalWrite(P2,(x>>2)&1);
	digitalWrite(P1,(x>>1)&1);
	digitalWrite(P0,(x>>0)&1);
}

void lcd_init()
{
	pinMODE(rs,"OUTPUT");
	pinMODE(en,"OUTPUT");
	pinMODE(P0,"OUTPUT");
	pinMODE(P1,"OUTPUT");
	pinMODE(P2,"OUTPUT");
	pinMODE(P3,"OUTPUT");

	lcd_port(0x28);
	lcd_port(0x0c);
	lcd_port(0x06);
	lcd_port(0x01);
}
void lcd_cmd(char cmd)
{
	lcd_port(cmd & (0xf0));
	digitalWrite(rs,0);
	digitalWrite(en,1);
	delay(5);
	digitalWrite(en,0);
	lcd_port(cmd<<4);
	digitalWrite(rs,0);
	digitalWrite(en,1);
	delay(5);
	digitalWrite(en,0);
}

void lcd_data(char cmd)
{
	lcd_port(cmd & (0xf0));
	digitalWrite(rs,1);
	digitalWrite(en,1);
	delay(5);
	digitalWrite(en,0);
	lcd_port(cmd<<4);
	digitalWrite(rs,1);
	digitalWrite(en,1);
	delay(5);
	digitalWrite(en,0);
}

void lcd_string(char *p)
{
 	while(*p)
 	{
 		lcd_data(*p++);
 		delay(100);
 	}
}


#endif /* SRC_LCD_H_ */
