#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* link;
};
void add_node(struct node** head_ref,int data)
{
    struct node* new_node=malloc(sizeof(struct node));
    new_node->data=data;
    new_node->link=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    struct node* current_node= *head_ref;
    while(current_node->link!=NULL)
    {
        current_node=current_node->link;
    }
    current_node->link=new_node;
}
void print(struct node* head)
{
    struct node* current_node=head;
    printf("\n");
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
            if(i->data>j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}
struct node* merging(struct node* m,struct node* n)
{
    struct node *now=malloc(sizeof(struct node));
    now->data=-1;
    now->link=NULL;
    struct node *non =now;
    struct node* p=m;
    struct node* q=n;
    while(p!=NULL&&q!=NULL )
    {
        if(p->data<q->data)
        {
            if(now->data==-1)
            {
                now->data=p->data;
                struct node* re=p;
                p=p->link;
                free(re);
                continue;
            }
            else
            {
                while(non->link!=NULL)
                {
                    non=non->link;
                }
                non->link=p;
                non=p;
                p = p->link;
                non->link = NULL;
            }
        }
        else
        {
            if (now->data ==-1)
            {
                now->data = q->data;
                struct node *g = q;
                q = q->link;
                free(g);
                continue;
            }
            else
            {
                while (non->link != NULL)
                {
                    non = non->link;
                }
                non->link = q;
                non = q;
                q = q->link;
                non->link = NULL;
            }
        }
    }
    if(p!=NULL)
    {
        while(p!=NULL)
        {
            while (non->link != NULL)
            {
                non = non->link;
            }
            non->link = p;
            non = p;
            p = p->link;
            non->link = NULL;
        }
    }
    if (q != NULL)
    {
        while (q != NULL)
        {
            while (non->link != NULL)
            {
                non = non->link;
            }
            non->link = q;
            non = q;
            q = q->link;
            non->link = NULL;
        }
    }
    return now;
}
int main()
{
    struct node* head=NULL;
    struct node* head1=NULL;
    struct node* head2=NULL;
    int x,i=0,a;
    printf("Enter the number of nodes:\n");
    scanf("%d",&x);
    printf("Enter the data for first linked list:\n");
    while(i<x)
    {
        scanf("%d",&a);
        add_node(&head1,a);
        i++;
    }
    i=0;
    printf("Enter the data for second linked list:\n");
    while(i<x)
    {
        scanf("%d",&a);
        add_node(&head2,a);
        i++;
    }
    shorting(head1);
    shorting(head2);
    print(head1);
    print(head2);
    head=merging(head1,head2);
    print(head);
    return 0;
}
