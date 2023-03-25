#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
FILE*ptr = fopen("temp1.txt","w");
FILE*ptr1 = fopen("temp2.txt","w");
srand(time(0));

for(int i = 0; i<500000; i++)
{	int x=rand();
        fprintf(ptr,"%d ", x);
        fprintf(ptr1,"%d ", x);}
 
}

