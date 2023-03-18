#include<stdio.h>

int towerofhanoi(int n, char src, char dest, char aux){
    int step=1;
if(n==1){
        printf("Moving disc from peg %c to peg %c\n",src,dest);
}
else{
    step+= towerofhanoi(n-1,src,aux,dest);
        towerofhanoi(1,src,dest,aux);
    step+=towerofhanoi(n-1,aux,dest,src);
}
return step;
}
int main(){
    int n,move;
    printf("Enter the number of discs:\n");
    scanf("%d",&n);
    char A,B,C;
    printf("A is source peg, B is destination peg, C is intermediate peg\n");
    move=towerofhanoi(n,'A','B','C');
    printf("No. of moves is: %d",move);
    return 0;


}