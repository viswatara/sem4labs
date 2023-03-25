#include<lpc17xx.h>
int main(){
int count,j,i;
SystemInit();
SystemCoreClockUpdate();
LPC_PINCON->PINSEL0=0XFF0000FF;
LPC_GPIO0->FIODIR=0X00000FF0;
LPC_PINCON->PINSEL2=0XFCFFFFFF;
LPC_GPIO2->FIODIR&=0XFFFFEFFF;
if((LPC_GPIO2->FIOPIN&1<<12)==0){
	while(1){
	count=1;
	for(i=0;i<8;i++){
	LPC_GPIO0->FIOPIN=count<<4;
	for(j=0;j<100000;j++);
	count=count<<1;
	}
}
}
}
