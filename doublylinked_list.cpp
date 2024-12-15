#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node*prev,*next;
};
class doubly_linked_list
{
private:
    node*head,*tail;
public:
    doubly_linked_list()
    {
        head=NULL;tail=NULL;
    }

    node* get_new_node(int x)
{
    node* newnode=new node;
    newnode->data=x;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
};
void insert_at_head()
{
    int x;
       cout<<"enter the data: ";
        cin>>x;
    node*temp= get_new_node(x);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }

    head->prev=temp;
    temp->next=head;
    head=temp;

}
void insert_at_tail()
{
        int x;
   cout<<"enter the data: ";
   cin>>x;
    node*temp= get_new_node(x);
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    temp->prev=tail;
    tail=temp;

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
        temp->prev=NULL;
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
            node* temp2=temp1->next;
            temp->next=temp2;
            temp1->next=temp;
            temp2->prev=temp;
            temp->prev=temp1;
            /*temp->next=temp2;
            temp2->prev=temp;      // this can also be used
            temp1->next=temp;
            temp->prev=temp1;*/
        }
    }
    void display()
    {
        node*temp=head;
        if(head==NULL&&tail==NULL)
            cout<<"\nnode is EMPTY:\n";
        else{
            while(temp!=NULL)
        {
        cout<<temp->data<<"\t";
        temp=temp->next;
        }
    cout<<"\n";
        }
    }
    void reverse()
    {
        node*temp=tail;
        if(tail==NULL)
        {
            cout<<"node is empty:\n";
        }
        else
            while(temp->prev!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->prev;
        }
        cout<<temp->data<<"\n";



    }
    void delet_node()
{
    int i,n;
    cout<<"enter the position to be deleted:\n";
    cin>>n;
    node* temp1=head;
    if(head==NULL&&tail==NULL)
    {
        cout<<"ERROR:node is empty\n";
    }

    else
    {
            if(n==1)
        {
        head=temp1->next;
        head->prev=NULL;// heads now points to second node
        free(temp1);
        }
    else
    {
         for(i=0;i<n-2;i++)
        {
        temp1=temp1->next;//temp1 points to (n-1)th node
        }
    node* temp2=temp1->next;
    node*temp3=temp2->next;
    /*if(temp3==tail)
    {
        temp2->next=NULL;
        tail=temp2;
        free(temp3);
        return;
    }*/
    temp1->next=temp3;
    temp3->prev=temp1;
    free(temp2);
    }

    }



}
};
int main()
{
    doubly_linked_list a;
    int choice;
    while(1)
    {cout<<"******MENUE******\n 1::INSERT AT HEAD\t 2::INSERT AT TAIL\n 3::DISPLAY\t 4::REVERSE\t 5::DELETE 6::EXIT\t7::INSERT AT__NODE\n";
    cin>>choice;
    switch(choice)
    {
        case 1: a.insert_at_head();break;
        case 2: a.insert_at_tail();break;
        case 3: a.display(); break;
        case 4: a.reverse();break;
        case 5: a.delet_node();break;
        case 6: exit(0);
        case 7: a.insert_at();break;
        default: cout<<"invalid choice\n";
    }

}
return 0;
}
