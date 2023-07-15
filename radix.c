#include <stdio.h>
#include <stdlib.h>
void print(int arr[],int n);
void counting(int a[],int n,int place)
{
    int i,k=10;
    int count[10]={0};
    int b[n];
    for ( i = 0; i < n; i++)
    {
        count[(a[i]/place)%10]++;
    }
    for ( i =1; i <=k; i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for ( i = n-1; i >= 0; --i)
    {
        b[--count[(a[i]/place)%10]]=a[i];
    }
    for ( i = 0; i < n; i++)
    {
        a[i]=b[i];
    }
}
int maxel(int arr[],int n)
{
    int i,max=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
    }
    return max;
}
void radix_sort(int arr[],int n)
{
    int max=maxel(arr,n);
    for(int i=1;max/i>0;i *=10)
    {
        counting(arr,n,i);
    }
}
void print(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[]={580,203,70,90,33,5,21,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("Print the unsorted array:\n");
    print(arr,n);
    radix_sort(arr,n);
    printf("Print the unsorted array:\n");
    print(arr,n);
    return 0;
}
