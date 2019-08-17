#include <stdio.h> 
#include<conio.h>
#include<string.h>

void display(int r, int c, int A[][20]) {
		int i, j;
		for(i=0; i<r; i++){
			for(j=0; j<c; j++){
				printf("%d ",A[i][j]);
			}
			printf("\n");
		}
}
  
int main() 
{   
   int A[20][20],i,j;
   for(i=0; i<3; i++){
   	 for(j=0; j<3; j++){
   	 	 scanf("%d ",&A[i][j]);	
		}
	 }
   display(3,3,A);
   return 0;       
}
