#include<LPC17xx.h>
unsigned int LED1=0x10;
unsigned int LED2=0xFF0;
unsigned int i,j;
int main(){
  SystemInit();
  SystemCoreClockUpdate();
  
  LPC_PINCON->PINSEL0 &=0xFF0000FF;//config p0.4 to p0.11 as gpio
  LPC_GPIO0->FIODIR|=0xFF0;//set p0.4 to p0.11 as output pins
  LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;//config p2.12 as gpio
  LPC_GPIO2->FIODIR &=0xFFFFEFFF;//set p2.12 as input
  
  while(1){
    if(!(LPC_GPIO2->FIOPIN &(1<<12))){
      LED1=0X10;
      for(i=0;i<256;i++){
        LPC_GPIO0->FIOPIN=LED1;
        for(j=0;j<50000;j++);
        LED1+=0x10;
      }
    }
    else{
      LED2=0xFF0;
      for(i=0;i<256;i++){
        LPC_GPIO0->FIOPIN=LED2;
        for(j=0;j<50000;j++);
        LED2-=0x10;
      }
    }
  }
  return 0;
}
      
      
  
  
  
