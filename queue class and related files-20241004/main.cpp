//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "ArrayQueue.h" // ADT Queue operations
//#include <queue>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void queueTester(ArrayQueue<string, 10>* queuePtr)
{
	string items[] = {"one", "two", "three", "four", "five", "six"}, temp;
	cout << "Empty: " << queuePtr->empty() << endl;
	for (int i = 0; i < 6; i++)
   {
		cout<<"Adding " << items[i] << endl;
      bool success = queuePtr->push(items[i]);
      if (!success)
         cout << "Failed to add " << items[i] << " to the queue." << endl;
	}
   
	if (!queuePtr->empty())
	{
		queuePtr->front(temp);
		cout << "Front of queue is " << temp << endl;
	}

}  // end queueTester


int main()
{
	// A.Declare an integer queue named A of size 100. (5 points)

	ArrayQueue<char, 100> A;

	// Enter the 26 letters (upper case) into queue A.
	for (char c = 'A'; c <= 'Z'; c++)
		if (A.push(c) == false)
		{
			cout << "queue is full, failed at char " << c << endl;
			break;
		}

	// A.fastpass(3);˜
	// A.swap();

	// print everything 
	vector<char> V = A.toVector(); // dump everything from A to V
	for (int k = 0; k < V.size(); k++)
		cout << V[k] << " ";
	cout << endl;


	system("pause");

   return 0;
}  