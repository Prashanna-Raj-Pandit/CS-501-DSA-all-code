#include<iostream>
using namespace std;

template <typename t>
class bag{    // bag interface
    public:
    virtual bool add(const t& item)=0;  // this is pure virtual funtion coz of "=0"
    virtual bool remove(const t& item)=0;
    virtual bool check(const t& item)=0;
    virtual int count(const t& item)=0;
    virtual bool isEmpty()=0;
    virtual bool isFull()=0;
    virtual int getCurrentSize()=0;

    virtual ~bag()=default;

};

template <typename t>
class arrayBag:public bag<t>
{
    private:
    t item;
    static const int capacity=10;
    int itemcount;
    int array[capacity];

    public:

    arrayBag():itemcount(0){} // default constructor; arrayBag(){ itemcount=0}

    int getCurrentSize() override{
    return itemcount;
   }

    bool isEmpty() override {
        return itemcount==0;
    }
    bool isFull() override {
        return itemcount>=capacity;
    }
    bool add(const t& item) override{
        if(itemcount<=capacity){
            array[itemcount]=item;
            itemcount++;
            return true;
        }
        else return false;
    } 
    bool remove(const t& item)override{
        int count;
        for(count=0;count<capacity;count++){
            if(array[count]==item){
                array[count]=array[--itemcount];
                return true;
            }
        }
        return false; //item not found
    }

    bool check(const t& item) override{
        for(int i=0;i<=itemcount;i++){
            if(array[i]==item){
                return true;
            }
        }
        return false;
    }

int count(const t& item)override{
    int count=0;
    for(int i=0;i<capacity;i++){
        if(array[i]==item){
            count++;
        }
    }
    return count;
}
};
int main(){
    arrayBag<int> a1;
    a1.add(3);
    a1.add(10);
    a1.add(15);
    a1.add(3);
    cout<<(a1.check(3)?"yes the bag contains 3":"no the bad doesn't contain 3")<<endl;
    cout<<"total numbers in bag:"<<a1.getCurrentSize()<<endl;
    cout<<"the frequency of 3 is:"<<a1.count(3)<<endl;
    return 0;
}