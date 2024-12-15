#include<stdio.h>
#include<stdlib.h>
                               //passed//
struct node
{
    int data;
    struct node* next,*prev;
};
struct node*head,*tail;
struct node* get_new_node(int x)
{
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
};
void insert_at_head()
{
    int x;
    printf("enter the data:\n");
    scanf("%d",&x);
    struct node*temp= get_new_node(x);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    //tail->next=temp;            //to insert at tail//
    //temp->prev=tail;
    //tail=temp;

    head->prev=temp;
    temp->next=head;
    head=temp;

}

void insert_at()
{
            struct node* temp=(struct node*)malloc(sizeof(struct node));
                    struct node* temp1=(struct node*)malloc(sizeof(struct node));
                            struct node* temp2=(struct node*)malloc(sizeof(struct node));
                                temp1=head;
    int value,position,i;
    printf("enter the position:");
    scanf("%d",&position);

    if(position==1)
    {
        insert_at_head();
    }
    else
    {
        printf("\nenter data:");
    scanf("%d",&value);
    temp->data=value;

        for(i=0;i<position-2;i++)
        {
            temp1=temp1->next;
        }
        temp2=temp1->next;
        temp1->next=temp;
        temp->prev=temp1;
        temp->next=temp2;
        temp2->prev=temp;
    }
}
void print()
{
    struct node*temp =head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void reverse()
{
    struct node*temp=head;
    if(temp==NULL){ printf("ERROR: node is empty:\n");}
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int main()
{
    head=NULL,tail=NULL;
    int choice;
    //char ch='y';
    do{
        printf("PRESS 1::INSERT AT HEAD2:: DELET 3::REVERSE 4::DIDPLAY 5::EXIT 6:: insert at\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert_at_head(); break;
            //case 2: delet(); break;
            case 3: reverse(); break;
            case 4:print(); break;
            case 5:exit(0);
            case 6:insert_at();break;
            default : printf("invalid choice\n"); break;
        }
        getchar();
        //printf("do you want to continue? (y/n)");
        //scanf("%c",&ch);
    }while(1);
    return 0;
}
