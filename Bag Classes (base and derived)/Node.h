/** @file Node.h */
#ifndef _NODE
#define _NODE

template <class ItemType>
struct Node
{

	ItemType item; // A data item
	Node< ItemType> *next; // Pointer to next node

	Node(); 
	Node(const ItemType& anItem);
	Node(const ItemType& anItem, Node< ItemType> *nextNodePtr);
	//void setItem(const ItemType& anItem);
	//void setNext(Node< ItemType> *nextNodePtr);
	//ItemType getItem() const;
	//Node< ItemType> *getNext() const;

}
; // end Node
#include "Node.cpp"
#endif