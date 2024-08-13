//#include <LPC21xx.H>
//#include "lcd four.h"
#define c0 (IOPIN0&(1<<16))
#define c1 (IOPIN0&(1<<17))
#define c2 (IOPIN0&(1<<18))
#define c3 (IOPIN0&(1<<19))
#define r0 	1<<20
#define r1 	1<<21
#define r2 	1<<22
#define r3 	1<<23
int key_scan(void);
char a[4][4]={ {'1','2','3','4'},{'5','6','7','8'},{'9','0','11','12'},{'4','6','0','@'}};
//int main()
//{
//int res;

//LCD_INIT();
// while(1)
// {
// //LCD_STR("SIVA KEYPAD");

// LCD_COMMAND(0XC0);//scond line in lcd
// res=key_scan();
// LCD_DATA((res/10)+48);
// LCD_DATA((res%10)+48);
// delay_milliseconds(2000);
// LCD_COMMAND(0X01);
// }
// }
int key_scan(void)
{
char row,col;
PINSEL0|=0X00000000;//GPIO
IODIR0|=r0|r1|r2|r3;//set output pin 
while(1)
{ 
IOCLR0|=r0|r1|r2|r3;
IOSET0|=c0|c1|c2|c3;
while((c0&&c1&&c2&&c3)==1);

/*check row*/
IOCLR0|=r0;
IOSET0|=r1|r2|r3;
if((c0&&c1&&c2&&c3)==0)
{
row=0;
break;
}
IOCLR0|=r1;
IOSET0|=r0|r2|r3;
if((c0&&c1&&c2&&c3)==0)
{
row=1;
break;
}
IOCLR0|=r2;
IOSET0|=r0|r1|r3;
if((c0&&c1&&c2&&c3)==0)
{
row=2;
break;
}
IOCLR0|=r3;
IOSET0|=r0|r1|r2;
if((c0&&c1&&c2&&c3)==0)
{
row=3;
break;
}
}
if(c0==0)
col=0;
else if(c1==0)
col=1;
else if(c2==0)
col=2;
else 
col=3;
delay_milliseconds(150);
while((c0&&c1&&c2&&c3)==0);
return a[row][col];
}


					    