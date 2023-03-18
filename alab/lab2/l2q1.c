#include<stdio.h>
int gcd1(int m, int n){
	int opcount;


opcount=0;

int t=m<n?m:n;

while(t!=0){

	opcount++;
	if(m%t==0){
		if(n%t==0){
			printf("Opcount is:%d\n",opcount);
			return t;
	}
	t--;
	
	continue;
  }

  t--;
  
 }
 printf("Opcount is:%d\n",opcount);
 return 1;
}


int main(){
	int m,n;
	printf("Enter m and n values respectively");
scanf("%d %d",&m,&n);
if(m==0||n==0){
	printf("They are both zeroes!!\n");
}
else{
printf("GCD is %d",gcd1(m,n));
}
	

return 0;
}
