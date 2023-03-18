#include<stdio.h>
#include<stdlib.h>
int opcount=0;
void bubblesort(int *a, int n){
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			++opcount;
			if(a[j]<a[i]){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;

			}
		}
	}

}
int main(){
	int n;
	printf("Enter number of elements in array\n");
	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));
	printf("Enter elements in array:\n");
	for(int i=0;i<n;i++){
		printf("Enter element no %d \n",i+1);
		scanf("%d", &a[i]);
	}
	bubblesort(a,n);
	printf("Sorted array is : \n");
	for(int i=0;i<n;i++){
	printf(" %d ",a[i]);
		
	}
	printf("Opcount is: %d",opcount);
	return 0;

}
