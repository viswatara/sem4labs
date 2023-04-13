#include<stdio.h>
#include<stdlib.h>
int opcount=0;
void warshall(int **adj, int **result, int n) {
    result = adj;
    int **resultK = result; 
    for (int k = 0; k<n; k++) {
        for(int i = 0; i<n; i++) {
            for (int j=0; j<n; j++) {
            	opcount++;
                result[i][j] = (resultK[i][j] || (resultK[i][k] && resultK[k][j]));
            }
        }
        resultK = result;
    }
    printf("Transitive closure: \n");
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++)
            printf("%d\t", result[i][j]);
        printf("\n");
    } 
}
 
void main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    int ** adj = (int**) malloc(n*sizeof(int*));
    for (int r = 0; r < n; r++) {
        adj[r] = (int *)malloc(n * sizeof(int));
    }
    int ** result = (int**) malloc(n*sizeof(int*));
    for (int r = 0; r < n; r++) {
        result[r] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the adjacency matrix: ");
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++)
            scanf("%d", &adj[i][j]);
    printf("Adjacency Matrix: \n");
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++)
            printf("%d\t", adj[i][j]);
        printf("\n");
    } 
    warshall(adj, result, n);
    printf("Opcount is %d\n",opcount);
}
