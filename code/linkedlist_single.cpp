#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linkedlist{
    private:
    node *head, *tail;
    public:
    linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void insert_at_head(){
        cout<<"\nenter the number:";
        int x;
        cin>>x;
        node *temp=new node;
        temp->data=x;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else{
            temp->next=head;
            head=temp;
        }

    }
    void insert_at_tail(){
        cout<<"enter the number:";
        int x;
        cin>>x;
        node *temp=new node;
        temp->data=x;
        temp->next=NULL;
        tail->next=temp;
        tail=temp;

    }
    int total_items(){
        node*temp=head;
        int items=0;
        while(temp!=NULL){
            items++;
            temp=temp->next;

        }
        return items;
    }
    void insert_at(){
        int position;
        cout<<"enter the position:";
        cin>>position;
        int totalitems=total_items();

        if(position>totalitems){
            cout<<"Out of range. enter a valid place.";
        }
        else{
            cout<<"enter the number:";
            int x;
            cin>>x;
            node *temp= new node;
            node *temp2=new node; temp2=head; //for looping
            temp->data=x;
            temp->next=NULL;
            if (position==1){
                temp->next=head;
                head=temp;
            }
            else{
                for(int i=0;i<position-2;i++){
                    temp2=temp2->next;
                }
                temp->next=temp2->next;
                temp2->next=temp;
            }
        }
        
        
    }
    void print(){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data;cout<<"\t";
            temp=temp->next;
        }
        cout<<"\n";
    }
    void delete_node(){
        cout<<"enter the position";
        int pos;
        cin>>pos;
        node *temp=head;
        node *temp2=head;

        int items=total_items();
        if(pos<=items){
            if (pos==1){
                head=head->next;
            }
            else{
                for(int i=0;i< pos-2;i++){
                    temp=temp->next;
                }
                temp2=temp->next;
                temp->next=temp2->next;

            }
        }
        else{
            cout<<"enter a valid range";
        }    
    }   

};

int main()
{
    linkedlist node;
    int choice;
    while(1){
        cout<<"PRESS 1::INSERT AT HEAD\t 2::INSERT AT TAIL\t3::INSERT AT__NODE\n4::DELET\t5::PRINT\t6::EXIT\n ";
        cin>>choice;
        switch (choice)
        {
        case 1:node.insert_at_head(); break;
        case 2: node.insert_at_tail();break;
        case 3: node.insert_at();break;
        case 4:node.delete_node(); break;
        case 5: node.print();break;
        case 6:exit(0);
        default:cout<<"invalid choice"; break;
        }
    }
    return 0;
}