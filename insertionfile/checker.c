#include <stdio.h>
#include <stdlib.h>

int main()
{
FILE *ptr=fopen("empty.txt","r");
int n,x,y;
fscanf(ptr,"%d",y);
for(int i=0;i<n;i++)
{
fscanf(ptr,"%d",x);
if(x<y){printf("NO");break;}
y=x;
}
fflush(ptr);
fclose(ptr);
}
