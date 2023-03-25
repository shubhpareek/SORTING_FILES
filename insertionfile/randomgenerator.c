#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main()
{
FILE*ptr = fopen("file1.txt","w");
srand(time(0));

for(int i = 0; i<500000; i++)
        fprintf(ptr,"%d ", rand());
 
}

