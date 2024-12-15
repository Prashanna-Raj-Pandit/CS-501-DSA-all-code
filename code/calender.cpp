#include<iostream>
using namespace std;

class calender{
private:
int day,month,year;
bool isLeapYear(int year){
    return (year%4==0 && year%100 !=0)|| (year%400==0);
}
int noOfDays(int month,int year){
    switch(month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            return 31; 
        case 4: case 6: case 9: case 11: 
            return 30;
        case 2: return isLeapYear(year)? 29: 28;
        default: return 0;
    }
}
public:
calender (): day(27),month(8),year(2024){}
calender(int d,int m, int y) : day(d), month(m), year(y){}

calender operator+(int days);

calender operator-(int days){
    calender date=*this;
    date.day-=days;
    while(date.day<=0){
        date.month--;
        if(date.month<1){
            date.month=12;
            date.year--;
        }
        date.day+=noOfDays(date.month,date.year);
    }

    return date;

}

void display();

};

calender calender:: operator+(int days){
calender date= *this;               // Creates a copy of the current date (27-08-2024).
date.day+=days;
while(date.day>(date.noOfDays(date.month,date.year))){
    date.day-=date.noOfDays(date.month,date.year);
    date.month++;
    if(date.month>12){
        date.month=1;
        date.year++;
    }
}
return date;
}

void calender:: display (){
    cout<< (day<10 ? "0":"")<<day<<":"
    <<(month<10? "0":"")<<month<<":"
    <<year<<endl;
}

int main(){
    calender c2,past;
    calender future=c2+200; //future=c2.operator+(200)
    past=c2-200;
    future.display();
    past.display();
}