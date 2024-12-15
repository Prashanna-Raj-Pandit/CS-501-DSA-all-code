#include<iostream>
using namespace std;

struct studentType
{
    string EID;
    string lastname;
    int score;
};

class arrayBag{
    private:
        int itemcount;
        static const int capacity=10;
        studentType students[capacity];
    public:
        arrayBag(): itemcount(0){}
        bool add(const studentType& item){
            if(itemcount<capacity){
                students[itemcount++]=item;
                return true;
            }
            else{
                return false;
            }
        }
        void display(){
            for(int i=0;i<capacity;i++){
                cout<<students[i].EID<<students[i].lastname<<students[i].score<<endl;
            }
        }

};
int main(){
    studentType student;
    arrayBag bag;

    for (int i=0;i<10;i++){
        cout<<"enter the details of "<<i+1<<"student:"<<endl;
        cout<<"enter ID:";
        cin>>student.EID;
        cout<<"enter Last name:";
        cin>>student.lastname;
        cout<<"enter his/her score:";
        cin>>student.score;

        if(!bag.add(student)){
            cout<<"sorry the bag is full";
            break;
        }
        cout<<endl;
    }
    bag.display();
    return 0;
}
