
#include <LPC17xx.h>
unsigned int j,k,led; 
int main(void)
{
	SystemInit(); //Add these two function for its internal operation
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;
 
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	LPC_GPIO2->FIODIR |= 0xFFFFEFFF;
 
	while(1){
        k = LPC_GPIO2->FIOPIN >> 12; //We read input from 2.12
        k &= 0x00000001;
 
		if(k==1)
				led*=2;
		else
				led/=2;
		if(led==256)
			led=1;
		if(led==0)
			led=128;
 
 
		LPC_GPIO0->FIOPIN=led<<4;
    for(j=0;j<100000;j++);
	}
}