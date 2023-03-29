#include<stdio.h>
#include<stdlib.h>
int flag=0;
typedef struct node *bst;
struct node{
	int data;
	bst lchild;
	bst rchild;
};
bst newnode(int item){
	bst temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->lchild=NULL;
	temp->rchild=NULL;
	return temp;

}
bst createBST(bst root,int item){
	if(root==NULL){
		return newnode(item);
	}
	else if(item==-1){
		return root;
	}
	else if(item<root->data){
		root->lchild=createBST(root->lchild,item);
	}
	else if(item>root->data){
		root->rchild=createBST(root->rchild,item);

	}
	
	else {
		printf("Key found\n");
		flag=1;
		return root;

	}
	

	return root;
}
void inorder(bst root){
	if(root){
		inorder(root->lchild);
		printf("%d ", root->data);
		inorder(root->rchild);
	}

}
void preorder(bst root){
	if(root){
		printf("%d ", root->data);
		preorder(root->lchild);
		preorder(root->rchild);
	}

}
void postorder(bst root){
	if(root){
		postorder(root->lchild);
		postorder(root->rchild);
		printf("%d ", root->data);
	
	}

}
int main(){
	bst root;

	int item;
	printf("Enter root data");
	scanf("%d",&item);
	root=newnode(item);
	
	while(item!=-1&&flag==0){
		printf("Enter key(-1 to stop)");
		scanf("%d",&item);
		createBST(root,item);
	}
	int key;
	
	printf("Inorder traversal is :");
	inorder(root);
	printf("\nPreorder traversal is:");
	preorder(root);
	printf("\nPostorder traversal is :");
	postorder(root);
	return 0;
}

