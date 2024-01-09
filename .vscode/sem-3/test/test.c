#include<stdio.h>

int main()
{
    int num=9474,i,n=0,t,k=1,j,arm=0;
    int a = num;
    // printf("Enter the number:");
    // scanf("%d",&a);

    while(a>0)
    {
        t=a%10;
        a = a/10;
        j=0;
        k=1;
        while (j<n)
        {
            j++;
            k=k*t;
        }
        arm=arm+k;
    }
    printf("arm=%d\n",arm);
    if (arm==num)
    {
        printf("%d is a armstrong number:",num);
    }
    else
    {
        printf("%d is not a armstrong number:",num);
    }
    return 0;
}