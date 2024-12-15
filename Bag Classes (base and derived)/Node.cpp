/** @file Node.cpp */
//#include "Node.h"
#include <cstddef>

// default constructor - no argument
template < class ItemType > Node < ItemType >::Node() //:next(nullptr)
{
	next = nullptr; // node<string> *p;
					// p = new node<string>; 
}   // end default constructor

template < class ItemType > Node < ItemType >::Node(const ItemType & anItem) :
	item(anItem),
	next(nullptr) // using initializer 
					// node<string> *p;
					// p = new node<string>("two"); 
{
}   // end constructor

template < class ItemType > Node < ItemType >::Node(const ItemType & anItem,
	Node < ItemType > *nextNodePtr) :
	item(anItem),
	next(nextNodePtr)
	// usage:
	// node<string> *q;
	// q = new node<string>("three", p); 
{
}   // end constructor

/*
template < class ItemType > void Node < ItemType >::setItem(const ItemType & anItem)
{
	item = anItem;
}   // end setItem

template < class ItemType > void Node < ItemType >::setNext(Node < ItemType > *nextNodePtr)
{
	next = nextNodePtr; // change value of next field of the current node
}   // end setNext

template < class ItemType > ItemType Node < ItemType >::getItem() const
{
	return item;
}   // end getItem

template < class ItemType > Node < ItemType > *Node < ItemType >::getNext() const
{
	return next;
}   // end getNext
*/