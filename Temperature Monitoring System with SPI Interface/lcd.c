#include <LPC21xx.H>
typedef unsigned int U8;
typedef signed int S32;
#define LCD_D 0X0f<<20
#define RS 1<<17
#define RW 1<<18
#define E 1<<19
void LCD_INIT(void);
void LCD_COMMAND(U8);
void LCD_DATA(U8);
void LCD_STR(unsigned char *);
void LCD_INTEGER(S32);
void LCD_FLOAT(float);
void delay_milliseconds(int milliseconds)
{
	//T0CTCR=0X00;
	T0PR = 15000-1;
	T0TCR = 0X01;
	while(T0TC<milliseconds);
	T0TCR = 0x03;
	T0TCR = 0x00;
}

void LCD_FLOAT(float f)
{
int temp;
temp=f;
LCD_INTEGER(temp);
LCD_DATA('.');
temp=(f-temp)*1000;
LCD_INTEGER(temp);
}

void LCD_INTEGER(S32 n)
{
	U8 arr[5];
	int i=0;
	if(n==0)
		LCD_DATA('0');
	else
	{
		if(n<0)
		{
			LCD_DATA('-');
			n=-n;
		}
		while(n>0)
		{
			arr[i++]=n%10;
			n=n/10;
		}
		for(--i;i>=0;i--)
		LCD_DATA(arr[i]+48);
	}
}

void LCD_STR(unsigned char*s)
{
	int i;
	for(i=0;s[i];i++)
	LCD_DATA(s[i]);

}

void LCD_INIT(void)
{	
IODIR1=LCD_D|RS|RW|E;
LCD_COMMAND(0X01);
LCD_COMMAND(0X02);
LCD_COMMAND(0X0C);
LCD_COMMAND(0X28);
LCD_COMMAND(0X80);
}
void LCD_COMMAND(U8 C)
{
IOCLR1=LCD_D;
IOSET1=(C&0Xf0)<<16;
IOCLR1=RS;
IOCLR1=RW;
IOSET1=E;
delay_milliseconds(2);
IOCLR1=E;
IOCLR1=LCD_D;
IOSET1=(C&0X0f)<<20;
IOCLR1=RS;
IOCLR1=RW;
IOSET1=E;
delay_milliseconds(2);
IOCLR1=E;

}
void LCD_DATA(U8 C)
{
IOCLR1=LCD_D;
IOSET1=(C&0Xf0)<<16;
IOSET1=RS;
IOCLR1=RW;
IOSET1=E;
delay_milliseconds(2);
IOCLR1=E;
IOCLR1=LCD_D;
IOSET1=(C&0X0f)<<20;
IOSET1=RS;
IOCLR1=RW;
IOSET1=E;
delay_milliseconds(2);
IOCLR1=E;
}
