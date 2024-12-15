#include<stdio.h>
#include<stdlib.h>

void short_marks(float*marks,int n)
{
    float temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(*(marks+j)<(*(marks+(j+1))))
            {
                  temp=*(marks+j);
                    *(marks+j)=*(marks+(j+1));
                    *(marks+(j+1))=temp;
            }

        }
    }
}

int main()
{
    float *marks;
    int i,n;
    printf("enter the number of subjects:\n");
    scanf("%d",&n);
    marks=(float*)calloc(n,sizeof(float));
    if(marks==NULL)
    {
        printf("memory is not allocated:\n");
        exit(1);
    }
    else
    {  printf("enter the marks:\n");
        for(i=0;i<n;i++)
        {
            scanf("%f", (marks+i));
        }

    }
    short_marks(marks,n);
    printf("the shorted list is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(marks+i));
    }
    free(marks);


}

/*int main()                     //for concept of dynamic memory allocation//
{
    float *adress;
    int i,j;
    printf("enter the number of address:\n");
    scanf("%d",&i);
    adress=(float*)malloc(i*sizeof(float));//adress=(float*)calloc(i,sizeof(float));
    if(adress==NULL)
    {
        printf("memory cannot be allocated:\n");
        exit(1);
    }
    else
    {
         for(j=0;j<i;j++)
    {
        printf("the adress of %d block is %d\n",j,(adress+j));
    }
    }
    free(adress);

}
*/
