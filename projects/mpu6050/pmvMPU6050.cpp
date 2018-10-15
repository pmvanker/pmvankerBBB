/*
 * pmvMPU6050.cpp
 *
 *  Created on: 12-Oct-2018
 *      Author: vvdn
 */
#include<unistd.h>
#include<iostream>
#include"../Header files/MPU6050.h"
#include "../Header files/I2CDevice.h"
#include<stdio.h>
//using namespace exploringBB;
using namespace std;
using namespace exploringBB;
namespace exploringBB
{
	class MPU6050:public I2CDevice
	{
	private:
		unsigned int bus;
		unsigned int address;
	public:
		int ACC_X,ACC_Y,ACC_Z,GYR_X,GYR_Y,GYR_Z,TMP;
		unsigned char *buff;
		void powr_up()
		{
			this->writeRegister(MPU6050_RA_PWR_MGMT_1, 0);
		}
		void powr_down()
		{
					this->writeRegister(MPU6050_RA_PWR_MGMT_1, 0x40);
		}
		unsigned char read_byte(unsigned char add)
		{
			return this->readRegister(add);
		}
		unsigned char write_byte(unsigned char add,unsigned char data)
		{
					return this->writeRegister(add, data);
		}

		void update_sensor()
		{
			buff = this->readRegisters(14,MPU6050_RA_ACCEL_XOUT_H);
			this->ACC_X=buff[0]<<8|buff[1];
			this->ACC_Y=buff[2]<<8|buff[3];
			this->ACC_Z=buff[4]<<8|buff[5];
			this->GYR_X=buff[8]<<8|buff[9];
			this->GYR_Y=buff[10]<<8|buff[11];
			this->GYR_Z=buff[12]<<8|buff[13];
			this->TMP=buff[6]<<8|buff[7];
		}
		void calibration()
		{
			this->TMP=(this->TMP/340) + 36.53;
			this->ACC_X/=16384;
			this->ACC_Y/=16384;
			this->ACC_Z/=16384;
			this->GYR_X/=131;
			this->GYR_Y/=131;
			this->GYR_Z/=131;
		}


		void print()
		{
			cout<<dec;
			cout<<"ACC("<<this->ACC_X<<" ";
			cout<<this->ACC_Y<<" ";
			cout<<this->ACC_Z<<") ";
			cout<<"GYR("<<this->GYR_X<<" ";
			cout<<this->GYR_Y<<" ";
			cout<<this->GYR_Z<<") ";
			cout<<"Temp = "<<this->TMP<<" "<<endl;
		}
		MPU6050(unsigned int bus,unsigned address):I2CDevice(bus,address)
		{
			this->address=address;
			this->bus=bus;
		}
	};
}

int main()
{
	MPU6050 mpu6050(2,0x68);
	mpu6050.powr_up();

	//fifo enable
	mpu6050.writeRegister(MPU6050_RA_USER_CTRL, 0x40);
	mpu6050.writeRegister(MPU6050_RA_FIFO_EN, 0x0f8);

	while(1)
	{
	mpu6050.update_sensor();
	usleep(100000);
	//mpu6050.calibration();
	mpu6050.print();
	usleep(100000);
	}


	mpu6050.powr_down();
	mpu6050.close();
}

