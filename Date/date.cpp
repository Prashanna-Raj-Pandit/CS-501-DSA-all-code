// date.cpp
// This file contains the definition of member functions of the date class

#include "date.h" // to include a user-defined header file, date.h


/*
void whatever ()
{ 
	cout << month << endl;
}
*/


// constructor two, with 3 arguments.
date::date (int m, int d, int y) // m, d, y are formal arguments
{
	// m = month; DON"T DO THIS
	month = m;
	day = d;
	year = y;
}

// arguments are given default values
// d1.assignDate(9,29,2000);
// di is the DEFAULT (OR *THIS) object
void date::assignDate (int m, int d, int y) 
{
	month = m;
	day = d;
	year = y;
}

// d2.displayShort();
void date::displayShort (void)
{
	cout << month << "-" << day << "-" << year << endl;
}

void date::nextDay ()
{

	int dim; // days in the current month, we can/should name this daysInCurrentMonth

	switch (month)
	{
	  case 4: case 6: case 9: case 11:
		dim = 30; break;
	  case 1: case 3: case 5: case 7: case 8:
	  case 10: case 12: 
		dim = 31; break;
	  case 2: 
		if ( (year%400==0) || ((year%4==0) && (year%100>0)))
			dim=29; // days of Feb in a leap year
		else
			dim = 28; // normal length
		break;
	}

	if (day < dim) 
	  day++;
	else// end of month
	{
	  day = 1;
	  if (month < 12) 
	    month++;
	  else { // end of year
	    month = 1;
	    year++;
	  }
	}
}

// d2 = d1.operator+(n);
// d2 = d1 + n;
date date::operator+ (int days)	  
{
	date result;
	// copy the value of default object to d 
	result = *this; 
	// or use the following:
	// result.month = month; result.day=day; result.year=year;
	// *this is the name of the default object
	for (int i=0;i<days;i++)
	  result.nextDay();
	return result;
}

// example usage: d1+= 5;
void date::operator+=(int days)
{
	for (int i = 0; i < days; i++)
		this->nextDay();			// (*this).nextDay();
}

// if (d1==d2) ...
bool date::operator==(date d)
{
	/*
	if (d.year==year && d.month==month && d.day==day)
		return true;
	else
		return false;
   */	
	return (d.year==this->year && d.month==month && d.day==day);
	// return *this==d;

}

// cout << d1 << d2;
// same as (cout << d1) << d2;
// same as operator<<(operator<<(cout, d1), d2);

ostream &operator<< (ostream &output, date d)
{
	output << " " << d.month << "/" << d.day << "/" << d.year;
	return output;
}





/*
ostream & operator<< (ostream &output, date d)
{
	output << " " << d.month << "-" << d.day << "-" << d.year;
	return output;
}
*/

// cin >> d1;
istream & operator>> (istream &input, date &d)
{
	input >> d.month >> d.day >> d.year;
	return input; // this allows statement such as 
				  // cin >> d1 >> d2;
}

date date::operator- (int days)
{
	// dim store the number of days in each month, at the index month 
	int dim[13] = {0,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	date result; // the object to be returned. Note that the default object is not changed.
	result = *this; 
		
	if (days<result.day) // no change for month
	  result.day -= days;
	else	// not enough days in the current month to go back word
	{
	  days -= result.day;	// subtract the days in the current month
      if (result.month == 1) // change to previous month
	  {
 	     result.month=12;
		 result.year--;
	  }
	  else
	     result.month--;
	  while (days > dim[result.month]) // moving back one whole month at a time
	  {
		days -= dim[result.month];
	    if (result.month == 1) // change to previous month
		{ 	  result.month=12; result.year--; }
	  	else
	     	  result.month--;
	 }	  
	  // now, there is not enough days for a whole month
	  result.day = dim[result.month]-days;  // 
	}
	  return result;
}

/*
int date::operator< (date d)
{
	int result;
	// if the year of default obj is less than the year of d
	if (year<d.year)
	  result= 1;
	else if (year==d.year&&month<d.month)
	  result= 1;
	else if (year==d.year&&month==d.month&&day<d.day)
	  result=1;
	else
	  result=0;

	return result;
}
*/