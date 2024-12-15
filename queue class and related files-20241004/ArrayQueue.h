//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT queue: Circular array-based implementation.
 Listing 14-4.
 @file ArrayQueue.h */

#ifndef _ARRAY_QUEUE
#define _ARRAY_QUEUE

using namespace std;
#include <vector>

template<class ItemType, int MAX_QUEUE=500>
class ArrayQueue 
{
private:
   ItemType items[MAX_QUEUE]; // Array of queue items
   int Front;                 // Index to front of queue
   int Back;                  // Index to back of queue
   int Count;                 // Number of items currently in the queue
   
public:
   ArrayQueue();
   // Copy constructor and destructor supplied by compiler
   bool empty() const;
   bool push(const ItemType& newEntry);
   bool pop();
   bool front(ItemType &frontEntry) const ;
   int size() { return Count; }
   vector<ItemType> toVector() const; 
   void swap();
      
}; // end ArrayQueue
#include "ArrayQueue.cpp"
#endif