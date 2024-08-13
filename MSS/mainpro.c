#include <LPC21xx.H>
#define SW   1<<14
#define PIN1 1<<0
#define PIN2 1<<1
#define BUZZER 1<<21
#include "timer3.h"
#include "lcdpro.h"
#include "uartpro.h"
#include "keypadpro.h"
#include "i2cpro.h"
#include "gsmpro.h"
#include "sevan.h"
#include "DC.h"

int open=0;
int c;
char p[20];
char *u;
char o[4];
int i,j;
int count=0;
int main()
{
	LCD_INIT();
	while(1)	{
  LCD_STR("WELCOME TO");
	LCD_COMMAND(0XC0);
	LCD_STR("AJITHA'S HOME");
	delay_milliseconds(2000);
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_STR("MULTI LEVEL ");
	delay_milliseconds(1000);
	LCD_COMMAND(0XC0);
	LCD_STR("SECURITY SYSTEM");
	delay_milliseconds(2000);
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_COMMAND(0X01);
 	if((IOPIN0&SW)==0)
 		{
 		break;
 		}
	}
	
	while(count!=3)
	{
		LCD_COMMAND(0xC0);
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_STR("ENTER PASSWORD");

	LCD_COMMAND(0xC0);	
	u=UART_PRO();
	LCD_COMMAND(0X01);
  LCD_COMMAND(0X80);
	
	
	I2C_FINAl(p);
	
	if(strcmp(p,u)==0)
	{
	LCD_COMMAND(0X01);
	LCD_COMMAND(0X80);
	LCD_STR("PASSWORD CORRECT");
	delay_milliseconds(2000);
	LCD_COMMAND(0X01);
  LCD_COMMAND(0X80);
  LCD_STR("OTP SENDING");		
 delay_milliseconds(1000);
	
		gsmpro(o);
		
		while(c!=3)
	  {	
		//gsmpro(o);
    LCD_COMMAND(0X01);
    LCD_COMMAND(0X80);			
		LCD_STR("ENTER THE OTP");
	  LCD_COMMAND(0XC0);
		u=UART_PRO();
		
	if(strcmp(o,u)==0)
	{
		DC();
    return 0;
}
	else
		{
			c++;
			LCD_STR("INVALID OTP");
			delay_milliseconds(2000);
			LCD_COMMAND(0X01);
		}
	}
		if(c==3)
		{
			LCD_STR("SORRY DOOR");
			LCD_COMMAND(0XC0);
			LCD_STR("       LOCKED");
			return 0;
		}
	}
	
		else
		{
			count ++;
			LCD_COMMAND(0X01);
      LCD_COMMAND(0X80);
			LCD_STR("PASSWORD");
			 LCD_COMMAND(0XC0);
			LCD_STR("INCORRECT");
			delay_milliseconds(2000);
			LCD_COMMAND(0X01);
		}	
		
		if(count==3)
		{
			LCD_STR("WAIT for 10 secs");
			seven();
		  //delay_milliseconds(10000);
			LCD_COMMAND(0X01);
			count=0;
		}
	}
}
