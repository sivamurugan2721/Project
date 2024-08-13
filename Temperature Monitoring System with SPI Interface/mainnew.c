#include <LPC21xx.h>
#include "types.h"
#include "spi.h"
#include "mcp3204.h"
#include "lcd.c"
#define PIN1 1<<17
#define PIN2 1<<18
main()
{
	f32 f;
	IODIR0|=PIN1|PIN2;
	IOSET0|=PIN1|PIN2;
	Init_SPI0(); //hw SPI initialisation
	LCD_INIT();	
	LCD_STR("TEMP deg");
	LCD_STR("   FAN");
	IOPIN0 |= 1<<7;
  while(1)
  {
    f=Read_ADC_MCP3204(0);
		LCD_COMMAND(0xc0);
		LCD_FLOAT(f);
		delay_milliseconds(500);
 	if(f>=30)
 		{
 			IOSET0=PIN1;
		IOCLR0=PIN2;
			LCD_STR("   ON");
		}
		else
		{
	IOSET0|=PIN1|PIN2;
		LCD_STR("     OFF");
}
}
}