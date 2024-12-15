#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
struct node* head;
void insert (int data,int n)
{
   struct node* temp1=(struct node*)malloc(sizeof(struct node));
    temp1->data=data;  //This pointer holds the address of the next node and creates the link between two nodes
    temp1->next=NULL;
    if(n==1)
    {
        temp1->next=head;
        head=temp1;
        return;
    }
    struct node*temp2=head;
    for(int i=0;i<n-2;i++)
    {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
struct node* reverse(struct node*head)
{
 struct node* current,*prev,*next;
 current=head;
 prev=NULL;
 while(current!=NULL)
 {
     next=current->next;
     current->next=prev;
    prev=current;
    current=next;
 }
 head=prev;
 return head;
}

void print()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void delet(int n)
{
    struct node* temp1=head;
    if(n==1)
    {
        head=temp1->next;// heads now points to second node
        free(temp1);
        return;
    }
    int i;
    for(i=0;i<n-2;i++)
    {
        temp1=temp1->next;//temp1 points to (n-1)th node
    }
    struct node* temp2=temp1->next;// nth node
    temp1->next=temp2->next;//(n+1)th node
    free(temp2);
}
int main()
{
    head=NULL;
    int n;
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    print();
    printf("enter a position:\n");
    //scanf("%d",&n);
    //delet(n);
    print();
    head=reverse(head);
    print();
    return 0;

}

