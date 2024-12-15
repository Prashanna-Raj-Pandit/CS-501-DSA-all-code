// date.h
// this user-created header file contains the definition of the class date

#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class date 
{
	private:
	  int month, day, year; // member elements

	public:
		date() { month = day = year = 1; } // constructor, inline implementation
	  date(int, int, int);  // another constructor
	  void assignDate (int, int, int);
	  void displayShort();
	  void nextDay(void);

	  date operator+ (int);
	  date operator- (int);
	  void operator+=(int);
	  bool operator==(date);
//	  bool operator<(date);

	friend ostream & operator<< (ostream &, date);	// non-member 
													// friend function
	friend istream & operator>> (istream &, date &);
};

#endif 