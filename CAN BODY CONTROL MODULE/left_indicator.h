#include <LPC21xx.H>
#include "lcd four.h"
typedef unsigned int U8;
#define LCD_D 0X0f<<20
#define RS 1<<17
#define RW 1<<18
#define E 1<<19
U8 CGRAM_LUT[]={0X00,0X04,0X08,0X1f,0X1f,0X08,0x04,0X00
                0X00,0X04,0X02,0X1f,0X1f,0X02,0x04,0X00};
void CGRAM_WRITE(U8);
int main()
{
LCD_INIT();
CGRAM_WRITE(16);
LCD_COMMAND(0X80);
LCD_DATA(0);
//delay_milliseconds(10);
LCD_DATA(1);
////delay_milliseconds(10);
//LCD_DATA(2);
////delay_milliseconds(10);
//LCD_DATA(3);
////delay_milliseconds(10);
//LCD_DATA(4);
}
void CGRAM_WRITE(U8 nBytes)
{
int i;
LCD_COMMAND(0X40);
for(i=0;i<nBytes;i++)
LCD_DATA(CGRAM_LUT[i]);
}

