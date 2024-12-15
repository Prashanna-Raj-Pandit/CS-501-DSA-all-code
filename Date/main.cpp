// This file contains the program that uses/tests the date class 
// This is often called the driver program

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "date.h"	// include a user-defined header file
//#include "temp.h"

using namespace std;

int main (void)
{
	date d1, d2(8, 21, 2024), d3;


	cout << "200 days from today is " << d2.operator+(200) << endl << endl;
//	d2.displayShort();
//	cout << endl;
	d2=date(6,2,3000); // calling constructor explicitly 
	d2.displayShort();
	cout << endl;

	int n;

//	d1 = d2-100; // we overloaded the op so that we can call the function like this
				//  typical ways of calling a member function
//	obj2=obj.fname(arg);;

//	d1=d2.operator+(50); 
	d1 = d2 + 50;
//	d1 = d2.operator+(50);
//	d1.displayShort();

	cout << d1 << endl;	// same as the call operator<<(cout, d1);
						// this works if << is overloaded

//	operator<<(operator<<(cout,d1), d2) << endl; 

   cout << d1 << endl << d2 << endl;

//	system("pause");
	return 0;
}	
			

