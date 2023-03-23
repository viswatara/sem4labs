#include<stdio.h>
#include<stdlib.h>

int opcount=0;
int count=0;

struct node{
int val;
struct node *left, *right;
};

typedef struct node *NODE;

NODE root=NULL;

NODE insert(int ele, NODE node){
NODE temp;

if(node == NULL) {
temp= (NODE)malloc(sizeof(struct node));
temp->val=ele;
temp->left = temp->right=NULL;
if(root == NULL)
root=temp;
return temp;
}

else if(ele < node->val) {
node->left = insert(ele, node->left);
return node;
}

else if(ele > node->val) {
node->right = insert(ele,node->right);
return node;
}

else {
printf( "Duplicate element found while inserting. Insertion failed \n");
return NULL;
}
}

int nodecount(NODE node){
	opcount++;
		if(node==NULL){
			return 0;
		}
		else{
			return 1+ nodecount(node->left) + nodecount(node->right);
		}
		

	}  
	

void main() {
int choice,ele;
do {
printf("1. Insert an element\n");
printf("2. Find no of nodes of BST\n");
printf("3. Exit\n");
printf("Please enter your choice");
scanf("%d",&choice);
switch(choice) {
case 1: printf("Insertion : Please enter an element\n");
scanf("%d", &ele);
insert(ele,root);
break;
case 2: printf("No of nodes of BST : %d\n",nodecount(root));
printf("Opcount= %d",opcount);
break;
case 3: break;
default: printf("Invalid choice. Please enter valid choice\n");
break;
}
}while(choice != 3);
}