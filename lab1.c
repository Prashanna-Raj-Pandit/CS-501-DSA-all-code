//wap to reverse a given string using stack
#include<stdio.h>
#include<string.h>
char stack[50];
int top=-1;

int main()
{
    char str[30];
    int i,len;
    printf("enter a string:\n");
    getchar();
    scanf("%s",str);
   // scanf("%[^\n]s",str);
    len=strlen(str);
    printf("%d\n",len);
    for(i=0;i<len;i++)
    {
        push(str[i]);
    }
    printf("the reversed string is:\n");
    for(i=0;i<len;i++)
    {
        pop();
    }
    return 0;
}
void push(char a)
{
    char c;
    top=top++;
    stack[top]=c;
    //printf("%s\n",stack);
}
void pop()
{
    char c;
    c=stack[top];
    top=top-1;
    printf("%c",c);
}
