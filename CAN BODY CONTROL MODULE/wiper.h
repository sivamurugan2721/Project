#include <LPC21xx.H>
#include "can_rtimer.h"
#include "can_rlcd.h"
#define PIN1 1<<6
#define PIN2 1<<7
#define BUZZER 1<<21
int main()
{
LCD_INIT();
IODIR0=PIN1|PIN2|BUZZER;
IOSET0=PIN1;
IOCLR0=PIN2;
LCD_STR("WIPER ON");
delay_milliseconds(5000);
IOSET0=PIN1|PIN2|BUZZER ;
delay_milliseconds(1000);
LCD_COMMAND(0X01);
LCD_COMMAND(0X80);
LCD_STR("WIPER CLOSE");
IOCLR0=PIN1|BUZZER;
IOSET0=PIN2;
delay_milliseconds(5000);
IOSET0=PIN1;
IOSET0=PIN2;
}