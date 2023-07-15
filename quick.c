#include <stdio.h>

void swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high)
{
  int pivot, i, j ;
	i = (low - 1);
	pivot = array[high];
  for (j = low; j < high; j++)
  {
    if (array[j] <= pivot)
    {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void printArray(int array[], int size)
{
  int i ;
  for (i = 0; i < size; ++i)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main()
{
   int x;
    int arr[20],i;
    printf("Enter the size of the array:\n");
    scanf("%d",&x);
    printf("Enter the element of the array:\n");
    for(i=0;i<x;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted array in ascending order: \n");
    printArray(arr, x);
    printf("Applying Quick sort:\n");
    quickSort(arr, 0, x- 1);
  printf("Sorted array in ascending order: \n");
  printArray(arr, x);
  return 0;
}
