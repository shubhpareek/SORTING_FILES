			//              MERGE SORT IN FILE CONTENTS
			
/* so this code contains three files file1,temp3,temp4.  temp3 and temp4 have the random numbers both have same content these files will be used for the two pointers in the bottom up merge sort algorithm. file1 will be used as a temprory file for storing the sorted files and copying back after one iteration is done  , SO FINALLY SORTED FILE CONTENT WILL BE IN temp3 , temp4    */
					/*PLEASE PUT A SPACE AT LAST OF THE INPUT FILE */

#include<stdio.h>

#include<stdlib.h>


void fpaster (FILE * ptr, FILE * ptr1, FILE * ptr2, int n) // this function will be used to copy contents of the file1 back to temp3 and temp4
{

  int x; // will be used for temprory storage 
  
	//  puts ("paste"); // for the sake of debbuging
  
  for (int i = 0; i < n; i++)	// loop scans through the file1 and prints in other two files
    {
      fscanf (ptr, "%d", &x);
      fprintf (ptr1, "%d ", x);
      fprintf (ptr2, "%d ", x);
    }

}

void pointermover (FILE * ptr, int w) // as the algorithm requires jumping file pointer over integers , this function will be used 
{
		//  printf ("pp1 %ld \n", ftell (ptr)); //for the sake of debbuging
		
  for (int i = 0; i < w; i++)
    {
      int x;
      fscanf (ptr, "%d", &x); // this will move the file pointer over w integers
    }
    
  			//printf ("pp1 %ld \n", ftell (ptr));//for the sake of debbuging
  			//puts ("move");
}

void merge (FILE * ptr1, FILE * ptr2, FILE * ptr, int n, int end, int size) 
// this will merge two parts of the file from end - size to end -1 and end to end + size  where end is the middle position of two parts
{

			//  puts ("merge");// for the sake of debbuging

  if (end + size < n)
    {
      int c;
      int k, c1 = 1, k1 = 1, c2 = 0, k2 = 0;// c,k store input values, c1 and k1 tell which file printed the last number
      
   	 hell:;	// for iteration 
    
      if (c1)
	{
	  fscanf (ptr1, "%d", &c);		// scan and store in c
	  		//printf ("c= %d\n", c);//for the sake of debbugind
	  c2++; // count the number's scanned from this file
	}

      if (k1)
	{
	  fscanf (ptr2, "%d", &k);// scan and store in c
	  		//printf ("k= %d\n", k);//for the sake of debbuging
	  k2++; // count the number's scanned from this file
	}

      if (c <= k)
	{
	  fprintf (ptr, "%d ", c);
	  	       //printf ("pc= %d %d\n", c, c2);//for the sake of debbuging
	  c1 = 1;// means c was printed k was not 
	  k1 = 0;
	  
	  if (c2 < size)// if there are still integer remaining
	    {
	      goto hell;
	    }
	}

      if (k < c)
	{
	  fprintf (ptr, "%d ", k);
		 //  printf ("pk= %d %d\n", k, k2);
	  c1 = 0;// means k was printed c was not 
	  k1 = 1;
	  
	  if (k2 < size)// if there are still integer remaining
	    {
	      goto hell;
	    }
	}

      if (k2 <= size && (!k1))  // checks if any integer remaning in the file part, and prints it in the file1
	{
	  fprintf (ptr, "%d ", k);
	  printf ("k= %d\n", k);
	  for (; k2 < size; k2++)
	    {
	      fscanf (ptr2, "%d", &k);
	      fprintf (ptr, "%d ", k);
	      			//printf ("k= %d\n", k);//for the sake of debbuging
	    }
	}
	
      if (c2 <= size && (!c1))  // checks if any integer remaning in the file part, and prints it in the file1
	
	{
	  fprintf (ptr, "%d ", c);
		  	       //printf ("c= %d\n", c);//for the sake of debbuging
	  for (; c2 < size; c2++)
	    {
	      fscanf (ptr1, "%d", &c);
	      fprintf (ptr, "%d ", c);
	      		       //printf ("c= %d\n", c);//for the sake of debbuging 
	    }
	}
	
	
    }
    
  else  // means n-end is less than current size
  
    {
      		//puts ("E");//for the sake of debbuging
      int c;
      int k, c1 = 1, k1 = 1, c2 = 0, k2 = 0;
    // same as previous if statement , the difference is in line 162,168,172. because n - end less than current size
    
    hell1:;
      if (c1)
	{
	  fscanf (ptr1, "%d", &c);
	  			//printf ("c= %d\n", c);//for the sake of debbuging
	  c2++;
	}

      if (k1)
	{
	  fscanf (ptr2, "%d", &k);
				// printf ("k= %d\n", k);//for the sake of debbuging
	  k2++;
	}

      if (c <= k)
	{
	  fprintf (ptr, "%d ", c);
	  			//printf ("pc= %d %d\n", c, c2);//for the sake of debbuging
	  c1 = 1;
	  k1 = 0;
	  
	  if (c2 < size)
	    {
	      goto hell1;
	    }
	}

      if (k < c)
	{
	  fprintf (ptr, "%d ", k);
	  			//printf ("pk= %d %d\n", k, k2);//for the sake of debbuging
	  c1 = 0;
	  k1 = 1;
	  
	  if (k2 < n - end)
	    {
	      goto hell1;
	    }
	}

      if (k2 <= n - end && (!k1))
	{
	  fprintf (ptr, "%d ", k);
			      //printf ("k= %d\n", k);// for the sake of debbuging
	  for (; k2 < n - end; k2++)
	    {
	      fscanf (ptr2, "%d", &k);
	      fprintf (ptr, "%d ", k);
			      //printf ("k= %d\n", k);// for the sake of debbuging 
	    }
	}
      if (c2 <= size && (!c1))
	{
	
	  fprintf (ptr, "%d ", c);
	  //printf ("c= %d\n", c);
	  
	  for (; c2 < size; c2++)
	    {
	      fscanf (ptr1, "%d", &c);
	      fprintf (ptr, "%d ", c);
	    //  printf ("c= %d\n", c);
	  
	    }
	    
	}
	
    }
    
  		//printf ("mm %ld %ld %ld\n", ftell (ptr1), ftell (ptr2), ftell (ptr));

}

