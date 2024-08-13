void UART0_INIT(void);
void UART0_TX(char);
void UART0_STR(char*);
unsigned char UART0_RX(void);
char s[20];
char rx[5];
char * UART_PRO(void)
{
int i,j;
char r;
UART0_INIT();
while(1)
{
for(i=0,j=0;i<20;i++)
{
	r=U0RBR;
	if((rx[i]=key_scan())!='@')
	{
		if(rx[i]=='\n')
			continue;
		if(rx[i]=='@')
			continue;
	//if(rx[i]!=rx[0])
	UART0_TX(rx[i]);
	
	LCD_DATA('*');
	}
    if(rx[i]=='@')
     {
			 rx[i]= '\0';
			 return rx;
	 }
 } 
}	
 }
unsigned char UART0_RX(void)
{							
while((U0LSR&1)==0);
return U0RBR;
}
void UART0_STR(char *s)
{
int i;
for(i=0;s[i];i++)
UART0_TX(s[i]);
}
void UART0_INIT(void)
{
PINSEL0|=0X00000005; 
U0LCR=0X83; 
U0DLL=97; 
U0LCR=0X03; 
}
void UART0_TX(char d)
{
while((U0LSR>>5&1)==0);
U0THR=d;
}
