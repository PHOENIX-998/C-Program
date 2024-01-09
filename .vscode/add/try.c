#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i,cou=21,arr[21],q=6,k=1,l=1,m=0;
    int clk=cou,j,v=0,h=0;
    for ( i = 0; i < cou; i++)
    {
        arr[i]=i;
    }
    i=0;
    while(k!=q)
    {
        h=k;
        if (i>q+m)
        {
            i=i-l;
        }
        if (i>q+m&&i<=clk)
        {
            l++;
        }
        if(k!=q&&i>=clk)
        {
            i=k;
            k++;
            l=1;
            m++;
            clk=clk-m;
        }
        if(k!=h)
        {
            v=0;
        }
        for ( j = 0; j < v; j++)
        {
            printf("\t");
        }
        printf("%d \n",arr[i]);
        v++;
        i+=q;
    }
    return 0;
}