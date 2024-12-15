#include<stdio.h>
#define size 5
int stack[size], top;
void push();
void pop();
void peek();
void display();
int main()
{
    top=-1;
    int choice;
    char ch='y';
    do{
        printf("PRESS 1::PUSH 2:: POP 3:: PEEK 4::DIDPLAY\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4:display(); break;
            default : printf("invalid choice\n"); break;
        }
        getchar();
        printf("do you want to continue? (y/n)");
        scanf("%c",&ch);
    }while(ch=='y');
}
void push()
{
    int item;
    if(top==size-1)
    {
        printf("stack OVERFLOW\n");
    }
    else
    {
        printf("enter the elements to be inserted\n");
        scanf("%d",&item);
        stack[++top]=item;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("stack UNDERFLOW\n");
    }
    else
    {
        printf("element deleted from stack is: %d\n",stack[top]);
        top--;
    }
}
void peek()
{
    if(top==-1)
    {
        printf("stack is empty:\n");

    }
    else
    {
        printf("the top of stack is %d\n",stack[top]);
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("the stack is empty\n");

    }
    else
    {
        printf("the elements in stack is:");
        for(i=0;i<=top;i++)
        {
            printf("%d\t",stack[i]);
        }
        printf("\n");
    }
}
