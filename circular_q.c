#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#define size 7
int q[size],front=-1,rear=-1;
void enq();
void deq();
void display();
void Swap();
void main()

{
    int choice;
    char ch;
    while(1){
         printf("press 1::ENQUEUE 2::DEQUEUE 3::DISPLAY\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: enq();break;
        case 2: deq();break;
        case 3:display();break;
        case 4: Swap(); break;
        case 5: exit(1); 
        default: printf("INVALID NUMBER\n");break;
    }
    
    }

}
void enq()
{
    int elem;
    if((front==0&&rear==size-1)||(front==rear+1))
    {
        printf("overflow");
    }
    else
    {
        printf("enter the element to be inserted into the Q\n");
        scanf("%d",&elem);
        if(front==-1&&rear==-1)
        {
            front=rear=0;

        }
        else if(front!=0&&rear==size-1)
        {
            rear=0;
        }
        else{
            rear++;
        }
        q[rear]=elem;
    }
}
void deq()
{
    if(front==-1&&rear==-1)
    {
        printf("underflow\n");
    }
    else
    {
        printf("element deleted from queue is %d\n",q[front]);
        if(front==size-1)
        {
            front=0;
        }
        else if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }

}

// void Swap() {
//     int to_swap = size / 2;
//     if (size <= 1) { // If the size of queue is 1 or less, no swap needed
//         return;
//     }

//     // Update the rear index before the swap
//     if (size % 2 == 0) {
//         rear = (rear - to_swap + size) % size; // Move rear to point to the end of the first half
//         printf("rear 1",rear);
//     } else {
//         rear = (rear - to_swap + size) % size; // Move rear to point to the end of the first half
//         printf("rear2 %d",rear);
//     }
//     // Move the front index after the swap
//     front = (front + to_swap+1) % size; // Update front to new position
//     printf("front 1 %d",front);

//     // Now adjust the rear index correctly for the next operation
//     rear = (front + size) % size; // Ensure rear points to the last element
//      printf("front 2 %d",rear);
// }


void Swap() {
    int to_swap = size / 2; // Use Count instead of count, as you have it defined in your class

    if (size <= 1) { // if the size of queue is 1 or less, no swap needed
        return;
    }

    // Create a temporary array to hold the items
    int temp[size];

    // Move the second half of the queue to the temporary array
    if(size%2==0){
    for (int i = 0; i < to_swap; i++) {
        temp[i] = q[(front + to_swap + i) % size]; // move the second half
    }}
    else{
         for (int i = 0; i < to_swap; i++) {
        temp[i] = q[(front + to_swap + i+1) % size]; // move the second half
    }
    }

    // Move the first half of the queue to the temporary array
    for (int i = 0; i < size - to_swap; i++) {
        temp[to_swap + i] = q[(front + i) % size]; // move the first half
    }

    // Copy the rearranged items back to the original array
    for (int i = 0; i < size; i++) {
        q[(front + i) % size] = temp[i];
    }

    // Reset Front to the beginning
    front = 0; // Assuming you want the front to start from index 0 after the swap
    rear = size - 1; // Back should be at the last index after rearranging
}


void display()
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("the queue is empty\n");
    }
    else
    {
        if(front>rear)
    {
        for(i=front;i<size;i++)
        {
            printf("%d\t",q[i]);
        }
        for(i=0;i<=rear;i++)
        {
            printf("%d\t",q[i]);
        }
        printf("\n");
    }
    else{
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",q[i]);
        }

    }
    }

}
