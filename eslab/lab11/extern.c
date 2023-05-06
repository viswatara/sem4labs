#include<LPC17xx.h>

int main(void){
		unsigned int i,j,k;
		LPC_PINCON -> PINSEL4 = (1<<24);
		LPC_GPIO0 -> FIODIR = 0X00000FF0;
		LPC_SC -> EXTMODE =0;
		LPC_SC -> EXTPOLAR =0;
		NVIC_EnableIRQ(EINT2_IRQn);
	
		while(1);
}

void EINT2_IRQHandler(void){
		unsigned int j;
		LPC_GPIO0 -> FIOPIN =~LPC_GPIO0->FIOPIN;
		for(j=0;j<500000;j++);
		LPC_SC -> EXTINT = 1;
}