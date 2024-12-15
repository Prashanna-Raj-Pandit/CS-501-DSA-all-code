#include<iostream>
using namespace std;

template<typename t>
struct node
{
    t item;
    node *next;
    
};

template <typename t>
class linkedBag
{
public:
   virtual bool check(const t& item)=0;
    virtual int count(const t& item)=0;
    virtual void display()=0;
    virtual void add(const t& item)=0;
    virtual bool remove(const t& item)=0;
    virtual ~linkedBag(){}
};

template<typename t>
class linked: public linkedBag<t>{
    private:
    node<t> *head;
    int itemcount=0;
    public:
    linked():head(NULL){}

    void add(const t& data) override{
        node<t> *temp=new node<t>;
        temp->item=data;
        temp->next=NULL;
        if (head==NULL){
            head=temp;
            itemcount++;

        }
        else{
            temp->next=head;
            head=temp;
            itemcount++;
        }
}

    int count(const t& item) override{
        node<t> *temp=new node<t>;
        temp=head;
        int count=0;
        while (temp!=NULL)
        {
            if(temp->item==item){
                count++;
            }
            temp=temp->next;
        }
        return count;
    }

    bool check(const t& item) override{
        
        if (count(item)>0){
            return true;
        }
        else{
            return false;
        }
    }
    void display() override {
        node<t> *temp=new node<t>;
        temp=head;
        while(temp!=NULL){
            cout<<temp->item<<"\t"<<endl;
            temp=temp->next;
        }
    }

    bool remove(const t& item)override{
        node<t> *temp,*temp2=new node<t>;
        temp=head;
        if(temp==NULL){
            return false;  //bag is empty
        }else{
            if(temp->item==item){
                head=head->next;
                delete(temp);
                return true;
            }
            else{
                while(temp!=NULL){
                    if(temp->next->item==item){
                        temp2=temp->next;
                        temp->next=temp->next->next;
                        delete(temp2);
                        return true;
                    }else{
                        temp=temp->next;
                    }
                }
                return false;
            }
        }
    }
};

int main(){

linked<int> l1;
l1.add(2);
l1.add(5);
l1.add(5);
l1.add(10);
l1.add(50);
l1.add(9);

l1.display();
bool isFound = l1.check(5);

cout << "Item 5 found: " << (isFound ? "Yes" : "No") << endl;
cout<<(l1.remove(2)?"removed":"not present")<<endl;
cout<<"\nthe frequency of 5 is:"<<l1.count(5)<<endl;
l1.display();
return 0;
}