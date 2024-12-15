#include <iostream>
#include <fstream>
#include "student_bst.h"


using namespace std;

void readitems(ifstream& sfin, student_bst &st)
{

	// read student records
	sfin.ignore(100, '\n');			// read and discard the header line
	student_type temp;

	while(	sfin >> temp.fname) // while there is still data
	{
		sfin >> temp.lname >> temp.sid >> temp.gpa;	
		st.insert(temp);

	}// end of while
}




int main ()
{

	// Begin of test student 
	student_bst stree;
	student_type tmp; // record to hold data

	// make the tree
	ifstream sfin("student.dat");
	ofstream sfout("student.out");
	
	readitems(sfin, stree);
	if (stree.isEmpty())
	  cout << "tree is empty\n";
	else
	{
		cout << setw(14) << "Fname(10)"	
			<< setw(14)  << "Lname(10)"
			<< setw(7) << "ID(4)"
			<< setw(5) << "GPA(4)" << endl; 
		stree.inorder(cout);
		cout << endl;
	}
/*
	cout << "*** before max call***\n";
	student_type *lg = stree.Max();

	if (lg)
		cout << *lg << endl << endl;
	else
		cout << "max returns null\n";
*/

	student_bst stree2(stree); // this is deep copying as we overloaded the copy constructor


	if (stree2==stree)
		cout << "The two trees are equal.\n";
	else
		cout << "Different trees.\n";
	

	cout << "Please enter the SID of student to be removed.\n Ctrl-Z to stop.\n";
	while (cin >> tmp.sid)
	{
	//	cin >> tmp.lname;
		stree.delete_node(tmp);
		stree.inorder(cout);
		cout << endl;
//		lg=stree.largest(gpa);
//		cout << "THE LARGEST STUDENT IS \n" << *lg << endl;
		cout << "Please enter the SID of the student to be removed.\n Ctrl-Z to stop.\n";
	}


	// two trees should be different at this point since we are using deep copy
	if (stree2==stree)
		cout << "Tree equal.\n";
	else
		cout << "The two trees are different.\n";


	return 0;

}	
