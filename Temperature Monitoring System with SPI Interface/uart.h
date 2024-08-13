#include <LPC21xx.H>
//#include "lcd four.h"
void UART0_INIT(void);
void UART0_TX(char);
void UART0_STR(char*);
unsigned char UART0_RX(void);
void UART0_INTEGER(signed int );
// int main()
// {
// int i;
// char rx[20];
// UART0_INIT();
// while(1)
// {
// for(i=0;i<20;i++)
// {
// rx[i]=UART0_RX();
//       if(rx[i]=='\r')
//      {
// 		break;
// 	}
// }	
// rx[i]= '\0';
// UART0_STR(rx);
//    }
// }
// unsigned char UART0_RX(void)
// {							
// while((U0LSR&1)==0);
// return U0RBR;
// }
void UART0_STR(char *s)
{
//while(*s)
//UART0_TX(*s++);
int i;
for(i=0;s[i];i++)
UART0_TX(s[i]);
}
void UART0_INIT(void)
{
PINSEL0=0X00000005; // select functionality
U0LCR=0X83; // select 8N1 & DLAB as 1
U0DLL=97; // set baud rate
U0LCR=0X03; // again DLAB as clear
}
void UART0_TX(char d)
{
while((U0LSR>>5&1)==0);
U0THR=d;
}
void UART0_INTEGER(signed int n)
{
	char arr[5];
	int i=0;
	if(n==0)
		UART0_TX('0');
	else
	{
		if(n<0)
		{
			UART0_TX('-');
			n=-n;
		}
		while(n>0)
		{
			arr[i++]=n%10;
			n=n/10;
		}
		for(--i;i>=0;i--)
		UART0_TX(arr[i]+48);
	}
}