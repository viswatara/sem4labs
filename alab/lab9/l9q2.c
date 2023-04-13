#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void initialize(int **hash_table,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            hash_table[i][j] = 0;
        }
    }

}

void Open_Hashing(int *arr,int **hash_table,int n)
{
    initialize(hash_table,n);
    int m = n;
    int k = 0;
    for(int i=0;i<n;i++)
    {
        if(hash_table[arr[i] % m][0] != 0)
            hash_table[arr[i]%m][++k] = arr[i];
        else
            hash_table[arr[i] % m][0] = arr[i];
    }
    for(int i= 0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(hash_table[i][j] != 0 || j == 0)
                printf("%d ",hash_table[i][j]);
        }
        printf("\n");
    }
}

void search(int **hash_table,int n,int searchele)
{
    int i = searchele % n;
    for(int j=0;j<n;j++)
    {
        if(hash_table[i][j] == searchele)
        {
            printf("\nElement found");
            return;
        }
    }
    printf("\nElement not found");
}

int main()
{
    int n,searchele;
    printf("Enter the mod function:");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    
    printf("\nEnter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search");
    scanf("%d",&searchele);
    int **hash_table = (int**)malloc(n*sizeof(int*));
    
    for(int i=0;i<n;i++)
    {
        hash_table[i] = (int*)malloc(n*sizeof(int));
    }
    printf("The hash table is:\n");
    Open_Hashing(arr,hash_table,n);
    search(hash_table,n,searchele);
    return 0;
}
