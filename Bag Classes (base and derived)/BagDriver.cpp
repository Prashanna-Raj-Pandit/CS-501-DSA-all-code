#include "BagInterface.h"
#include "ArrayBag.h"
#include "LinkedBag.h"
#include <iostream>
#include <string>
#include <cctype> // contains the toupper function
using namespace std;


void displayBag(BagInterface < string > *bagPtr)
{
	cout << "The bag contains " << bagPtr->getCurrentSize() << " items:" << endl;
	vector < string > bagItems;
	bagItems = bagPtr->toVector();
	int numberOfEntries = bagItems.size();
	for (int i = 0; i < numberOfEntries; i++)
	{
		cout << bagItems[i] << " ";
	}	// end for
	cout << endl << endl;
}   // end displayBag

void bagTester(BagInterface < string > *bagPtr)
{
	cout << "isEmpty: returns " << bagPtr->isEmpty() << "; should be 1 (true)" << endl;
	string items[] = { "one", "two", "three", "four", "five", "one" };
	cout << "Add 6 items to the bag: " << endl;
	for (int i = 0; i < 6; i++)
	{
		bagPtr->add(items[i]); // or, cin >> oneString; aBag.add(oneString);
	}	// end for
	displayBag(bagPtr);
	cout << "isEmpty: returns " << bagPtr->isEmpty() << "; should be 0 (false)" << endl;
	cout << "getCurrentSize returns : " << bagPtr->getCurrentSize() << "; should be 6" << endl;
	cout << "Try to add another entry: add(\" extra \") returns " << bagPtr->add("extra") << endl;
	displayBag(bagPtr);
}   // end bagTester


int
main()
{
	
	// delayed binding - binding occurs at run time
	// delayed = run time
	// early = compile time
	BagInterface < string > *bagPtr = nullptr; // bagPtr could point to either kind of bag
	ArrayBag < int > aBag; // early binding, aBag is bound to an ArrayBag object
	char userChoice;
	cout << "Enter 'A' to test the array-based implementationn or\n"
	<< "Enter 'L' to test the link-based implementation: ";
	cin >> userChoice;
	if (toupper(userChoice) == 'A') // same as (userchoice=='a' || userchoice=='A')
	{
		bagPtr = new ArrayBag < string >(); // create an array bag and let bagPtr points
		cout << "Testing the Array-Based Bag:" << endl;
	}
	else
	{
		bagPtr = new LinkedBag < string >(); // create a linkedBag ...
		cout << "Testing the Link-Based Bag:" << endl;
	}	// end if
	cout << "The initial bag is empty." << endl;
	bagTester(bagPtr);
	delete bagPtr;
	bagPtr = nullptr;
	

	LinkedBag<int> bag;

	// 3. store the numbers 1 through 10 in *bPtr
	for (int k = 1; k <= 10; k++)
		bag.add(k%3);

	vector<int> BC1 = bag.toVector();
	for (int j = 0; j < BC1.size();j++)
		cout << BC1[j] << " ";
	cout << endl;

	bag.RD(2);


	vector<int> BC2 = bag.toVector();
	for (int j = 0; j < BC2.size();j++)
		cout << BC2[j] << " ";
	cout << endl;

	cout << "All done!" << endl;
	system("pause");

	return 0;
}   // end main