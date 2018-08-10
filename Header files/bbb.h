/*
 * bbb.h
 *
 *  Created on: 03-Jun-2017
 *      Author: ccare
 */

#ifndef BBB_H_
#define BBB_H_

#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#define MAX 64

FILE *fp;
char GPIOstring[4],GPIOvalue[MAX],GPIOdirection[MAX];
int exportGPIO(int GPIOpin)
{
	sprintf(GPIOstring,"%d",GPIOpin);
	if((fp=fopen("/sys/class/gpio/export","ab"))==NULL)
		{
			printf("export fail\n");
			return 1;
		}
		fwrite(&GPIOstring,sizeof(char),2,fp);
		fclose(fp);
	return 0;
}
int unexportGPIO(int GPIOpin)
{
	sprintf(GPIOstring,"%d",GPIOpin);
	if((fp=fopen("/sys/class/gpio/unexport","ab"))==NULL)
		{
			printf("unexport fail\n");
			return 1;
		}
		fwrite(&GPIOstring,sizeof(char),2,fp);
		fclose(fp);
	return 0;
}
int set_direction(int GPIOpin,int n)
{
	sprintf(GPIOdirection,"/sys/class/gpio/gpio%d/direction",GPIOpin);
	if((fp=fopen(GPIOdirection,"rb+"))==NULL)
		{
			printf("Can not set Direction\n");
			return 1;
		}
		if(n==0)
			fwrite("in",sizeof(char),3,fp);
		else
			fwrite("out",sizeof(char),3,fp);
		fclose(fp);
	return 0;
}
void write_GPIO(int GPIOPin,int n)
{
	sprintf(GPIOvalue,"/sys/class/gpio/gpio%d/value",GPIOPin);
	if((fp=fopen(GPIOvalue,"rb+"))==NULL)
	{
		printf("can not open GPIO value\n");
		return ;
	}
	if(n)
	fwrite("1",sizeof(char),1,fp);
	else
	fwrite("0",sizeof(char),1,fp);
	fclose(fp);
}
void flash(int GPIOPin)
{
	exportGPIO(GPIOPin);
	set_direction(GPIOPin,1);
	for(int i=0;i<10;i++)
	{
		write_GPIO(GPIOPin,1);
		usleep(5000000);
		write_GPIO(GPIOPin,0);
		usleep(5000000);
	}
	unexportGPIO(GPIOPin);
}



#endif /* BBB_H_ */
