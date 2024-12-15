#include<iomanip>
#include<iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};


class stack_bylinkedlist
{
private:
    node *head;      
public:
    stack_bylinkedlist(){
        head=NULL;
    }
    void push();
    void pop();
    void peek();
    void display();
};

void stack_bylinkedlist::display(){
        node *temp=new node;
        temp=head;
        while(temp!=NULL){
            cout<<temp->data;cout<<"\t";
            temp=temp->next;
        }
        cout<<"\n";
}

void stack_bylinkedlist::push(){
    cout<<"\nenter the number:";
        int num;
        cin>>num;
        node *temp=new node;
        temp->data=num;
        temp->next=NULL;
        if(head==NULL){
            head=temp;
            // head->data=num;  this cannot be done bcz head is just a pointer variable of type node
            // head->next=NULL;
        }
        else{
            temp->next=head;
            head=temp;
        }
}
void stack_bylinkedlist::pop(){
        node *temp=new node;
        temp=head;
        if(head==NULL){
            cout<<"stack underflow";
        }else{
            cout<<temp->data<< "\tpopped";
            head=temp->next;
            delete(temp);
        }
}

void stack_bylinkedlist::peek(){
        node *temp=new node;
        temp=head;
        cout<<"Top Of Stack is:"<<temp->data<<endl;
}


int main(){
stack_bylinkedlist node;
int choice;

while(1){
    cout<<"1:: PUSH\t2::POP\t3::PEEK\t4::DISPLAY\t5::EXIT";cout<<endl;
    cin>>choice;
    switch(choice){
        case 1: node.push(); break;
        case 2: node.pop(); break;
        case 3: node.peek(); break;
        case 4: node.display(); break;
        case 5: exit(0);
        default: cout<<"enter a valid choice";
    }

}
}