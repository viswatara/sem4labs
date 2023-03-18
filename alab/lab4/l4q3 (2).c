#include <stdio.h>

int adj[20][20];
int no_of_v;
int visited[20];
int queue[20], front=0,rear=0;

void enqueue(int v){
	queue[++rear]=v;

}
int dequeue(){
	if(front==rear)
		return -1;
	return queue[front++];
}
void bfsvisit(int v){
	printf(" Visiting : %d \n",v+1);
	visited[v]=1;
	for(int i=0;i<no_of_v;++i){
		if(!visited[i] && adj[v][i] && i!=v){
			enqueue(i);
		}
	}
}
void bfs(){
	int k;
	enqueue(0);
	do{
		k=dequeue();
		if(k!=-1 && !visited[k]){
			bfsvisit(k); }
	  }while(k!=-1);
	}

int main(){
	printf("Enter number of vertices: ");
	scanf("%d",&no_of_v);
	printf("Enter adjacency matrix: \n");
	for(int i=0;i<no_of_v;i++){
		for(int j=0;j<no_of_v;j++){
			printf("Enter ele [%d][%d]: ",i,j);
			scanf("%d",&adj[i][j]);
		}
	}
	bfs();
	return 0;

}
