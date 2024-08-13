void otp(unsigned char*p);
void SMS(unsigned char*num,unsigned char* MSG,unsigned char*p);
void gsmpro(char* s)
{
	int i;
	unsigned char p[4];
	UART0_INIT();
	otp(p);
	SMS("+917708431541","THIS IS YOUR OTP",p);
	for(i=0;i<4;i++)
	s[i]=p[i];
	s[i]='\0';
}
void SMS(unsigned char*num,unsigned char*MSG,unsigned char*p)
{
	UART0_STR("AT\r\n");//CHECK COMMUNICATIO MODULE

	delay_milliseconds(10);
	
	UART0_STR("AT+CMGF=1\r\n");//SET SMS MODE
	
	delay_milliseconds(10);

	UART0_STR("AT+CMGS=");//SET MSG&NUM
	UART0_TX('"');
	
	while(*num)
			UART0_TX(*num++);//ONE BY ONE NUM
		UART0_TX('"');
	UART0_STR("\r\n");

	delay_milliseconds(10);
	
	while(*MSG)
			UART0_TX(*MSG++);//ONE BY ONE MSG
	UART0_STR("\r\n");
	
	
	delay_milliseconds(10);
	while(*p)
		UART0_TX(*p++);
		UART0_TX(0X1a);//END OF TEXT
	delay_milliseconds(10);
}
void otp(unsigned char*p)
{
	int i;
	for(i=1000;i<=9999;i++)
	{
		if(i==9999)
		{
			i=1000;
		}
		if((IOPIN0&1<<15)==0)
			break;
}
sprintf(p,"%d",i);
}