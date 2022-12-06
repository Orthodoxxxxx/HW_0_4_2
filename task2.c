#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* Initialization(int *size){
  int *arr;
  printf("Enter the size of array:");
  scanf("%d", size);
  srand(time(NULL));
  arr = (int*) malloc (*size * sizeof(int));
  int i;
  for (i = 0; i < *size; i++){
    arr[i] = (rand() % 18) - 9;  
  }
  return arr;
}

void printArray(int *arr, int size){
  int i;
  printf("Array: ");
  for (i = 0; i < size; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

double avgValue(int *arr, int size){
  double sum = 0;
  int i;
  for (i = 0; i < size; i++){
    sum += arr[i];
  }
  sum = sum / size;
  int count = 0;
  for(i = 0; i < size; i++){
    if ((double)arr[i] > sum) count++;
  }
  printf("Count of elements which > than average = %d\n", count);
  return sum;
}

int sumNegative(int *arr, int size){
  int sum = 0;
  int i, mark = 0;
  for (i = 0; i < size; i++){
    if(mark == 1)sum += abs(arr[i]);
    if (arr[i] < 0) mark = 1;
    
    
  }
  return sum ;
}

int main(){
  int size;
  int *arr = Initialization(&size);
  printArray(arr, size);
  printf("Avg value = %.3f\n", avgValue(arr, size));
  printf("Sum after first negative = %d\n", sumNegative(arr, size));
  return 0;
}