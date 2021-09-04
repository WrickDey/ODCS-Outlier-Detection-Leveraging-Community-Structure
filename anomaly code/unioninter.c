#include<stdio.h>
#include<malloc.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)     
 
       // Last i elements are already in place  
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}




 void uni(char c1[],char c2[])
{
	
	printf("\n\nUnion of the observations obtained\n\n"); 
	FILE* fp1=fopen(c1,"r");
	FILE* fp2=fopen(c2,"r");
	if(fp1==NULL || fp2==NULL)
	{
		printf("FILE NOT FOUND");
	}
	
	int i=0,j=0;

	while(!feof(fp1))
	{
		i++;	
	}
	
	while(!feof(fp2))
	{
		j++;	
	}
	
	int* arr1=(int*)malloc(sizeof(int)*i);
	int* arr2=(int*)malloc(sizeof(int)*j);
	
	while(!feof(fp1))
	{
		int a=0;
		int i=0;
		fscanf(fp1,"%d\n",&a);
		arr1[i]=a;
		i++;		
	}
	
	while(!feof(fp2))
	{
		int a=0;
		int i=0;
		fscanf(fp1,"%d\n",&a);
		arr2[i]=a;
		i++;		
	}
	
	
	bubblesort(arr1,i);
	bubblesort(arr2,j);
	
	int c = 0, d = 0;
    while (c < i && d < j) {
        if (arr1[c] < arr2[d])
            printf(" %d ", arr1[c++]);
        else if (arr2[d] < arr1[c])
            printf(" %d ", arr2[d++]);
        else {
            printf(" %d ", arr2[d++]);
            c++;
        }
    }
 
    /* Print remaining elements of the larger array */
    while (c < i)
    	printf(" %d ",arr2[c++]);
    while (d < j)
        printf(" %d ",arr2[d++]);

	
	fclose(fp1);
	fclose(fp2);
	free(arr1);
	free(arr2);
	
	return;
}
	




	void printIntersection(char c1[],char c2[])
	{
	   
	   
	  printf("\n\nIntersection of the observations obtained\n\n");  
	FILE* fp1=fopen(c1,"r");
	FILE* fp2=fopen(c2,"r");
	if(fp1==NULL || fp2==NULL)
	{
		printf("FILE NOT FOUND");
	}
	
	int i=0,j=0;

	while(!feof(fp1))
	{
		i++;	
	}
	
	while(!feof(fp2))
	{
		j++;	
	}
	
	int* arr1=(int*)malloc(sizeof(int)*i);
	int* arr2=(int*)malloc(sizeof(int)*j);
	
	while(!feof(fp1))
	{
		int a=0;
		int i=0;
		fscanf(fp1,"%d\n",&a);
		arr1[i]=a;
		i++;		
	}
	
	while(!feof(fp2))
	{
		int a=0;
		int i=0;
		fscanf(fp1,"%d\n",&a);
		arr2[i]=a;
		i++;		
	}
	
	
	bubblesort(arr1,i);
	bubblesort(arr2,j);
		
		
		
		
		int c = 0, d = 0;
	    while (c < i && d < j) {
	        if (arr1[c] < arr2[d])
	            c++;
	        else if (arr2[d] < arr1[c])
	            d++;
	        else /* if arr1[c] == arr2[d] */
	        {
	            printf(" %d ", arr2[d++]);
	            c++;
	        }
	    }
	
	fclose(fp1);
	fclose(fp2);
	free(arr1);
	free(arr2);
	
	return;
	
	
	
	}



int main(int argc,char* argv[])
{
	uni(argv[1],argv[2]);
	printIntersection(argv[1],argv[2]);
	
	return 0;
}
