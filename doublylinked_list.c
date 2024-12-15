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
    void add_node()
    {
        int x;
        cout<<"enter the data:\t";
        cin>>x;
        node*newnode=new node;
        newnode->data=x;
        newnode->next=NULL;
        if(head=NULL)
        {
            newnode->prev=NULL;
            head=tail=newnode;
        }
        else
        {
            newnode->prev=tail;
            tail=newnode;
        }
    }
    void display()
    {
        node*temp=head;
        if(head==NULL)
            cout<<"\nnode is EMPTY:\n;
        else{
            while(temp->next!=NULL)
        {
            cout<<temp->data<<"\t";
            temp=temp->next;
        }
        cout<<temp->data<<"\n";
        }
    }
};
int main()
{
    doubly_linked_list a;
    int choice;
    cout<<"******MENUE******\n 1.INSERT\n 2.DISPLAY\n 3.EXIT\n";
    cin>>choice;
    switch(choice)
    {
        case 1: a.add_node();break;
        case 2: a.display();break;
        case 3: exit(0);
        default: cout<<"invalid choice\n";
    }
    return 0;
}
