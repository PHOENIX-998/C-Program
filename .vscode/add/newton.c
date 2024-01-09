#include<stdio.h>
#include<stdlib.h>
int table(int *p,int *g,int q,int val)
{
    int i,k=1,l=1,m=0;
    int clk=val,j,v=0,h=0;
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
        if (i<q)
        {
            printf("%d|",g[i]);
        }
        for ( j = 0; j < v; j++)
        {
            printf("\t\t");
        }
        printf("%d \n",p[i]);
        v++;
        i+=q;
    }
    return 0;
}
int function(int *p,int q)
{
    int i,x;
    int *arr=p;
    for ( i = 0; i < q; i++)
    {
        scanf("%d",&arr[i]);
    }
    return *arr;
}
int newton(int *p, int q, int val)
{
    int i, j = q, m, l, k = 2, n = 1;
    m = q;
    for (i = 0; i < val; i++)
    {
        if (i + 1 == m)
        {
            i = m;
            m = (m + q) - n;
            n++;
        }
        p[j] = p[i + 1] - p[i];
        l = p[j];
        j++;
    }
    return *p;
}
int interpol(int *cal,int q,float u,float a,int *g)
{
    int i,j,f=1,k=0,wo;
    float c=1,b=0,h=0;
    for ( i = 0; i < q; i++)
    {
        if (g[i]>a)
        {
            i--;
            break;
        }
        
    }
    for ( ; i < q; i++)
    {
        f=1;
        if (i==0)
        {
            b=cal[i];
            continue;
        }
        for(j=1;j<=i;j++)
        {
            f=f*j;
        }
        c=((c*(u-k))/(f))*cal[i];
        b=b+c;
        k++;
    }
    printf("The answer is : \n");
    printf("%f",b);
}
float dif(int *g,float a,int q)
{
    int i=0;
    float u,h,m=0;
    h=(g[i+1]-g[i]);
    for ( i = 0; i < q; i++)
    {
        if (g[i]>a)
        {
            i--;
            break;
        }
        
    }
    m=(a-g[i]);
    u=m/h;
    return u;
}
int *result(int *p,int *g, int val, int q)
{
    int *cal,i, j = 0;
    int m = q, n = 1;
    float a;
    cal = (int *)malloc(q);
    printf("Enter the value of x to find y: \n");
    scanf("%f",&a);
    float u=dif(g,a,q);
    for (i = 0; i < val; i++)
    {
        if (i == 0)
        {
            cal[j] = p[i];
            j++;
        }
        if (i + 1 == m)
        {
            i = m;
            cal[j] = p[i];
            m = (m + q) - n;
            n++;
            j++;
        }
    }
    interpol(cal,q,u,a,g);
    return cal;
    free(cal);
}
int main()
{
    int *p, *a, *g , q = 0, val = 0;
    printf("Enter the size of the list: \n");
    scanf("%d", &q);
    val = (q * (q + 1)) / 2;
    p = (int *)malloc((2 * val) * sizeof(int));
    a = (int *)malloc(val * sizeof(int));
    g = (int *)malloc(q);
    *p = val;
    printf("Enter the data of x : \n");
    *g = function(g, q);
    printf("Enter the data of y : \n");
    *p = function(p, q);
    *p = newton(p, q, val);
    table(p,g,q,val);
    a = result(p,g, val, q);
    free(p);
    free(a);
    return 0;
}