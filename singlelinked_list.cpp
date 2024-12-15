#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
int data;
node* next;

};

class linked_list
{
private:
    node* head,*tail;
public:
    linked_list()
    {
        head=NULL;
        tail=NULL;
    }
    void insert_at_head()
    {
        cout<<"enter the data:";
        int x;
        cin>>x;
        node*temp=new node;
        temp->data=x;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            temp->next=head;
            head=temp;
        }

    }
    void insert_at_tail()
    {
        int n;
        cout<<"enter the data of node:\n";
        cin>>n;
        node* temp= new node;
        temp->data=n;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }

    }
    void insert_at()
    {
        int data,i,n;
        cout<<"enter the position:";
        cin>>n;
        cout<<"enter data:";
        cin>>data;
        node *temp= new node;
        temp->data=data;
        temp->next=NULL;
        if(n==1)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
            node* temp1=head;
            for(i=0;i<n-2;i++)
            {
                temp1=temp1->next;
            }
            temp->next=temp1->next;
            temp1->next=temp;
        }
    }
    void print()
{
    node*temp=head;
    while(temp!=NULL)
    {
       cout<<temp->data<<"\t";
        temp=temp->next;
    }
    printf("\n");
}
void delet_node()
{
    int n;
    cout<<"enter the position to be deleted:\n";
    cin>>n;
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
/*reverse_node()
{
    node*head;
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
// return head;
}*/
};

int main()
{
    linked_list a;
    int choice;
    char ch='y';
    while(1){
        cout<<"PRESS 1::INSERT AT HEAD\t 2::INSERT AT TAIL\t3::INSERT AT__NODE\n4::DELET\t5::PRINT\t6::EXIT\n ";
        cin>>choice;
        switch(choice)
        {
            case 1: a.insert_at_head(); break;
            case 2: a.insert_at_tail(); break;
            //case 3: a.reverse_node(); break;
            case 3: a.insert_at(); break;
            case 4: a.delet_node(); break;
            case 5: a.print();break;
            case 6: exit(0);
            default : cout<<"invalid choice\n"; break;
        }
    }
    //a.add_node(1);
    //a.add_node(2);
    //a.print();
    return 0;
}
