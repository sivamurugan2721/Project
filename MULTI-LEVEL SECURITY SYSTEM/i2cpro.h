#include <LPC21xx.H>
#include <string.h>
#define SCL_EN  0x00000010
#define SDA_EN  0x00000040
#define CCLK    60000000  
#define PCLK    CCLK/4    
#define I2C_SPEED 100000    
#define LOADVAL   ((PCLK/I2C_SPEED)/2)
#define AA_BIT 2
#define SI_BIT 3
#define STOP_BIT 4
#define START_BIT 5
#define I2EN_BIT 6
#define I2C_EEPROM_SA 0X50
#define gled 1<<17
#define rled 1<<19
void I2C_INIT(void);
void I2C_EEPROM_WRITE(char,char,char);
char I2C_EEPROM_READ(char,char);
void I2C_EEPROM_PAGE_WRITE(char,char,char*,int);
void I2C_EEPROM_SEQUENCE_READ(char,char,char*,int);
void I2c_START(void);
void I2C_RESTART(void);
void I2C_WRITE(char);
char I2C_NACK(void);
char I2C_MASTERACK(void);
void I2C_STOP(void);
//char s[20];

void I2C_FINAl(char*p)
{
	//char p[20];
	//int i;
	I2C_INIT();
	
	I2C_EEPROM_PAGE_WRITE(I2C_EEPROM_SA,0x00,"1234",4);
	I2C_EEPROM_SEQUENCE_READ(I2C_EEPROM_SA,0x00,p,4);
	//for(i=0;i<8;i++)
	//s[i]=p[i];
	//return s;
	}

void I2C_EEPROM_PAGE_WRITE(char slave_Addr,char WBuffer_Addr,char *p,int n)
{	int i;
	I2c_START();
	I2C_WRITE(slave_Addr<<1);
	I2C_WRITE(WBuffer_Addr);
	for(i=0;i<n;i++)
	{
	I2C_WRITE(p[i]);
	}
	I2C_STOP();
	delay_milliseconds(10);
}
void I2C_EEPROM_SEQUENCE_READ(char slave_Addr,char rBuffer_Addr,char *p,int n)
{
    int i;
	I2c_START();
	I2C_WRITE(slave_Addr<<1);
	I2C_WRITE(rBuffer_Addr);
	I2C_RESTART();
	I2C_WRITE(slave_Addr<<1|1);
	for(i=0;i<n-1;i++)
	{
	p[i]=I2C_MASTERACK();
	}
	//p[i]='\0';
	p[i]=I2C_NACK();
	I2C_STOP();
	}
void I2C_INIT(void)
{
	PINSEL0=SDA_EN|SCL_EN;
	I2SCLL=LOADVAL;
	I2SCLH=LOADVAL;
	I2CONSET=1<<I2EN_BIT;
}

void I2c_START(void)
{
	I2CONSET=1<<START_BIT;
	while((I2CONSET>>SI_BIT&1)==0);
	I2CONCLR=1<<START_BIT;
}
void I2C_RESTART(void)
{
	I2CONSET=1<<START_BIT;
	I2CONCLR=1<<SI_BIT;
	while((I2CONSET>>SI_BIT&1)==0);
	I2CONCLR=1<<START_BIT;
}
void I2C_WRITE(char d)
{
	I2DAT=d;
	I2CONCLR=1<<SI_BIT;
	while((I2CONSET>>SI_BIT&1)==0);
}
char I2C_NACK()
{
	I2CONSET=0X00;
	I2CONCLR=1<<SI_BIT;
	while((I2CONSET>>SI_BIT&1)==0);
	return I2DAT;
}
char I2C_MASTERACK(void)
{
I2CONSET=0X04;
I2CONCLR=1<<SI_BIT;
while(((I2CONSET>>SI_BIT)&1)==0);
I2CONCLR=0X04;
return I2DAT;
}

void I2C_STOP()
{
  I2CONSET=1<<STOP_BIT;
  I2CONCLR=1<<SI_BIT;
}
