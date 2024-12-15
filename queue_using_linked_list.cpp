#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node*next;
};
class queue_link_list
{
private:
    node*front,*rear;
public:
    queue_link_list()
    {
        front=NULL;
        rear=NULL;
    }
    void enqueue()
    {
        int x;
        cout<<"enter the data:\t";
        cin>>x;
        node*temp=new node;
        temp->data=x;
        temp->next=NULL;
        if(front==NULL)
        {
            front=rear=temp;
        }
        else
            rear->next=temp;
            rear=temp;
        cout<<"\nInsertion is Success!!!\n";
    }
    void dequeue()
    {
        node*temp=front;
        if(front==NULL)
            cout<<"queue is empty:\n";
        else
            cout<<temp->data<<"\t";
            front=front->next;
        free(temp);
    }
    void display()
{
   if(front == NULL)
      cout<<"\nQueue is Empty!!!\n";
   else{
      node*temp = front;
      while(temp->next != NULL){
	 cout<<temp->data<<"\t";
	 temp = temp -> next;
      }
      cout<<temp->data;
   }
}
};
int main()
{
    queue_link_list a;
    int choice;
   //clrscr();
   cout<<"\n:: Queue using Linked List ::\n";
   while(1){
      cout<<"\n****** MENU ******\n";
      cout<<"1. ENQUEUE\n2. DEQUEUE\n3. Display\n4. Exit\n";
      cout<<"Enter your choice: ";
      cin>>choice;
      switch(choice)
      {
	 case 1: a.enqueue();break;
	 case 2: a.dequeue(); break;
	 case 3: a.display(); break;
	 case 4: exit(0);
	 default: cout<<"\nWrong selection!!! Please try again!!!\n";
      }
   }
}

