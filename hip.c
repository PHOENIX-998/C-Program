#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int i,int x)
{

    int largest=i;
    int left=2 * i+1;
    int right=2 * i+2;
    if(left<x && arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<x && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,largest,x);
    }
}
void heap_sort(int arr[],int x)
{
    int i;
    for(i=x/2-1;i>=0;i--)
    {
        heapify(arr,i,x);
    }
    for(i=x-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,0,i);
    }
}
void print(int arr[],int x)
{
    int i;
    for(i=0;i<x;++i)
    {
        printf("%d ",arr[i]);
    }
}
int main()
{
    int x,i;
    int arr[20];
    printf("Enter the size of the array:\n");
    scanf("%d",&x);
    printf("Enter the elements of the array:\n");
    for(i=0;i<x;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Print unsorted array:\n");
    print(arr,x);
    heap_sort(arr,x);
    printf("\nPrint sorted array:\n");
    print(arr,x);
    return 0;
}
