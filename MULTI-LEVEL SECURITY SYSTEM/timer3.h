#include <LPC21xx.H>
typedef unsigned int U32;
void delay_milliseconds(int milliseconds)
{
T0PR=15000-1;
T0TCR=0X01;
while(T0TC < milliseconds);
T0TCR=0X03;
T0TCR=0X00;
}	
void delay_seconds(int seconds)
{
T0PR=15000000-1;
T0TCR=0X01;
while(T0TC < seconds);
T0TCR=0X03;
T0TCR=0X00;   
}	
void delay_microseconds(int microseconds)
{
T0PR=15-1;
T0TCR=0X01;
while(T0TC < microseconds);
T0TCR=0X03;
T0TCR=0X00;
}	
