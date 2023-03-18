#include<stdio.h>
#include<string.h>
int opcount=0;
void stringmatch(char *str, char *sub){
	
	int flg=0;
	int j;
	/*for(int i=0;i<n-m;i++){
		int j=0;
		while(j<m){
			++opcount;  
			if(str[j]==sub[j+i]){
			j++;
		}
			else{
				break;
			}
		}
			                   
			if(j==m){
				flg=1;
				printf("Pattern found at position %d",i);
				break;

			} }

			if(flg==0){
				printf("Pattern not found\n");

			}
			printf("Opcount is %d ",opcount); */
	 for (int i=0; i <= strlen(str) - strlen(sub); i++){
        j=0;
        while( j < strlen(sub)){
            opcount++;
            if(str[i+j] == sub[j])
                j++;
            else
                break;
        }
        if(j == strlen(sub)){
            printf("Found at position %d\n", i);
            flg = 1;
            break;
        }
    }
    if (flg==0)
        printf("Pattern not found\n");
    printf("Opcount is %d\n",opcount);
			
			
		}
		
			

	int main(){
		char str[50];
		char sub[50];
		printf("Enter string\n");
		scanf("%s", str);
		printf("Enter pattern to match\n");
		scanf("%s",sub);
	
		stringmatch(str,sub);
		return 0;
	}




