#include <LPC21xx.H>
#include "can_typedef.h"
#include "can_header.h"
#include "can_timer.h"
#include "CAN_LCD.h"
#include "can_uart.h"
#define SW1 14
#define SW2 15
#define SW3 16
int main()
{
	int lcount=0;
	int rcount=0;
	int vcount=0;
	CAN2_MSG s1;
	CAN2_MSG v;
	s1.rtr=0;
	s1.dlc=8;
	LCD_INIT();	
	LCD_STR("WELCOME TO");
	LCD_CMD(0XC0);
	LCD_STR("Ajitha Project");
//	delay_milliseconds(500);

	uart0_init(115200); 

	can2_init();

	uart0_string("Ajitha");
	LCD_CMD(0X01);
	LCD_STR("BODY CONTROL MODULE");
	delay_milliseconds(1000);
	LCD_CMD(0x01);
	LCD_CMD(0X80);
	LCD_STR("PRESS SWITCH...");
	LCD_CMD(0XC0);
	LCD_STR("SW1:LSW2:RSW3:W");
	while(1)
	{
	if(((IOPIN0>>SW1)&1)==0) //SWITCH ONE LEFT INDICATOR
	{
//	delay_milliseconds(150);
	lcount=!lcount;
	s1.byteA=lcount;
	s1.id= 0X01;
	can2_tx(s1);
		uart0_string("LEFT INIDICATOR");
		LCD_CMD(0x01);
	    LCD_CMD(0X80);
		LCD_STR("LEFT INIDICATOR ON");
		uart0_integer(s1.id);
		uart0_integer(s1.dlc);
		uart0_integer(s1.rtr);
		uart0_integer(s1.byteA);
		uart0_integer(s1.byteB);
		while(((IOPIN0>>SW1)&1)==0);
	}
  if(((IOPIN0>>SW2)&1)==0) //SWITCH TWO RIGHT INDICATOR
	{
	delay_milliseconds(150);
	rcount=!rcount;
	s1.byteB=rcount;
	s1.id= 0X02;
	can2_tx(s1);
		uart0_string("RIGHT INDICATOR");
		LCD_CMD(0x01);
	    LCD_CMD(0X80);
		LCD_STR("RIGHT INIDICATOR ON");
		uart0_integer(s1.id);
		uart0_integer(s1.dlc);
		uart0_integer(s1.rtr);
		uart0_integer(s1.byteA);
		uart0_integer(s1.byteB);
		while(((IOPIN0>>SW2)&1)==0);
	}
	if(((IOPIN0>>SW3)&1)==0) //SITCH THREE WIPER
	{
	delay_milliseconds(150);
	vcount=!vcount;
	v.byteA=vcount;
	v.id=0X03;
	can2_tx(v);
	uart0_string("WIPER ON");
		LCD_CMD(0x01);
	   LCD_CMD(0X80);
		LCD_STR("WIPER ON");
		uart0_integer(v.id);
		uart0_integer(v.dlc);
		uart0_integer(v.rtr);
		uart0_integer(v.byteA);
		uart0_integer(v.byteB);
		while(((IOPIN0>>SW3)&1)==0);
	}
	 }
	}