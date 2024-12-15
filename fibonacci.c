#include<stdio.h>
int fibo(int n)
{                   //passed
    if(n==0)
        return 0;  // if the no of series is 1, then n-1 is passed to the function and hence it returns 0.
    else if(n==1)
    {
        return 1;
    }
    else
        return (fibo(n-1)+fibo(n-2));
}
int main()
{
    int n,f;
    printf("enter 'n', where n is no of terms in series:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        f=fibo(i);
        printf("\t%d",f);
    }
    return 0;
}
