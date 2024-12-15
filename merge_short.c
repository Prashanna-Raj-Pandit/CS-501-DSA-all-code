#include<stdio.h>

int merge(int left[],int nl,int right[],int nr,int array[])
{
    int i,j,k;
    i=j=k=0;
    while(i<nl&&j<nr)
    {
        if(left[i]<right[j])
        {
            array[k]=left[i];
            i++;
        }
        else
        {
            array[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<nl)
    {
        array[k]=left[i];
        i++;
        k++;
    }
    while(j<nr)
    {
        array[k]=right[j];
        j++;
        k++;
    }
}
int mergeshort(int array[],int len)
{

    if(len<2)
       { return 0;}
    int mid=len/2;
    int left[mid]; int right[len-mid];
    for(int i=0;i<mid;i++)
    {
        left[i]=array[i];
    }
    for(int i=mid;i<len;i++)
    {
        right[i-mid]=array[i];
    }
    printf("\ncalling left merge");
    mergeshort(left,mid);
    printf("\ncalling right merge");
    mergeshort(right,len-mid);
    printf("\ncalling merge");
    merge(left,mid,right,len-mid,array);
}

void print(int array[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }
}
int main()
{
   // int len=8,array[]={2,4,1,6,8,5,3,7};
   int len=10;
    int array[10];
    printf("enter the no of elements:");
    scanf("%d",&len);
    for(int i=0;i<len;i++)
    {
        printf("\nenter element:");
        scanf("%d",&array[i]);
    }
    printf("Before shorting:\n");
    print(array,len);
    mergeshort(array,len);
    printf("\nafter short:\n");
    print(array,len);
    return 0;
}
