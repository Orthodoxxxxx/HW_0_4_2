#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

void outputArray(int a[], int size) 
{
	printf("Array:");
	for (int i=0;i<size;i++)
	{		
		printf(" %d ",a[i]);
		}
	printf("\n");

}

int returnMin(int a[], int size) 
{

 	int min = a[0];
 	outputArray(a, size);
	for (int i=1; i<size; i++)
	{	
		if (min > a[i])
		min = a[i];
	}
	printf("min: %d\n",min);
	return min;
}
 

int main()
{	
	srand(time(NULL));
	int *MassArray;
	int *temp;
	int n, min;
	printf("Task 0 - mass array problem\nEnter the size of the array (n):");
	scanf("%d",&n);
	MassArray = (int*)malloc(n * sizeof(int));
	temp = (int*)malloc(n * sizeof(int));
	
	for (int i=0; i<=n-1; i++)
		{
			MassArray[i] = rand() %500; 		
		}
	
	int index=0; 						
	
	while (n>0)
	{
		min = returnMin(MassArray, n); 			
		for (int i=0; i<=n-1; i++)
			{
				if(MassArray[i] == min)
				{
					index = i;		
				}		
			}
			
		if (MassArray[index-1] != NULL)
		{
			MassArray[index-1] = MassArray[index] + MassArray[index-1];	
			MassArray[index] = 0;						
		}
		else
		{
			MassArray[index+1] = MassArray[index]+MassArray[index+1];	
			MassArray[index]=0;						
		}
			
		n--;
		temp = (int*)realloc(temp, n * sizeof(int));				
		
		int j=0;								
		for (int i=0; i<=n-1; i++)
			{
				if(MassArray[j] != 0)					
				{
					temp[i] = MassArray[j];
				}
				else
				{
					temp[i]=MassArray[j+1];
					j++;
				}
				j++;			
			}
			
		MassArray = (int*)realloc(temp, n * sizeof(int));			
		for (int i=0; i<=n-1; i++)
		{
			MassArray[i] = temp[i];						
		}
		printf("\n");
		
	}
	free(MassArray);
	free (temp);
	return 0;
}
