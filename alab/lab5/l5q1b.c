#include <stdio.h>
#include <stdlib.h>
char del[50];
int delt=0;
int colsearch(int v, int mat[v][v], int j){
	int i;
	for(i=0;i<v;i++){
		if(mat[i][j]==1){
			return 1;
		}
	}
	return 0;
}
int alreadydel(char i){
	for(int j=0;j<50;j++){
		if(i==del[j]){
			
			return 1;
		}
	}
	return 0;
}
void deloutgoing(int v, int mat[v][v],int i){
	int j;
	del[delt++]=i+65;
	for(j=0;j<v;j++){
		mat[i][j]=0;
}
}
void main(){
	int v, i,j,ans;
	char temp;
	int ind=0;
	printf("Enter number of vertices: ");
	scanf("%d",&v);
	char toporder[v];
	int mat[v][v];
	int ch=65;
	for(i=0;i<v;i++){
		for(j=0;j<v;j++){
			printf("Does %c have a connection with %c(1,0)", i+65,j+65);
			scanf("%d",&ans);
		}
	}
		/*for(i=0;i<v;i++){
			for(j=0;j<v;j++){
				printf("%d",mat[i][j]);
			}
			printf("\n");
		} */
		for(int k=0;k<v;k++){
			for(i=0;i<v;i++){
			char x=65+i;
			if(colsearch(v,mat,i)==0 && alreadydel(x)==0){
				toporder[ind++]=x;
				deloutgoing(v,mat,i);
				break;
			}
		}
				
	}
		
		for(i=0;i<v;i++){
			printf("%c ",toporder[i]);
		}
	}
/*
void srcrem(int ** arr, int n, int **adj){
	int flag;
	int count=0;
	int i,j,k;
	while(count<n){
		for(i=0;i<n;i++){
			if(arr[i][i]!=1){
				flag=0;
				for(j=0;j<n;j++){
					if(adj[j][i]==1){
						flag=1;
						break;
					}
				}
				if(flag==1){
					continue;
				}
				else{
					count++;
					printf("%d",i+1);
					arr[j][i]=1;
					for(k=0;k<n;k++){
						adj[i][k]=0;
					}
				}
			}
		}
	}
}
int dag(int **arr, int ** adj,int n,int i){
	int j;
	if(arr[1][i]==1){
		return 1;
	}
	int x=0;
	arr[1][i]=1;
	for(j=0;j<n;j++){
	if(adj[i][j]==1){
		x=dag(arr,adj,n,j);
		if(x==1){
			return 1;
		}
	}
	}
	return x;
}
void main(){
	int n,i,j,x;
	printf("Enter number of vertices: ");
	scanf("%d",&n);
	int **adj=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++){
		adj[i]=(int *)malloc(n*sizeof(int));
	}
	int ** arr=(int **)malloc(2*sizeof(int *));
	for(i=0;i<2;i++){
		arr[i]=(int*)malloc(n*sizeof(int));
	}
	printf("Enter adj matrix \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d", &adj[i][j]);
		}
	}
	for(i=0;i<n;i++){
		arr[0][i]=i+1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			arr[1][j]=0;
		}
		x=dag(arr,adj,n,i);
		if(x==1){
			break;
		}
	}
	if(x==1){
		printf("Not dag");
	}
	else{
		for(i=0;i<n;i++){
			arr[1][j]=0;}
			srcrem(arr,n,adj);

	}
	
} */



/*int queue[100], k_1 = 0, k = 0, arr[100][100], n, indegree[100];
 
void calc() {
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
			if(arr[j][i] && i!=j) {
    			indegree[i]++;
			}
		}
	}
}
void initQueue() {
	for(int i = 0; i<n; i++) {
    	queue[i] = 1;
	}
}
void dec(int v) {
	for(int i = 0; i<n; i++) {
		if(arr[v][i]) {
			indegree[i]--;
		}
		if(indegree[i] == 0) {
    		queue[k++] = i;
		}
	}
}
int queueEmpty() {
	for(int i = 0; i<n; i++) {
		if(queue[i] != -1) {
    		return 0;
		}
	}
	return 1;
}

int main() {
	printf("Enter the Number of Vertices : \n");
	scanf("%d", &n);
	printf("Enter the Adjacency Matrix : \n");
	for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++) {
    		scanf("%d", &arr[i][j]);
		}
	}
	initQueue();
	calc();
	for(int i = 0; i<n; i++) {
		if(indegree[i] == 0) {
    		queue[k++] = i;
		}
	}
	printf("The Topological Sort Order is : \n");
	while(!queueEmpty()) {
		int vertex = queue[k_1++];
		printf("%d ", vertex);
		queue[k_1-1] = -1;
		dec(vertex);
		printf("%d ", vertex);
	}
	printf("\n");
	return 0;
}
*/
