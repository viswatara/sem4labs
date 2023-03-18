#include<stdio.h>
#include<stdbool.h>
bool  subset(int *arr, int sum,int n){
	if(sum==0){
		return true;
	}
	if(n==0){
		return false;
	}
	if(arr[n-1]>sum){
		return subset(arr,sum,n-1);

	}
	return subset(arr,sum-arr[n-1],n-1)|| subset(arr,sum,n-1);

}
int main(){
	int n,sum;
	printf("Enter number of elements in set:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter elements in set:");
	for(int i=0;i<n;i++){
	scanf("%d",&arr[i]);
}
bool x=false;
printf("Enter sum to find:");
scanf("%d",&sum);
x=subset(arr,sum,n);
if(x==true){
	printf("Subset exists");
}
else{
	printf("Subset doesn't exist");
}


return 0;
}