#include<iostream>
using namespace std;

template <typename t>
class bag{
    private:
    t item;
    int capacity;
    int itemcount;

    public:
    virtual void add()=0;
    virtual void check()=0;
    virtual void count()=0;
    virtual void isEmpty()=0;
    virtual void isFull()=0;

    virtual ~bag()=default;

};