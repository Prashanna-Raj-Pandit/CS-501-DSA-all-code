#include<iostream>
using namespace std;

class base{

    protected: 
    int length,breadth;

    public:

    base(){
        length=0;
        breadth=0;
    }

    base(int l,int b): length(l),breadth(b){}

    virtual void display(){
        cout<<"the are of rectangle is:"<<length*breadth<<endl;
    }
};

class funtion_overriding: public base
{
private:
    int height;
public:
    funtion_overriding(int l,int b,int h):base(l,b),height(h){}

    void display() override{
        cout<<"the volume of rectangle is:"<<length*breadth*height<<endl;
    }
};

int main(){

    base *b;
    funtion_overriding f(5,10,15);
    b=&f;
    b->display();
    return 0;
}
