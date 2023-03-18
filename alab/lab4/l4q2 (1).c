#include <stdio.h>
#include <stdlib.h>
	
int adj[10][10];
int no_of_v;
int visited[10];
void dfsv(int v)
{
	printf("Visiting %d\n", (v+1));
	visited[v] = 1;
	for(int i = 0; i < no_of_v; ++i)
		{
			if(!(visited[i]) && (adj[v][i] == 1) && (i != v))
	  			dfsv(i);
		}
}
void dfs()
{
	int i;
	for(i = 0; i < no_of_v; ++i)
	{
		if(!visited[i])
	  		dfsv(i);
	}
}
int main()
{
printf("Enter the Number of Vertices: \n");
scanf("%d", &no_of_v);
int i, j;
printf("Enter the Adjacency Matrix: \n");
for(i = 0; i < no_of_v; ++i)
	{
   		for(j = 0; j < no_of_v; ++j)
			scanf(" %d", &adj[i][j]);
	}
dfs();
return 0;
}