#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
struct node
{
    int data;
    struct node *next;
};
void add_node(struct node *head, int data)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head->data == '\0')
    {
        head->data = new_node->data;
        return;
    }
    struct node *current_node = head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}
int count(struct node* head)
{
    int a=0;
    struct node* curr=head;
    while(curr!=NULL)
    {
        a++;
        curr=curr->next;
    }
    return a;
}
void rev(struct node *head,int arr[],int m)
{
    int i=0;
    struct node *curr=head;
    while(curr!=NULL)
    {
        arr[i]=curr->data;
        curr=curr->next;
        i++;
    }
    i=m-1;
    while(i>=0)
    {
        printf("%d, ",arr[i]);
        i--;
    }
    printf("\b\b.\n");
}
int main()
{
    int a, x, i = 0,m;
    struct node *head = malloc(sizeof(struct node));
    head->data = '\0';
    head->next = NULL;
    printf("Enter the number of nodes:\n");
    scanf("%d", &x);
    printf("Enter the data:\n");
    while (i < x)
    {
        // a=rand()%10;
        add_node(head, i);
        i++;
    }
    m=count(head);
    int arr[m];
    rev(head,arr,m);
    i = 0;
    while (head != NULL)
    {
        printf("%d, ", head->data);
        head = head->next;
    }
    printf("\b\b.\n");
    return 0;
}
