#include <stdio.h>
#define MAX_SIZE 10000
int opcount=0;

void getPrime(int n, int *prime)
{	
  	for(int i = 2; i<=n; i++){opcount++;
  	 prime[i] = i;
}
    int i = 2;
    while ((i*i) <= n)
    {
    	opcount++;
        if (prime[i] != 0)
        {
            for(int j=2; j<n; j++)
            {	
            opcount++;
                if (prime[i]*j > n) break;
                else prime[prime[i]*j]=0;
            }
        }
        i++;
	}
	//printf("Opcount in prime generation: %d\n",opcount);
}

int primeFactors(int n,int *factors)
{	
	int prime[MAX_SIZE];
	getPrime(n,prime);
	int factorCount=0;
	int p;
	for(int i=2; i<=n; i++)
	{	
		if(prime[i]==0) continue;
		opcount++;
		p = prime[i];
		if (n%p==0)
		{
			n=n/p;
			factors[factorCount++] = p;
			i--;
		}
	}
	return factorCount-1;
}

int midgcd(int m,int n)
{	
	int factorsM[MAX_SIZE],factorsN[MAX_SIZE],res[MAX_SIZE];
	int factorCountM = primeFactors(m, factorsM);
	int factorCountN = primeFactors(n, factorsN);
	int i=0, j=0,k=0;
	while(i<=factorCountM && j<=factorCountN)
	{	
		opcount++;

		if(factorsM[i]==factorsN[j])
		{
			res[k++] = factorsN[j++];
			i++;
		}
		else if(factorsM[i]<factorsN[j]) i++;
		else if(factorsM[i]>factorsN[j]) j++;
	}
	int gcd = 1;
	for(int a=0; a<k; a++)
	{	opcount++;
		gcd*=res[a];
	}	
	return gcd;
}


int main(){
	int m,n;
	
	printf("Enter m and n values respectively");
	scanf("%d %d",&m,&n);
	if(m==0||n==0){
		printf("Both are zero!!");
	}
	else{
		printf("GCD is: %d\n", midgcd(m,n));
		printf("Total opcount is:%d",opcount);

	}
	return 0;

}