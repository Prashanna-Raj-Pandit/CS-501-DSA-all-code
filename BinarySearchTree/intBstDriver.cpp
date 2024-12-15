#include <iostream>
#include <fstream>
//#include "student_bst.h"
#include "int_bst.h"


using namespace std;

int main ()
{

	int_bst tree1;
	int k, tmp;
	for (k=31;k>=1;k--)
	{
		tree1.insert(k);
	//	cout << k << " is done\n";
	}
/*
	cout << "Tree nodes in level order: ";
	vector<int> TC = tree1.toVectorIn();
	for (int k = 0; k < TC.size(); k++)
		cout << TC[k] << " ";
*/
	tree1.preorder(cout, " ");

	cout << "\nenter number to add: ";
	cin >> tmp;

	if (tree1.insert(tmp))
		cout << tmp << " added\n";
	else
		cout << tmp << " already exists, could not add.\n";
		
	cout << "Tree is created\n";
	tree1.preorder(cout, " ");
	cout << "\n Original tree1 height is " << tree1.tree_height() << endl;
		
    int_bst tree2(tree1);

	if (tree1==tree2)
		cout << "Tree1 and tree2 have the same structure and data\n";
	else
		cout << "Tree1 and tree2 are different\n";

	tree1.balance();
	cout << "\nBalanced tree1 height is " << tree1.tree_height() << endl;
	vector<int> TCL = tree1.toVectorLevel();
	for (int k = 0; k < TCL.size(); k++)
		cout << TCL[k] << " ";

	if (tree1.balanced())
		cout << "it's balanced\n";
	else
		cout << "not  balanced\n";

	ofstream fout("temp.out");
	tree1.preorder(fout, " ") ;	



	if (tree1==tree2)
		cout << "Tree1 and tree2 have the same structure and data\n";
	else
		cout << "Tree1 and tree2 are different\n\n";


	tree2.balance();
	cout << "Tree2 is now also balanced\n";
	if (tree1==tree2)
		cout << "Tree1 and tree2 have the same structure and data\n";
	else
		cout << "Tree1 and tree2 are different\n\n";
	
	int num;
	cout << " Enter a number to delete\n";
	cin >> num;
	tree1.delete_node(num);
	cout << "\n\n\n";
	tree1.inorder(cout);

/*
	// Begin of test student 
	student_bst stree;
	student_type tmp; // record var to hold data

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
		stree.preorder(cout, "\n");
		cout << endl;
	}

	student_bst stree2(stree);

	if (stree2==stree)
		cout << "The two trees are equal.\n";
	else
		cout << "Different trees.\n";
	
	student_type *lg=stree.largest(gpa); // include sid as function argument
	cout << "THE LARGEST STUDENT IS \n" << *lg << endl;
	cout << "Please enter the first, and last name of student to be removed.\n Ctrl-Z to stop.\n";
	while (cin >> tmp.fname)
	{
		cin >> tmp.lname;
		stree.delete_node(tmp);
		stree.inorder(cout);
		cout << endl;
		lg=stree.largest(gpa);
		cout << "THE LARGEST STUDENT IS \n" << *lg << endl;
		cout << "Please enter the first, and last name of student to be removed.\n Ctrl-Z to stop.\n";
	}

	if (stree2==stree)
		cout << "Tree equal.\n";
	else
		cout << "The two trees are different.\n";
*/
	
	return 0;

}	
