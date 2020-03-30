/*
			===  OS Project  ===

		Name: Harjas Preet Singh
		Roll no: 31
		Regt no: 11801373
		Section: K18HK

Q 22: WAP that implements FIFO page replacement algo. First, generate a random
	page-reference string where page numbers range from 0 to 9. Apply the 
	random page-reference string to each algo, and record the number of page
	faults incurred by each algo. Implement the replacement algo so that the
	number of page frames can vary from 1 to 7. Assume that demand paging is
	used.
*/
//======================================================================================================================

//importing necessary libraries.
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

struct Object
{
	int pno;
}frames[7];											// an array of objects of the structure.

int faults=0;										// count for number of page faults initialized to 0.
int i,p;											// iterating variables.
int n;												// number of frames entered by user.
int pno;											// variable denoting current page number.
int flag=0;											// flag variable.

// Function determining whether it is a page fault or not.
// it takes in the current page number to be acessed as an arguement.
int page_found(int pno)
{
	for(i=0;i<n;i++)
	{
		if(frames[i].pno == pno)
			return i;								//if the page number is found in frame, the page number is returned
	}
	return 'a';										//if page number not found in frame, alphabet 'a' is returned
}
//=========================================== MAIN PROGRAM ============================================================
int main()
{
	int len;										// number of pages.
	srand ( time(NULL));							// used to generate random numbers using internal clock of system.
	printf("Enter number of pages (b/w 0 to 9) :");
	scanf("%d",&len);
	if(len<0 || len>9)
	{
		printf("\nInput out of bounds.\n");
		exit(0);
	}

	int *arr = (int *)malloc(len*sizeof(int));			// dynamically allocated memory for 'len' number of pages.
	
	for (int i=0;i<len;i++)
	{
		arr[i] = ( rand()%9 )+1 ;
	}
	printf("\nEnter no of frames (b/w 1 to 7) :");
	scanf("%d",&n);
	if(n<1 || n>7)
	{
		printf("\nInput out of bounds.\n");
		exit(0);
	}

	printf("Length:%d",len);

	for (i=0;i<n;i++)
	{
		frames[i].pno = -1;								// all the frame values are initialized as -1.
	}

	printf("\n Page no     page frames     page faults     fault count");
	printf("\n-----------------------------------------------------------");
	for(p=0;p<len;p++)
	{
		pno = arr[p];
		flag=0;											// When page is not found and there is a page fault
		if(page_found(pno) == 'a')						// i.e. when 'if' condition is true, flag value changes from 
		{												// 0 to 1.
			frames[faults%n].pno = pno;
			faults++;
			flag=1;
		}
		printf("\n%5d\t",pno);
		printf("\t");
		for(i=0;i<n;i++)
			printf("%d ",frames[i]);

		if(flag==1)
			printf("\t\t YES");
		else
			printf("\t\t NO");

		printf("\t\t%d",faults);
	}
	printf("\n------------------------------------------------------------");
	printf("\nTotal page faults:%d", faults);
	printf("\n\n Exiting...\n\n");

	free(arr);											// free up the dynamically allocated memory
	return 0;
}