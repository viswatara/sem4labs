#include<stdio.h>
#include<stdlib.h>
#define max 40
int adj[max][max];
int dist[max][max];
int n;

void createGraph() {

    int i, max_edge, origin, destin,wei;

 

    printf("Enter number of nodes : ");

    scanf("%d", &n);

    max_edge = n * (n - 1);

 

    for (i = 1; i <= max_edge; i++) {

        printf("Enter edge %d( 0 0 ) to quit : ", i);

        scanf("%d %d", &origin, &destin);

        if ((origin == 0) && (destin == 0))

            break;

        if (origin > n || destin > n || origin <= 0 || destin <= 0) {

            printf("Invalid edge!\n");

            i--;

        } else{

            adj[origin][destin] = 1; 
        }
        printf("Enter distance");
        scanf("%d",&wei);


        if (wei<= 0) {

            printf("Invalid distance!\n");

            i--;

        } else{

            dist[origin][destin] = wei; }



    }

}
void displayadj() {

    int i, j;

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= n; j++)

            printf("%4d", adj[i][j]);

        printf("\n");

    }

}
void displaydist() {

    int i, j;

    for (i = 1; i <= n; i++) {

        for (j = 1; j <= n; j++)

            printf("%4d", dist[i][j]);

        printf("\n");

    }

}
void displayarrow(){
	int i,j;
	for (i = 1 ;i <= n; i++) {
		printf("%d",i);

        for (j = 1; j <= n; j++){

        

            if(adj[i][j]==1){
            	printf("->%d",j);

            }

        

    }
    printf("\n");

}
}
int main(){


    int node, origin, destin;

    createGraph();
    printf("\nAdjacency matrix is:\n");
    displayadj();
    printf("\nDistance Matrix is:\n");
    displaydist();
    displayarrow();


    return 0;

}

