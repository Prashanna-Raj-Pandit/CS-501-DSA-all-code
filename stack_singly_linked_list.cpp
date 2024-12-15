#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node* next;
};
class stack_using_linked_list
{
    private:
        node* top;
    public:
        stack_using_linked_list()
        {
            top=NULL;
        }
        void push()
        {
            int x;
            cout<<"enter the data:";
            cin>>x;
            node* newnode=new node;
            newnode->data=x;
            if(top==NULL)
                newnode->next=NULL;//The next field of the first element must be always NULL.
            else
                newnode->next=top;
            top=newnode;

            cout<<"Insertion completed\n";
        }
        void pop()
        {
            node*temp=top;
            if(top==NULL)
                cout<<"stack is empty:\n";
            else
                cout<<"element popped:\t"<<temp->data<<"\n";
            top=temp->next;
            free(temp);
        }
        void display()
        {
            node*temp=top;
            if(top==NULL)
            {
                cout<<"stack is empty:\n";
            }
            else
                while(temp->next!=NULL)
                {
                    cout<<temp->data<<"\t";
                    temp=temp->next;
                }
            cout<<temp->data<<"\n";
        }
};
int main()
{
    stack_using_linked_list a;
    int choice;
   //clrscr();
   cout<<"\n:: Stack using Linked List ::\n";
   while(1){
      cout<<"\n****** MENU ******\n";
      cout<<"1. Push\n2. Pop\n3. Display\n4. Exit\n";
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice){
	 case 1: a.push();break;
	 case 2: a.pop(); break;
	 case 3: a.display(); break;
	 case 4: exit(0);
	 default: cout<<"\nWrong selection!!! Please try again!!!\n";
      }
   }
}
