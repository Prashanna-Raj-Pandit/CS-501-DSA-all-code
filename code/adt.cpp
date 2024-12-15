#include<iostream>
using namespace std;

class Base{

    private:

    public:

    virtual void draw()=0; // this is pure virtual function bcz of =0;
    virtual void area()=0;

    // virtual ~Base()=default;
};

class circle: public Base{
    private: int radius;

    public: 

    circle(int r): radius(r){} // parametrized constructor

    void draw() {
        cout<<"drawing a circle"<<"\n";
    }
    void area() {
        cout<<"area of circle is: "<<3.1416*radius*radius<<endl;
    }
};

class square: public Base{
    private: int len;

    public: 
    square(int l): len(l){}// parameterized constructor because there is no default value here.

    void draw() {
        cout<<"drawing a square"<<"\n";
    }
    void area(){
        cout<<"area of square is: "<<len*len<<endl;
    }
};

int main(){
    Base *obj1= new circle(3);
    Base *obj2=new square(5);

    obj1->area();
    obj1->draw();
    obj2->draw();
    obj2->area();

    return 0;
}