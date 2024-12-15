/** @file ArrayStack.cpp */
#include <cassert> 	// For assert
#include "ArrayOnlyStack.h"	// Header file


template < class ItemType, int MAX_STACK> 
Stack < ItemType, MAX_STACK >::Stack() 
{
	Top = -1;
}   // end default constructor

// Copy constructor and destructor are supplied by the compiler
// why is not necessary here? cuz there is no dynamic memory
template < class ItemType, int MAX_STACK>
bool Stack < ItemType, MAX_STACK >::empty() const
{
	return Top < 0; // if (Top<0) return true; else return false;
}   // end empty

template < class ItemType, int MAX_STACK>
bool Stack < ItemType, MAX_STACK >::full() const
{
	return Top==MAX_STACK-1; 
}   // end of full

template < class ItemType, int MAX_STACK>
bool Stack < ItemType, MAX_STACK >::push(const ItemType & newEntry)
{
	bool result = false;

	if (Top < MAX_STACK - 1)	// Does stack have room for newEntry?
	{
		// Top++; post increment
		items[++Top] = newEntry; //  preincrement: Top++; items[top]=newEntry;
		result = true;
	}	// end if
	return result;
}   // end push

template < class ItemType, int MAX_STACK>
//template < class ItemType, int MAX_STACK>
bool Stack < ItemType, MAX_STACK >::pop()
{
	bool result = false;

	if (!empty()) // ie., Top>=0
	{
		Top--;
		result = true;
	}	// end if
	return result;
}   // end pop

template < class ItemType, int MAX_STACK>
ItemType Stack < ItemType, MAX_STACK >::top() const
{
	//assert(!isEmpty());	// Enforce precondition
	if (!empty())				// Stack is not empty; return top
	  return items[Top];
}   // end peek



template<class ItemType, int MAX_STACK>
vector<ItemType> Stack<ItemType, MAX_STACK>::toVector() const
{
	vector<ItemType> stackContents;
	for (int i = 0; i <=Top; i++)
		stackContents.push_back(items[i]);

	return stackContents;
}  // end toVector

