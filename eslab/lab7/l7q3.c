#include <LPC17xx.h>
#include <stdio.h>
unsigned int tohex[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
unsigned int arr1[4]={0,0,0,0};
unsigned int arr2[4]={9,9,9,9};
unsigned int i,j;
int main(){
	LPC_GPIO0->FIODIR|=0xFF0;//because cna p0.4 to p0.11 are output pins
	//LPC_GPIO2->FIODIR|=0xF<<21;//because cnc pin 7 is connected to p2.21
	LPC_GPIO1->FIODIR|=0xF<<23;//because cnb p1.23 to p1.26 are output pins
	while(1){
	if((LPC_GPIO0->FIOPIN &1<<21)==0){
	//while(1){
		for(arr2[3]=9; arr2[3]>=0; arr2[3]--)
	     for(arr2[2]=9; arr2[2]>=0; arr2[2]--)
	           for(arr2[1]=9; arr2[1]>=0; arr2[1]--)
	                 for(arr2[0]=9; arr2[0]>=0; arr2[0]--)
		{
           		      for(i=0; i<4; i++)
		      {
			LPC_GPIO1->FIOPIN=i<<23;
			LPC_GPIO0->FIOPIN=tohex[arr2[i]]<<4;
			for(j=0; j<1000; j++);
		      }
		      for(j=0; j<1000; j++);
		      LPC_GPIO0->FIOCLR|=0X00000FF0;
		}
		 
      }
	
			//}

	else{
		//while(1){
		for(arr1[3]=0;arr1[3]<10;arr1[3]++)
			for(arr1[2]=0;arr1[2]<10;arr1[2]++)
				for(arr1[1]=0;arr1[1]<10;arr1[1]++)
					for(arr1[0]=0;arr1[0]<10;arr1[0]++){
						for(i=0;i<4;i++){
							LPC_GPIO1->FIOPIN=i<<23;
							LPC_GPIO0->FIOPIN=tohex[arr1[i]]<<4;
							for(j=0;j<1000;j++);
						}
						for(j=0;j<1000;j++);
						LPC_GPIO0->FIOCLR|=0xFF0;
					}
		
	
}
}
	}
	
