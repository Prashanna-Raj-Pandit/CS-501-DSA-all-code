#include<stdio.h>
int partition(int array[],int start,int end)
{
    int pivot,i,temp;
    pivot=array[end];
    int pindex=start;
    for(i=start;i<end;i++)
    {
        if(array[i]<=pivot)
        {
            temp=array[i];
            array[i]=array[pindex];
            array[pindex]=temp;
            pindex++;
        }
    }
    temp=array[pindex];
    array[pindex]=array[end];
    array[end]=temp;
    return pindex;
}
int quick_short(int array[],int start,int end)
{
    if(start<end)
    {
    int pindex=partition(array,start,end);
    quick_short(array,start,pindex-1);
    quick_short(array,pindex+1,end);
}
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
    int len=8;
    int array[]={4,6,9,2,1,10,5,12};
    printf("before short:\t");
    print(array,len);
    quick_short(array,0,7);
    printf("\nafter short:\t");
    print(array,len);
}
