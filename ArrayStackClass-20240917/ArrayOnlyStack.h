/** ADT stack: Array-based implementation.
@file ArrayOnlyStack.h */
#ifndef _ARRAY_STACK
#define _ARRAY_STACK
#include <vector>
#include <cstdlib>

using namespace std;

// ex., Stack<string, 2000> S1; // S1 is a string stack of size 2000
// ex., Stack<int> S2;	// S2 is an int stack of size of 1000 (default)
template < class ItemType, int MAX_STACK=1000 > 
class Stack 
{
private:
	ItemType items[MAX_STACK];	// Array of stack items
	int Top;					// Index of top of stack

public:
	Stack();	// Default constructor
	bool empty() const;
	bool full() const;
	bool push(const ItemType & newEntry);
	bool pop();
	ItemType top() const;
	vector<ItemType> toVector() const;
	// add a contain function that check to see if an item is in the stack
	bool contain(ItemType entry) // inline imp
	{
		vector<ItemType> v=toVector();
		// for (int k = 0; k <= Top; k++)
		// for(int k: items)
		for(ItemType k: v)
			// if (entry == items[k])
			if(entry==k)
				return true;
		return false;
	}


	
};  // end Stack

#include "ArrayOnlyStack.cpp"
#endif