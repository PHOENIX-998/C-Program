#include<stdio.h>
int front=-1;
int rear=-1;
void enqueue(int queue[],int x,int data)
{
    if (rear==x-1)
    {
        printf("\nOverflow\n");
    }
    if(front==-1&&rear==-1)
    {
        front=rear=0;
        queue[rear]=data;
    }
    else
    {
        rear++;
        queue[rear]=data;
    }
}
void dequeue(int queue[],int x)
{
    int b=0;
    if (front == -1 && rear == -1 || front >rear)
    {
        printf("\nThe queue is empty!\n");
    }
    if(front<x&&front<=rear)
    {
        printf("The deleted Element is: %d\n",queue[front]);
       queue[front]=b;
        front++;
    }
}
void peek(int queue[],int x)
{
    int a=0;
    if (front == -1 && rear == -1)
    {
        printf("\nThe queue is empty!\n");
    }
    if (front == x - 1)
    {
        printf("\nThe front value is: %d\n", a);
    }
    else
    {
        a=queue[front];
        printf("\nThe front value is: %d\n",a);
    }
}
void display(int queue[],int x)
{
    int i;
    printf("\nPrinting the queue:\n");
    for ( i = 0; i <= rear; i++)
    {
        if (queue[i]=='\0')
        {
            continue;
        }
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main()
{
    int queue[100];
    int x,ch,a;
    int y=1;
    printf("\nEnter the queue size:\n");
    scanf("%d",&x);
    while(y)
    {
        printf("Enter your choise:\n");
        printf("1. Enqueue.\n2. Dequeue.\n3. Peek.\n4. Display.\n");
        printf("Your choies is:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
        if (front==x-1&&rear==x-1)
        {
            printf("\nQueue ended!\n");
            y=0;
            break;
        }
        if(rear==x-1)
        {
            printf("\nOverflow!!\n");
            break;
        }
            printf("Enter your data:\n");
            scanf("%d", &a);
            enqueue(queue,x,a);
            break;
        case 2:
            dequeue(queue,x);
            break;
        case 3:
            peek(queue,x);
            break;
        case 4:
            display(queue,x);
            break;
        default:
            y=0;
        }
    }
}