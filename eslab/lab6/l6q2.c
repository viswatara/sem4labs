#include<LPC17xx.h>

unsigned int j;
unsigned long LED = 0x00000010;

int main(void)
{
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0X00000FF0;
	LPC_PINCON->PINSEL0 &= 0xFCFFFFFF;
	LPC_GPIO2->FIODIR &= 0XFFFFEFFF;
  
	
		while(1)
		{
			if(LPC_GPIO2->FIOPIN&1<<12){
				for(LED=255;LED>=0;LED--){
					LPC_GPIO0->FIOPIN=LED<<4;
					for(j=0;j<200000;j++);
				}
			}
			else{
			for(LED=0;LED<256;LED++){
				LPC_GPIO0->FIOPIN=LED<<4;
				for(j=0;j<200000;j++);
			}
			}
	}
}

//press sw2 while clicking on start so that upcounter runs, press rest afterwards for downcounter
