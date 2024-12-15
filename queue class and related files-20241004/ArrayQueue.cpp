//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT queue: Circular array-based implementation.
 Listing 14-5.
 @file ArrayQueue.cpp */

//#include "ArrayQueue.h"  // Header file

template<class ItemType, int MAX_QUEUE>
ArrayQueue<ItemType, MAX_QUEUE> ::ArrayQueue() 
{
	Front = 0; 
	Back = -1;
	Count = 0;
} // end default constructor

template<class ItemType, int MAX_QUEUE>
bool ArrayQueue<ItemType, MAX_QUEUE>::empty() const
{
   return Count == 0;// if (count==0) return true; else return false; 
} // end empty

template<class ItemType, int MAX_QUEUE>
bool ArrayQueue<ItemType, MAX_QUEUE>::push(const ItemType& newEntry) 
{
   bool result;
   if (Count < MAX_QUEUE) // Queue has room for another item
   {	  
	   Back = (Back + 1) % MAX_QUEUE; // back contains the location of last element
	   items[Back] = newEntry;
	   Count++;
	   result = true;
   } // end if
   else
	   result = false; // no more room
   
   return result;
} // end enqueue

template<class ItemType, int MAX_QUEUE>
bool ArrayQueue<ItemType, MAX_QUEUE>::pop() // removing front
{
	bool result;
	if (!this->empty()) // *this is the default object
	{
		Front = (Front + 1) % MAX_QUEUE; // front will circle back to the beginning
		Count--;
		result = true;
	} 
	else
		result = false;
   
   return result;
} // end pop

template<class ItemType, int MAX_QUEUE>
bool ArrayQueue<ItemType, MAX_QUEUE>::front(ItemType & frontEntry) const
{

	if (empty())
		return false;
	else
	{ // Queue is not empty; 
		frontEntry = items[Front];
		return true;
	}
   
} // end front

template<class ItemType, int MAX_QUEUE>
vector<ItemType> ArrayQueue<ItemType, MAX_QUEUE>::toVector() const
{
	vector<ItemType> QC; // QueueContent 
	int j = Front;
	for (int i = 0; i < Count; i++) // i is just the LCD, counting the iteration 
	{
		// queueContents[i]=items[j];
		QC.push_back(items[j]);
		j = (j + 1) % MAX_QUEUE; // if (j==max-1) j=0; else j++;
	}
	return QC;
}  // end toVector

// template<class ItemType,int MAX_QUEUE>
// void ArrayQueue<ItemType,MAX_QUEUE>::swap(){
// int N=Count/2;
// vector<ItemType> v;
// int i=0;
// for(int j=Count-N;j<Count;j++){
// 	v[i++]=items[j];
// }
// for(int j=0;j<Count-N;j++){
// 	v[i++]=items[j];
// }
// int index=0;
// for(int j=0;j<v.size();j++){
// 	items[j]=v[j];
// }
// }
template<class ItemType,int MAX_QUEUE>
void ArrayQueue<ItemType,MAX_QUEUE>::swap() {
    // int N = Count / 2;
    // vector<ItemType> v(Count);  // Properly initialize the vector with size Count
    // int i = 0;
    
    // // Move the second half to the front of the vector
    // for (int j = Count - N; j < Count; j++) {
    //     v[i++] = items[j];
    // }
    
    // // Move the first half to the end of the vector
    // for (int j = 0; j < Count - N; j++) {
    //     v[i++] = items[j];
    // }
    
    // // Copy the vector back to the queue's items array
    // for (int j = 0; j < v.size(); j++) {
    //     items[j] = v[j];
    // }


	int to_swap = Count / 2; 

    if (Count <= 1) { // if the size of queue is 1 or less, no swap needed
        return;
    }

    // Create a temporary array to hold the items
    int temp[Count];

    // Move the second half of the queue to the temporary array
    if(Count%2==0){
    for (int i = 0; i < to_swap; i++) {
        temp[i] = items[(Front + to_swap + i) % Count]; // move the second half
    }}
    else{
         for (int i = 0; i < to_swap; i++) {
        temp[i] = items[(Front + to_swap + i+1) % Count]; // move the second half
    }
    }

    // Move the first half of the queue to the temporary array
    for (int i = 0; i < Count- to_swap; i++) {
        temp[to_swap + i] = items[(Front + i) % Count]; // move the first half
    }

    // Copy the rearranged items back to the original array
    for (int i = 0; i < Count; i++) {
        items[(Front + i) % Count] = temp[i];
    }

    // Reset Front to the beginning
    Front = 0; // Assuming you want the front to start from index 0 after the swap
    Back =Count - 1; // Back should be at the last index after rearranging

}


// End of implementation file.
