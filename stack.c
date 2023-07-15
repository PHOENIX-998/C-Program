
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
    struct node* prive;
};
int push(struct node* stack,int data,int i,int x,int top)
{
    if(i<x)
    {
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    new_node->prive=NULL;
    if (stack->data=='\0')
    {
        stack->data=new_node->data;
        return 0;
    }
    while (stack->next!=NULL)
    {
        stack=stack->next;
    }
    stack->next=new_node;
    new_node->prive=stack;
    top = top + 1;
    }
    return top;
}
int pop(struct node* stack,int top)
{
    struct node *curr=stack;
    while (curr->next!=NULL)
    {
        curr=curr->next;
    }
    struct node* prev=curr->prive;
    prev->next=NULL;
    printf("%d\n",curr->data);
    free(curr);
    top=top-1;
    return top;
}
int display(struct node* current)
{
    while (current->next != NULL)
    {
        current = current->next;
    }
    if (current->prive==NULL)
    {
        printf("The stack is empty!\n");
        return 0;
    }
    printf("Stack elementes:\n");
    while (current!=NULL)
    {
        printf("%d ",current->data);
        current=current->prive;
    }
    printf("\n");
    return 0;
}
int main()
{
    int i=0,x,a,ch;
    int y=1,top=0;
    struct node* stack=malloc(sizeof(struct node));
    stack->data='\0';
    stack->next=NULL;
    stack->prive=NULL;
    struct node *current = stack;
    printf("Enter the size of the stack:\n");
    scanf("%d",&x);
    while(y)
    {
        printf("Enter your choise:\n");
        printf("1. Push.\n2. Pop.\n3. Display.\n4. Exit.\n");
        printf("Your choise:");
        scanf("%d",&ch);
        printf("\n");
        switch (ch)
        {
        case 1:
        if(top==x)
        {
            printf("Stack overflow!!\n\n");
            continue;
        }
            printf("Enter the element:\n");
            while (i<x)
            {
                scanf("%d",&a);
                top=push(stack,a,i,x,top);
                i++;
            }
            break;
        case 2:
        if (top==0)
        {
            printf("Stack underflow!!\n\n");
            continue;
        }
            top=pop(stack,top);
            break;
        case 3:
            display(current);
            break;
        case 4:
            y=0;
            break;
        }
        printf("\n");
    }
    return 0;
}