long int eoffinder (FILE * ptr) // finds the EOF location of a file 
{
  fseek (ptr, 0, SEEK_END);
  return ftell (ptr);
}

int logfinder (int n)  //finds the number of bits in a number 
{
  int cnt = 0;
  while (n != 0)
    {
      n = (n >> 1);
      cnt++;
    }
  return cnt;

}

int main ()
{


  long int x; // for storing EOF location
  
  FILE *ptr0 = fopen ("temp1.txt", "r+");// this file is being opened just for findin the EOF location
  x = eoffinder (ptr0);
  fclose (ptr0);
  
				//  printf ("%ld\n", x);// just for the sake of debbuging
  
  int n = 500000;			// for storing number of integers in file 
  int v = 0;			// v counts the power of two size has reached 
  int log = logfinder (n);	// stores the number of bits in n
  
  for (int size = 1; v <= log; size *= 2)
    {
    printf("%d\n",v);
      FILE *ptr = fopen ("file1.txt", "r+");

      FILE *ptr1 = fopen ("temp1.txt", "r+");

      FILE *ptr2 = fopen ("temp2.txt", "r+");
      
      for (int st = 0, end = size; end < n; st += size)
	{
			  //printf ("%d %d %d\n", st, end, size);	//just for the sake of debbuging
	  		//printf ("pp %ld %ld %ld\n", ftell (ptr1), ftell (ptr2), ftell (ptr));	//just for the sake of debbuging
	  		
	  if (st)
	    {
	      pointermover (ptr1, size); // jumps pointer according to the required size
	    }
	  
	      pointermover (ptr2, size); // jumps pointer according to the required size

	  if ((ftell (ptr2) < x-1) && (ftell (ptr2) < x - 2)) // makes sure the other pointer does not cross EOF
	    {
	      merge (ptr1, ptr2, ptr, n, end, size);
	    }
	    
	  else // so other pointer is at the end so we just need to print the part of other array in file
	  
	    {
	      for (int i = 0; i < size; i++)
		{
		  int y;
		  fscanf (ptr1, "%d", &y);
		  fprintf (ptr, "%d ", y);

		}
	    }

	  end += size;

	}
      fflush (ptr1);     //  WE NEED TO FLUSH AND CLOSE THESE FILES SO , WE OPEN THEM IN OVERWRITE FORMAT 
      fflush (ptr2);	//
			//
      fclose (ptr1);	//
      fclose (ptr2);	//

//free(ptr1);
//free(ptr2);

      FILE *ptr3 = fopen ("temp1.txt", "w");// OPENED IN W FORMAT BECAUSE WE NEED TO OVERWRITE THEM FROM TEMP(file1) FILE 
					   // FOR USE IN NEXT ITERATION
      FILE *ptr4 = fopen ("temp2.txt", "w");//

      fseek (ptr, 0, SEEK_SET);// set file1 pointer to start because we need to copy it both the files 
      fpaster (ptr, ptr3, ptr4, n);// for pasting

      fflush (ptr3); //		FLUSH AND CLOSE FILES SO WE USE THEM IN NEXT ITERATION
      fflush (ptr4); // 
      fflush (ptr);  //
		     //
      fclose (ptr3); //
      fclose (ptr4); //
      fclose (ptr);  //

//free(ptr3);
//free(ptr4);
//free(ptr);

      v++; // counts the power of 2 in size

    }

  /*FILE *ptr = fopen ("file1.txt", "r+");
  fprintf (ptr, "did some thing  ");
  fclose (ptr);*/
				// 			FINISH

}

