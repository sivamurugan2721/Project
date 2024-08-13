#include <LPC21xx.H>
#include "can_typedef.h"
#include "can_header.h"
#include "can_timer.h"
#include "can_uart.h"
#include "can_rlcd.h"
#define LED1 1<<17
#define LED2 1<<18
#define LED3 1<<19
int main()
{
	CAN2_MSG s2;
	can2_init();
	IODIR0=LED1|LED2|LED3;
	IOSET0=LED1|LED2|LED3;
	while(1)
	{
	can2_rx(&s2);
	if((s2.id==0X01)&&(s2.byteA==1)) // LEFT INIDCATOR
	IOCLR0=LED1;
	
	else
	IOSET0=LED1;
	 
	if((s2.id==0X02)&&(s2.byteB==1)) // RIGHT INDICATOR
	IOCLR0=LED2;
	
	else
	IOSET0=LED2;
	
	if((s2.id==0X03)&&(s2.byteA==1)) // WIPER
	IOCLR0=LED3;
	
	else
	IOSET0=LED3;
}
	}
