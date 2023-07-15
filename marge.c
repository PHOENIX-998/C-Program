#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int low,int mid,int high)
{
    int i,j,k,arr2[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid&&j<=high)
    {
        if(arr[i]>arr[j])
        {
            arr2[k]=arr[j];
            k++;
            j++;
        }
        else
        {
            arr2[k]=arr[i];
            k++;
            i++;
        }
    }
    while(i<=mid)
    {
        arr2[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        arr2[k]=arr[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
    {
        arr[i]=arr2[i];
    }
}
void merge_sort(int arr[],int low,int high)
{
    if(low!=high)
    {
        int mid;
    mid=(low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    }
}
void printArray(int array[], int size)
{
  int i ;
  for (i = 0; i < size; i++)
  {
    printf("%d  ", array[i]);
  }
  printf("\n");
}
int main()
{
    int x;
    int arr[20];
    int i;
    printf("Enter the size of the array:\n");
    scanf("%d",&x);
    printf("Enter the element of the array:\n");
    for(i=0;i<x;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Unsorted array in ascending order: \n");
    printArray(arr,x);
    merge_sort(arr,0,x-1);
    printf("Sorted array in ascending order: \n");
    printArray(arr, x);
    return 0;
}
