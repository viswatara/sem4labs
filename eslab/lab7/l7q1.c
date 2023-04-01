#include <LPC17xx.h>
unsigned seven_seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int dig_count=0;
unsigned int j,i;
unsigned int dig_value[4]={1,2,3,4};
unsigned int dig_select[] = {3<<23,2<<23,1<<23,0<<23};
void display(){
	LPC_GPIO1->FIOPIN=dig_select[dig_count];
	LPC_GPIO0->FIOPIN=seven_seg[dig_value[dig_count]]<<4;
}
void delay(){
	for(j=0;j<=60000;j++);
}
int main(){
	LPC_GPIO0->FIODIR = 0xFF0;//because cna p0.4 to p0.11 are output pins
	LPC_GPIO1->FIODIR = 0xF<<23;//because cnb p1.23 to p1.26 are ouput pins
	while(1){
			delay();
			display();
			dig_count=(dig_count+1)%4;
	}
}
