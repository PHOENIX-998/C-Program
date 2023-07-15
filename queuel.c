#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
};
int enqueue(struct node *queue, int data, int i, int x, int top)
{
    if (i < x)
    {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        if (queue->data == '\0')
        {
            queue->data = new_node->data;
            return 0;
        }
        while (queue->next != NULL)
        {
            queue = queue->next;
        }
        queue->next = new_node;
        top = top + 1;
    }
    return top;
}
struct node* pop(struct node *queue, int* top)
{
    struct node *curr = queue;
    if(curr==NULL)
    {
        free(curr);
        return NULL;
    }
    queue = queue->next;
    curr->next = NULL;
    printf("%d\n", curr->data);
    free(curr);
    (*top)--;
    return queue;
}
int display(struct node *current)
{
    if (current == NULL)
    {
        printf("The queue is empty!\n");
        return 0;
    }
    printf("Queue elementes:\n");
    while (current!= NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return 0;
}
void peek(struct node *queue)
{
    struct node *curr=queue;
    printf("\nThe first element of tne queue is:%d",curr->data);
    printf("\n");
}
int main()
{
    int x,i=0,a,y,ch;
    int top=0;
    struct node *queue=malloc(sizeof(struct node));
    queue->data='\0';
    queue->next=NULL;
    struct node *current = queue;
    printf("Enter the size of the queue:\n");
    scanf("%d", &x);
    while (y)
    {
        printf("Enter your choise:\n");
        printf("1. Push.\n2. Pop.\n3. Display.\n4. Peek.\n");
        printf("Your choise:");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            if (top >= x)
            {
                printf("Queue overflow!!\n\n");
                continue;
            }
            printf("Enter Data:\n");
            if(i < x)
            {
                scanf("%d", &a);
                top = enqueue(queue, a, i, x, top);
                i++;
            }
            break;
        case 2:
            if(queue==NULL)
            {
                printf("\nThe queue is deleted!!\n");
                y=0;
                break;
            }
            if (top < 0)
            {
                printf("Queue underflow!!\n\n");
                continue;
            }
            queue = pop(queue, &top);
            break;
        case 3:
            display(current);
            break;
        case 4:
            peek(queue);
            break;
        default :
            y=0;
            break;
        }
    }
    printf("\n");
    return 0;
}