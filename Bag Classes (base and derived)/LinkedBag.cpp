//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT bag: Link-based implementation.
@file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>

template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount; // whose itemCount is this?
								// default bag object
	Node<ItemType>* origChainPtr = aBag.headPtr;  
	// Points to nodes in original chain of aBag, used to walk through the original list

	if (origChainPtr == nullptr)
		headPtr = nullptr;  // Original bag is empty
	else
	{
		// Copy first node
		headPtr = new Node<ItemType>(); // which object does this headptr belong to?
		headPtr->item = origChainPtr->item; 
		// copy value from head of aBag to head of  *this bag
		// headPtr->item = origChainPtr->item; // copy if node is struct

		// Copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
		origChainPtr = origChainPtr->next;     // Advance original-chain pointer

		while (origChainPtr != nullptr)
		{
			// Get next item from original chain
			// ItemType nextItem = origChainPtr->item;

			// Create a new node containing the next item
			Node<ItemType>* newNodePtr = new Node<ItemType>(origChainPtr->item);

			// Link new node to end of new chain
			newChainPtr->next=newNodePtr;

			// Advance pointer to new last node
			newChainPtr = newChainPtr->next;

			// Advance original-chain pointer
			origChainPtr = origChainPtr->next;
		}  // end while
		// at this point, what's the value of origChainPtr? null or 0
		newChainPtr->next(nullptr);              // Flag end of chain
	}  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
	clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
	return itemCount;
}  // end getCurrentSize

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
	// Add to beginning of chain: new node references rest of chain;
	// (headPtr is null if chain is empty)        
	Node<ItemType>* nextNodePtr = new Node<ItemType>(); // allocate space
	nextNodePtr->item= newEntry;  // set new node item value
	nextNodePtr->next=headPtr;  // New node points to chain
	//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); 
	// alternate code

	headPtr = nextNodePtr;          // New node is now first node
	itemCount++;

	return true;
}  // end add

template<class ItemType>
vector<ItemType> LinkedBag<ItemType>::toVector() const
{
	vector<ItemType> bagContents;
	Node<ItemType>* curPtr = headPtr;
	int counter = 0;
	while ((curPtr != nullptr) ) // && (counter < itemCount))
	{
		bagContents.push_back(curPtr->item);
		curPtr = curPtr->next;
		counter++;
	}  // end while

	return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
	Node<ItemType>* entryNodePtr = getPointerTo(anEntry); // get location of the node
														// with matching item value as entry
	bool canRemoveItem =  (entryNodePtr != nullptr);
	if (canRemoveItem)
	{
		// Copy data from first node to located node
		entryNodePtr->item = headPtr->item;

		// Delete first node
		Node<ItemType>* nodeToDeletePtr = headPtr;
		headPtr = headPtr->next; // move headptr one node down

		// Return node to the system
		nodeToDeletePtr->next=nullptr;
		delete nodeToDeletePtr;
		nodeToDeletePtr = nullptr;

		itemCount--;
	} // end if

	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
	Node<ItemType>* nodeToDeletePtr = headPtr;
	while (headPtr != nullptr)
	{
		headPtr = headPtr->next;

		// Return node to the system
		nodeToDeletePtr->next=nullptr; // prevent UAF attack
		delete nodeToDeletePtr; 

		nodeToDeletePtr = headPtr;
	}  // end while
	   // headPtr is nullptr; nodeToDeletePtr is nullptr

	itemCount = 0;
}  // end clear


template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
	int counter = 0;
	Node<ItemType>* curPtr = headPtr;
	while ((curPtr != nullptr) && (counter < itemCount))
	{
		if (anEntry == curPtr->item)
		{
			frequency++;
		} // end if

		counter++;
		curPtr = curPtr->next;
	} // end while

	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
/*
	if (getPointer(anEntry) == nullptr)
	  return false;
	 else
	  return true;
*/

}  // end contains

   // private
   // Returns either a pointer to the node containing a given entry 
   // or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
	bool found = false;
	Node<ItemType>* curPtr = headPtr; 

	while (!found && (curPtr != nullptr)) // not found AND there is still item in the list
	{
		if (anEntry == curPtr->item)
			found = true; // could also be return curPtr;
		else
			curPtr = curPtr->next;
	} // end while

	return curPtr; // curPtr would be null if not found
} // end getPointerTo

template<class ItemType>
bool LinkedBag<ItemType>::RD( ItemType Target)
{
	int count = getFrequencyOf(Target);
	for (int j = 0; j < count - 1; j++)
		remove(Target);
	return count > 0;

}

