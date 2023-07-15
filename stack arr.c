#include <stdio.h>
#include <stdlib.h>

int Push(int stack[],int x,int top)
{
    printf("Enter the stack element:\n");
    while(1)
    {
        if(top<x)
        {
            while(top<x)
            {
                scanf("%d",&stack[top]);
                top++;
            }
            return top;
        }
        else
        {
            printf("stack overflow!!\n");
            return 0;
        }
    }
    return top;
}
int Pop(int stack[],int x,int top)
{
    int temp;
    if(top==-1)
    {
        printf("stack underflow!!\n");
    }
    else
    {
        temp=stack[top-1];
        top=top-1;
        printf("\n%d\n",temp);
    }
    return top;
}
void Display(int stack[],int x,int top)
{
    if(top==-1)
    {
        printf("stack is empty!!\n");
    }
    else
    {
        for(top=x-1;top>=0;top--)
        printf("%d ",stack[top]);
    }
}
int main()
{
    int x,ch;
    int stack[20];
    int top=-1,y=1;
    printf("Enter the size of the stack:\n");
    scanf("%d",&x);
    while(y)
    {
        printf("Enter your choice:\n");
        printf("\n1. Push.\n2. Pop.\n3. Display.\n4. Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            {
                top=Push(stack,x,top+1);
                break;
            }
        case 2:
            {
                top=Pop(stack,x,top);
                break;
            }
        case 3:
            {
                Display(stack,x,top);
                break;
            }
        case 4:
            {
                y=0;
                break;
            }
        }
    }
    return 0;
}
