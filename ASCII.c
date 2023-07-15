#include<stdio.h>
#include<conio.h>
int main()
{
    int a;
    printf("\n\n\n\t\t\t ASCII value:");
    while(a!=27)
    {
        a=getch();
        system("cls");
        printf("\n\n\n\t\t\t ASCII value:%d",a);
    }
    return 0;
}
