#include<stdio.h>
#include<stdlib.h>

void print(int arr[],int x)
{
    int i;
    for ( i = 0; i < x; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void sort(int arr[],int x)
{
    int i;
    int j;
    for(i=0;i<x;i++)
    {
        for ( j =i+1; j<=x; j++)
        {
            if (arr[i]>arr[j])
            {
            int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
int binary( int arr[],int low,int high,int a)
{
    int l,h,mid;
    mid=(low+high)/2;
    if(a==arr[mid])
    {
        return mid;
    }
    if(a<arr[mid])
    {
        binary(arr,low,mid-1,a);
    }
    if(a>arr[mid])
    {
        binary(arr,mid+1,high,a);
    }
}
int main()
{
    int arr[20];
    int x,i,c,k;
    printf("Enter the size of the array:\n");
    scanf("%d",&x);
    printf("Enter the elements:\n");
    for ( i = 0; i < x; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("The array is:\n");
    sort(arr,x);
    print(arr,x);
    printf("Enter the element for search:\n");
    scanf("%d",&c);
    k=binary(arr,0,x-1,c);
    printf("Element found!!\n");
    printf("The position of the element %d is:%d\n",arr[k],k);
}