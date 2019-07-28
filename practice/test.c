#include <stdio.h> 
#include<conio.h>
#include<string.h>
  
int main(int argc, char *argv[]) 
{   
    int i;
    for(i=0; i<argc; i++)
       printf("%s ", argv[i]);
    return 0;
          
}
