#include <LPC21xx.H>
#include "can_typedef.h"
#include "can_header.h"
#include "can_timer.h"
#include "can_uart.h"
#include "can_rlcd.h"
#define PIN1 1<<19
#define PIN2 1<<20
#define BUZZER 1<<21
#define LED 1<<22
int main()
{
		CAN2_MSG s2;
		can2_init();		
		IODIR0=PIN1|PIN2|BUZZER|LED;
		IOSET0=PIN1|PIN2|LED;
while(1)
	{
			can2_rx(&s2);
if((s2.id==0X03)&&(s2.byteA==1))				 //WIPER RECEIVER ID
		{
			IOSET0=PIN1;
			IOCLR0=PIN2;
			delay_milliseconds(10000);
			IOSET0=PIN1|PIN2|BUZZER ;
		}
else
			IOSET0=PIN1|PIN2;
			IOCLR0=BUZZER;
}
	}

