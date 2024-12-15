#include <iostream>


// class Complex {
// private:
//     double real, imag;

// public:
//     Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

//     // Overload binary + operator as a member function
//     Complex operator+(const Complex& other) const {
//         // 'this' is a pointer to the object on the left side of the operator
//         // 'other' is the object on the right side of the operator
//         return Complex(this->real + other.real, this->imag + other.imag);
//     }

//     void display() const {
//         std::cout << "(" << real << " + " << imag << "i)" << std::endl;
//     }
// };

// int main() {
//     Complex c1(3.0, 4.0);  // c1 is the left operand
//     Complex c2(1.0, 2.0);  // c2 is the right operand

//     Complex c3 = c1 + c2;  // c1.operator+(c2) is how the call is interpreted

//     c3.display();  // Output: (4.0 + 6.0i)

//     return 0;
// }

using namespace std;

class complex{

    private:
    float real,img;

    public:

    complex(float r=0.0,float i=0.0):real(r),img(i){}

    complex operator+(complex c1){
        // complex x3;
        // x3.real= c1.real+this->real;
        // x3.img=c1.img+this->img;
        // return x3;
        return complex(this->real+c1.real,this->img+c1.img);
    }
    void display(){
        cout<<real<<"+"<<img<<"j"<<endl;
    }

    friend complex operator-(float val,complex x1);

};

complex operator-(float val,complex x1){
    return complex(val-x1.real,x1.img);
}


int main(){
    complex c1(2,5),c2(3,9),c3;
    c3=c1+c2;
    complex x1(10,10),sub;
    sub=100-x1;
    c3.display();
    sub.display();
    
}