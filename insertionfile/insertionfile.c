			// THIS PROGRAM SORTS FILE CONTENTS USING INSERTION SORT
			// result of sorted content will be in empty.txt , and will be present originally unsorted in file1.txt 

#include <stdio.h>
#include <string.h>

void fpaster (FILE * ptr, FILE * ptr1, int n) // this function will be used to copy contents of the file empty2 back to empty
{

  int x; // will be used for temprory storage 
  
	//  puts ("paste"); // for the sake of debbuging
  
  for (int i = 0; i < n; i++)	// loop scans through the empty2 and prints in empty
    {
      fscanf (ptr, "%d", &x);
      fprintf (ptr1, "%d ", x);
    }

}

int main()
{

FILE* ptr = fopen("file1.txt","r");	// file whose content has to be sorted 
	
FILE* ptr1 = fopen("empty.txt","r+");	// will be used for storing previous element of current element 

int x,n=6,y,end=0,did;		
// x takes input from file1 , y from empty, end counts number in empty, did tells wheather we did insertion apart from the original location or not 
long int k;	// will store current pointer location before scanning element 

fscanf(ptr,"%d",&x);

//printf("%d \n",x);

fseek(ptr1,0,SEEK_SET);

fprintf(ptr1,"%d ",x);// we dont do insertion on the first element , so we start from second element 

end++;// increase end because element in empty has been increased 

//fseek(ptr1,0,SEEK_SET);

fflush(ptr1);// closing just for sake of algorithm

fclose(ptr1);//

//fseek(ptr1,0,SEEK_SET);

for(int i=1;i<n;i++) // insertion sort will be done for all n-1 elements 
{

	did=0;// by default , we havent done anything for this element in this iteration
	
//	printf("%d \n",i);

	fscanf(ptr,"%d",&x); //take the element that has to be inserted
	
//	printf("%d \n",x);
	//fseek(ptr1,0,SEEK_SET);
	
	FILE* ptr0 = fopen("empty.txt","r+"); // open file that will store previous element 
	
	for(int j=0;j<end;j++)		
	{
	
		did=0;
		
		k=ftell(ptr0);// we store location of pointer before scanning just in case we need it 
		
		fscanf(ptr0,"%d",&y); // scan for comparison 
		
//		printf("y %d\n",y);

		if(x<=y)	// if this is the case , it means we need to insert before this element 
		{
		
		FILE* ptr2 = fopen("empty2.txt","w");
		// this file needs to be opened , for storing till k,then inserting x and then again doing the same till end
		
			did=1;// because we are doing insertion now 
			
			fseek(ptr0,0,SEEK_SET);//
			fseek(ptr2,0,SEEK_SET);// just in case if it is not at start
			
			while(ftell(ptr0)!=k)// store till k
			{
				fscanf(ptr0,"%d",&y);
				fprintf(ptr2,"%d ",y);
				
//				printf("i%d ",y);
			}
			
			fprintf(ptr2,"%d ",x);// then insert x
			
//			printf("a %d ",x);
			//j--;
			
			while(j<end)// then store remaining previous elements
			{
				fscanf(ptr0,"%d",&y);
				fprintf(ptr2,"%d ",y);
//				printf("b%d ",y);	
				j++;
			}
			
//			printf("\n");

			end++; // because one element has been inserted and now numbers in empty has increased by 1
			
			fflush(ptr2);//
			fclose(ptr2);// because now we need it for read only
			
			FILE* ptr3 = fopen("empty2.txt","r");
			
			fseek(ptr3,0,SEEK_SET);// just in case
			fseek(ptr0,0,SEEK_SET);
			
			fpaster(ptr3,ptr0,end);// paste from empty2 to empty 
			
			fflush(ptr3);
			fclose(ptr3);// then close 
			
			break;// break and move to next element in file1
			
		}
		
	}
	
	if(!did)// if this is the case , it means we need to insert at the original position only
	{
		fprintf(ptr0," %d ",x);
		/*printf("a1 %d \n",x);*/
		end++;
	} 
fflush(ptr0);

fclose(ptr0);// close and open in next iteration 	


}

fflush(ptr);



fclose(ptr);// close it because the work has been done 

				// THE END :)


//fprintf(ptr1,"\n 1 \n");
//fseek(ptr1,0,SEEK_SET);
//fprintf(ptr1,"        3 ");
//fseek(ptr1,0,SEEK_SET);
//fprintf(ptr1,"        ");
/*while(!feof(ptr1))
{
char c;
long int k=ftell(ptr1);
fscanf(ptr1,"%c",&c);
if(c=='\n')
{fseek(ptr1,k,SEEK_SET);fprintf(ptr1," ");}


}*/
//n--;

//while(n--)
//{



//}

}
