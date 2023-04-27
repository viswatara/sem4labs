    #include<stdio.h>
    #include<stdlib.h>
    int i,j,k=1,a,b,u,v,n;
    int min,mincost=0;
    int find(int i, int *parent)
    {
      while(parent[i])
      i=parent[i];
      return i;
    }
     int uni(int i,int j,int *parent)
    {
      if(i!=j)
      {
        parent[j]=i;
        return 1;
      }
      return 0;
    }

    void main()
    {
    
      printf("\nEnter the no. of vertices:");
      scanf("%d",&n);
      int **cost=(int **)calloc(n,sizeof(int *));
      for(int i=0;i<n;i++){
        cost[i]=(int *)calloc(n,sizeof(int));
      }
      int *parent=(int *)calloc(n,sizeof(int));
      printf("Enter the cost adjacency matrix:\n");
      for(i=0;i<n;i++)
      {
        for(j=0;j<n;j++)
        {
          printf("Enter for [%d][%d]",i,j);
          scanf("%d",&cost[i][j]);
          if(cost[i][j]==0)
            cost[i][j]=999;
        }
      }
      printf("The edges of Minimum Cost Spanning Tree are\n");
      while(k < n)
      {
        for(i=0,min=999;i<n;i++)
        {
          for(j=0;j < n;j++)
          {
            if(cost[i][j] < min)
            {
              min=cost[i][j];
              a=u=i;
              b=v=j;
            }
          }
        }
        u=find(u,parent);
        v=find(v,parent);
        if(uni(u,v,parent))
        {
          printf("edge (%d,%d) =%d\n",a,b,min);
          mincost +=min;
        }
        cost[a][b]=cost[b][a]=999;
      }
      printf("\n\tMinimum cost = %d\n",mincost);
   
    }
    
