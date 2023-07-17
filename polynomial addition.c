#include <stdio.h>
#include <stdlib.h>
typedef struct Node 
{
    int coefficient;
    int exponent;
    struct Node* next;
} Node;
void insertTerm(Node** head, int coefficient, int exponent) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    if (*head == NULL)
	{
        *head = newNode;
    } 
	else 
	{
        Node* temp = *head;
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
void displayPolynomial(Node* head) 
{
    Node* temp = head;
    while (temp != NULL) 
	{
        printf("%dx^%d ", temp->coefficient, temp->exponent);
        if (temp->next != NULL) 
		{
            printf("+ ");
        }
        temp = temp->next;
    }
    printf("\n");
}
Node* addPolynomials(Node* poly1, Node* poly2) 
{
    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;
    while (temp1 != NULL && temp2 != NULL) 
	{
        if (temp1->exponent > temp2->exponent) 
		{
            insertTerm(&result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } 
		else if (temp1->exponent < temp2->exponent) 
		{
            insertTerm(&result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } 
		else 
		{
            int sum = temp1->coefficient + temp2->coefficient;
            if (sum != 0) 
			{
                insertTerm(&result, sum, temp1->exponent);
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL) 
	{
        insertTerm(&result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }
    while (temp2 != NULL) 
	{
        insertTerm(&result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }
    return result;
}
void clearPolynomial(Node** head) 
{
    Node* temp;
    while (*head != NULL) 
	{
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int main() 
{
	int i;
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    int n1, n2;
    int coefficient, exponent;
    printf("Enter the number of terms in Polynomial 1: ");
    scanf("%d", &n1);
    printf("Enter the terms for Polynomial 1 (coefficient exponent):\n");
    for ( i = 0; i < n1; i++) 
	{
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly1, coefficient, exponent);
    }
    printf("Enter the number of terms in Polynomial 2: ");
    scanf("%d", &n2);
    printf("Enter the terms for Polynomial 2 (coefficient exponent):\n");
    for ( i = 0; i < n2; i++) 
	{
        scanf("%d %d", &coefficient, &exponent);
        insertTerm(&poly2, coefficient, exponent);
    }
    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);
    Node* result = addPolynomials(poly1, poly2);
    printf("Result: ");
    displayPolynomial(result);
    clearPolynomial(&poly1);
    clearPolynomial(&poly2);
    clearPolynomial(&result);
    return 0;
}
