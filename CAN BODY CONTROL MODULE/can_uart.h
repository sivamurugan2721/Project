#define THRE (U0LSR&(1<<5))
#define RDR  (U0LSR&0x1)
void uart0_init(int baud)
{ 
	PINSEL0 |= 5;//P0.0=TXD0, P0.1=RXD0
	U0LCR=0x83;//DLAB=1, WORD LENGTH=8bits, PARITY=Disabled,No of Stop Bits=1

	switch(baud)	//setting baudrate
	{	
//		case 4800:	U0DLL=195;break;//4800bps

//		case 7200:	U0DLL=130;break;//7200bps

//		case 9600:	U0DLL=195;break;//9600bps

//		case 57600:	U0DLL=16;break;//9600bps

		case 115200:U0DLL=32;break;//@PCLK=60MHz

//		default: 		U0DLL=195;//for PCLK=30MHz

	}	

	U0LCR=0x3;////DLAB=0, WORD LENGTH=8bits, PARITY=Disabled,No of Stop Bits=1
}
void uart0_tx(U8 data)
{
	U0THR=data; 
	while (THRE == 0);
}
void uart0_string(char *s)
{
	while(*s)
		uart0_tx(*s++);
}
void uart0_integer(int n)
{
U8 arr[5];
	int i=0;
	if(n==0)
		uart0_tx('0');
	else
	{
		if(n<0)
		{
			uart0_tx('-');
			n=-n;
		}
		while(n!=0)
		{
			arr[i++]=n%10;
			n=n/10;
		}
		for(--i;i>=0;i--)
		uart0_tx(arr[i]+48);
	}
}
