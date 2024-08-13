//#define LCD_D 0X0f<<20
//#define RS 1<<17
//#define RW 1<<18
//#define E 1<<19
unsigned int CGRAM_LUT[]={0X00,0X04,0X08,0X1f,0X1f,0X08,0x04,0X00};
void CGRAM_WRITE(unsigned int);
void RIGHT(void)
{
LCD_INIT();
CGRAM_WRITE(8);
LCD_CMD(0XC0);
LCD_DISPLAY(0);
//delay_milliseconds(10);
////delay_milliseconds(10);
//LCD_DATA(2);
////delay_milliseconds(10);
//LCD_DATA(3);
////delay_milliseconds(10);
//LCD_DATA(4);
}
void CGRAM_WRITE(unsigned int nBytes)
{
int i;
LCD_CMD(0X40);
for(i=0;i<nBytes;i++)
LCD_DISPLAY(CGRAM_LUT[i]);
}

