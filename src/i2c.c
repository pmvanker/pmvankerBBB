#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>

typedef struct MPU6050_data
{
	short int ACC_X_OUT;
	short int ACC_Y_OUT;
	short int ACC_Z_OUT;
	short int GYR_X_OUT;
	short int GYR_Y_OUT;
	short int GYR_Z_OUT;
}MPU;


int main()
{
	static MPU data;
	char buff[6],data_write[2];
	int fd;
	static char data1;
	char add=0x68;
	char whoami=0x75;
	char acc=0x3b;
	char gyr=0x43;
	char power=0x6b;
	char acc_config=0x1c;
	char gyr_config=0x1b;

	if((fd=open("/dev/i2c-1",O_RDWR))<0)
	{
		perror("open");
	}
	perror("open");
	ioctl(fd,I2C_SLAVE,add);
	perror("ioctl");
	write(fd,&whoami,1);
	perror("write");
	read(fd,&data1,1);
	perror("read");

	printf("dec =%d hex=%x char=%c \n",data1,data1,data1);	


	data_write[0]=acc_config;
	data_write[1]=0;
	write(fd,data_write,2);

	data_write[0]=gyr_config;
	data_write[1]=0;
	write(fd,data_write,2);

	data_write[0]=power;
	data_write[1]=0;
	write(fd,data_write,2);
	while(1)
	{
		write(fd,&acc,1);
		read(fd,buff,6);
		data.ACC_X_OUT = (buff[0]<<8|buff[1]) /16384;
		data.ACC_Y_OUT = (buff[2]<<8|buff[3]) /16384;
		data.ACC_Z_OUT = (buff[4]<<8|buff[5]) /16384;


		write(fd,&gyr,1);
		read(fd,buff,6);
		data.GYR_X_OUT = (buff[0]<<8|buff[1]) /131 ;
		data.GYR_Y_OUT = (buff[2]<<8|buff[3]) /131;
		data.GYR_Z_OUT = (buff[4]<<8|buff[5]) /131;


		printf("acc_x=%d acc_y=%d acc_z=%d\tgyr_x=%d gyr_y=%d gyr_z=%d\n",data.ACC_X_OUT,data.ACC_Y_OUT,data.ACC_Z_OUT,data.GYR_X_OUT,data.GYR_Y_OUT,data.GYR_Z_OUT);
		usleep(100000);
	}
	close(fd);
	return 0;
}
