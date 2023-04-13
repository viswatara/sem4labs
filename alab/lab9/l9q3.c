#include <stdio.h>
#include<stdlib.h>
int keycomp=0;
void insert(int *arr,int tablesize)
{
  int key, index, i, flag=0, hkey;
  printf("Enter a Value to Insert into the Hash Table : \n");
  scanf("%d", &key);
  hkey = key % tablesize;
 
  for(i = 0 ; i < tablesize ; i++)
  {
    index = (hkey + i) % tablesize;
    if(arr[index] == 0)
    {
      arr[index] = key;
      break;
    }
  }
 
  if(i == tablesize)
    printf("The Element cannot be Inserted\n");
}
 
void search(int *arr,int tablesize)
{
  int key, index, i, flag=0, hkey;
 
  printf("Enter the Search Element : \n");
  scanf("%d", &key);
 
  hkey = key % tablesize;
 
  for(i = 0 ; i <tablesize ; i++)
  {
    keycomp++;
    index = (hkey + i) % tablesize;
 
    if(arr[index] == key)
    {
      printf("Value is Found at Index %d\n", index);
      keycomp++;
      printf("No of key comparisons in successful search is: %d", keycomp);
      break;
    }
  }
 
  if(i == tablesize){
    printf("Value is not Found\n");
    keycomp++;
    printf("No of key comparisons in successful search is: %d", keycomp);
 
  }
}
 
void display(int *arr, int tablesize)
{
  int i;
 
  printf("Elements in the Hash Table are : ");
 
  for(i = 0 ; i < tablesize ; i++)
    printf("\nat Index %d  Value =  %d",i,arr[i]);
 
}
 
int main()
{
  int op, i,tablesize;
  printf("Enter table size");
  scanf("%d",&tablesize);
  int arr[tablesize];
  for(int i=0;i<tablesize;i++){
    arr[i]=0;
  }
  while(1)
  {
    printf("\nEnter 1. Insert 2. Display 3. Search 4.Exit : \n");
    scanf("%d", &op);
    switch(op)
    {
      case 1:
        insert(arr,tablesize);
        break;
      case 2:
        display(arr,tablesize);
        break;
      case 3:
        search(arr,tablesize);
        break;
      case 4: 
        exit(0);
    }
  }
 
  return 0;
}/*#include<stdio.h>
#include<stdlib.h>


void Closed_Hashing(int *arr,int n,int *hash_table){
    int m = n;
    for(int i=0;i<n;i++)
    {
        if(hash_table[arr[i] % m] != 0)
            search(hash_table,i,arr,n);
        else
            hash_table[arr[i] % m] = arr[i];
    }
}

void search(int *hash_table,int i, int *arr, int n){
    int m=n;
    int flag=0;
    while(i<n){
        i++;
        if(hash_table[arr[i]%m]==0){
            hash_table[arr[i] % m] = arr[i];
            flag=1;
            return;
        }
    }
    if(flag==0){
        int k=i;
        i=0;
        while(i<k){
            if(hash_table[arr[i]%m]==0){
                hash_table[arr[i] % m] = arr[k];
                flag=1;
                return; 
            }
            i++;
        }
       
    }
}



int main()
{
    int n;
    printf("enter the no. of elements:");
    scanf("%d",&n);

    int *arr = (int*)malloc(n*sizeof(int));
    
    printf("\nenter the elements:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int *hash_table = (int*)malloc(n*sizeof(int));
    Closed_Hashing(arr,n,hash_table);
    printf("\nThe hash table is:\n");
     for(int i= 0;i<n;i++){
        printf("%d ",hash_table[i]);
    }
       
} */