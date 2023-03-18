#include<stdio.h>
int opcount=0;
int fib(int n){
	++opcount;
if(n==0){
	return 0;
}
else if(n==1){
	return 1;
}
else{
	return fib(n-1)+fib(n-2);
}

}

int main(){
	int n,k;
	printf("Enter the value of n:");
	scanf("%d",&n);
	k=fib(n);
	printf("The nth number in fibonacci sequence is %d\n", k);
	printf("Opcount is %d",opcount);
	return 0;
}