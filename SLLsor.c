#include <stdio.h>
#include <stdlib.h>

 struct node
{
    int data;
    struct node *link;
};
void add_node(struct node** head_ref, int data)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=data;
    new_node->link=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    struct node* current_node=*head_ref;
    while(current_node->link!=NULL)
    {
        current_node=current_node->link;
    }
    current_node->link=new_node;
}
void print_list(struct node* head)
{
    struct node* current_node=head;
    while(current_node!=NULL)
    {
        printf("%d ",current_node->data);
        current_node=current_node->link;
    }
    printf("\n");
}
void shorting(struct node* head)
{
    struct node* i,*j;
    int temp;
    for(i=head;i!=NULL;i=i->link)
    {
        for(j=i->link;j!=NULL;j=j->link)
        {
            if(i->data<j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}
int main()
{
    int a,i=0,x;
    struct node* head=NULL;
    printf("Enter the number of nodes:\n");
    scanf("%d",&x);
    while(i<x)
    {
        printf("Enter the data:\n");
        scanf("%d",&a);
        add_node(&head,a);
        i++;
    }
    shorting(head);
    print_list(head);
    return 0;
}
