 #include<stdio.h>
 void multiply(int matrix1[50][50], int r1, int c1, int matrix2[50][50], int r2, int c2,int matrix3[50][50]){
		static int i=0;
		static int j=0;
		static int k=0;
		
		if(i>=r1){
			return;
		}
		else if(i<r1){
			if(j<c2){
				if(k<c1){ 
					(matrix3[i][j]) += (matrix1[i][k]) * (matrix2[k][j]);
					k++;
					multiply(matrix1,r1,c1,matrix2,r2,c2,matrix3);
				}
				k=0;
				j++;
				multiply(matrix1,r1,c1,matrix2,r2,c2,matrix3);
			}
			j=0;
			i++;
			multiply(matrix1, r1,c1,matrix2,r2,c2,matrix3);
		}
	}

int main(){
	int r1,c1,r2,c2;
	int matrix1[50][50], matrix2[50][50],matrix3[50][50];
	printf("Enter number of rows and columns respectively in matrix 1: ");
	scanf("%d %d",&r1, &c1);
	printf("Enter number of rows and columns respectively in matrix 2: ");
	scanf("%d %d",&r2, &c2);
	if(c1!=r2){
		printf("Matrix multiplication not possible!\n");
	}
	else{
	
		printf("Enter elements of matrix 1:\n");
		for(int i=0;i<r1;i++){
			for(int j=0;j<c1;j++){
				printf("Enter element [%d][%d]:\n",i,j);
				scanf("%d",&matrix1[i][j]);
			}
		}
		printf("Enter elements of matrix 2:\n");
		for(int k=0;k<r2;k++){
			for(int l=0;l<c2;l++){
				printf("Enter element [%d][%d]:\n",k,l);
				scanf("%d",&matrix2[k][l]);
			}
		}
		multiply(matrix1, r1,c1,matrix2,r2,c2,matrix3);
		printf("Product matrix is : \n");
		for(int g=0;g<r1;g++){
			for(int h=0;h<c2;h++){
				printf(" %d ",matrix3[g][h]);
			}
			printf("\n");
		}

	}
	return 0;

} 

/*#include <stdio.h>

 

void multiply(int, int, int [][10], int, int, int [][10], int [][10]);

void display(int, int, int[][10]);

 

int main()

{

    int a[10][10], b[10][10], c[10][10] = {0};

    int m1, n1, m2, n2, i, j, k;

 

    printf("Enter rows and columns for Matrix A respectively: ");

    scanf("%d%d", &m1, &n1);

    printf("Enter rows and columns for Matrix B respectively: ");

    scanf("%d%d", &m2, &n2);

    if (n1 != m2)

    {

        printf("Matrix multiplication not possible.\n");

    }

    else

    {

        printf("Enter elements in Matrix A:\n");

        for (i = 0; i < m1; i++)

        for (j = 0; j < n1; j++)

        {

            scanf("%d", &a[i][j]);

        }

        printf("\nEnter elements in Matrix B:\n");

        for (i = 0; i < m2; i++)

        for (j = 0; j < n2; j++)

        {

            scanf("%d", &b[i][j]);

        }

        multiply(m1, n1, a, m2, n2, b, c);

    }

    printf("On matrix multiplication of A and B the result is:\n");

    display(m1, n2, c);

}

 

void multiply (int m1, int n1, int a[10][10], int m2, int n2, int b[10][10], int c[10][10])

{

    static int i = 0, j = 0, k = 0;

 

    if (i >= m1)

    {

        return;

    }

    else if (i < m1)

    {

        if (j < n2)

        {

            if (k < n1)

            {

                c[i][j] += a[i][k] * b[k][j];

                k++;

                multiply(m1, n1, a, m2, n2, b, c);

            }

            k = 0;

            j++;

            multiply(m1, n1, a, m2, n2, b, c);

        }

        j = 0;

        i++;

        multiply(m1, n1, a, m2, n2, b, c);

    }

}

 

void display(int m1, int n2, int c[10][10])

{

    int i, j;

 

    for (i = 0; i < m1; i++)

    {

        for (j = 0; j < n2; j++)

        {

            printf("%d  ", c[i][j]);

        }

        printf("\n");

    }

} */