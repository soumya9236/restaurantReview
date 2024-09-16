#include "PriorityQueue.hpp"
#include <limits.h>

using namespace std;

void swap(ReviewInfo *a, ReviewInfo *b)
{
    // swaping values in the heap array 
    ReviewInfo temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
}

/*
Constructor for our MinHeap implementation
*/
PriorityQ::PriorityQ(int cap)
{ 
    

    capacity = cap;  // capacity to the cap value given 
    currentSize = 0; // set the current size to zero 
    heapArr = new ReviewInfo[cap]; // heap array to new array on heap 

}

/*
Destructor
*/
PriorityQ::~PriorityQ()
{
    delete[] heapArr; // delete the whole array of the heap 

}

/*
Finds the parent of a node, given its index.
*/
int PriorityQ::parent(int index)
{
    return((index - 1)/2); // finds the parent value on an array 

}

/*
Returns the left child of a node.
*/
int PriorityQ::leftChild(int index)
{
    return((2*(index)+ 1)); // left child in array 


}

/*
Returns the right child of a node.
*/
int PriorityQ::rightChild(int index)
{
    return(2*(index)+ 2); // right child in array 

}

void PriorityQ::peek()
{
    if(currentSize == 0)
    {
        cout << "no record found" << endl;
    }
    else // print out the first one only so use heapArr[0]; 
    {
        cout << "Restaurant: "<< heapArr[0].restaurantName << endl; // 
        cout << "Customer:" << heapArr[0].customer << endl;
        cout << "Review:" << heapArr[0].review << endl;
        cout << "Time:" << heapArr[0].time << endl; 

    }

}

void PriorityQ::heapify(int i)
{
    // heapify using parent value, swap current and parrent and set the index to parent value and then continue to heapfify upwards 
    int parentValue = parent(i); // find the parent value by using the parent function to find its place in the array 
    while((parentValue != i) && (heapArr[i].time > heapArr[parentValue].time)) // checks if the node's parent time is smaller 
    {
        swap(&heapArr[i], &heapArr[parentValue]); // if it is swap the values 
        i = parentValue; // set the current index to parent valuw 
        parentValue = parent(i); // change parent value to new parent 
    }



}

void PriorityQ::insertElement(ReviewInfo restaurant)
{

    // to insert element set the restaurnt into current size then heapify based on that current size, and then add to current size 
    if(currentSize == capacity)
    {
        cout << "Maximum heap size reached. Cannot insert anymore."<<endl;
    }
    else 
    {
        heapArr[currentSize] = restaurant; // set the new current size 
        heapify(currentSize); // now heapify using parent node with this current size 
        currentSize++; // add to the curent size 

       


        // heapArr[currentSize] = restaurant; 
        // int current = currentSize;
        // int parentValue = parent(currentSize); 
        // while((current!= parentValue) && (heapArr[currentSize].time > heapArr[parentValue].time))
        // {
        //     swap(heapArr[parentValue],heapArr[current]);
        //     current = parentValue;  
        //     parentValue = parent(current); 
           
        // }
        // currentSize++; 
    }
    



    
}

/*
Prints the elements in the heap
*/
void PriorityQ::print()
{
  
    //cout << "Restaurant: " << heapArr[0].restaurantName << endl; 
    for (int i = 0; i < currentSize; i++)
    {
        cout << "\t" << "Customer: " << heapArr[i].customer << endl; // print each value for that size in priority queue
        cout << "\t" << "Review: " << heapArr[i].review << endl;
        cout << "\t" << "Time: " << heapArr[i].time << endl;
        cout << "\t" << "=====" << endl;

    }
        
   // }

}


void PriorityQ::pop()
{

    // pop make a struct instance of review infor and then swap the top value to the bottom, then subract out current size, and then heapify 
    ReviewInfo temp; 
    if(currentSize == 0)
    {
        return; 
    }
    // temp = heapArr[0]; 
    // heapArr[0] = heapArr[currentSize]; 
    if(currentSize == 1)
    {
        currentSize--; 
        return; 
    }

    swap(heapArr[0],heapArr[currentSize-1]); // swap because for when you pop they need to switch 
    currentSize--; // then current size decreases 

  
    int highestValue = 0; // set a value for highest  
    int current = 0; // set a current bvalue 
    while(highestValue < currentSize) // while that highest value is less than the current size 
    {
        int rightChild1 = rightChild(highestValue); // right child value 
        int leftChild1 = leftChild(highestValue); // left child value 
    
        if ((leftChild1 < currentSize) && (heapArr[leftChild1].time > heapArr[highestValue].time)) // if left is greater than highest value 
        {
            highestValue = leftChild1; // make the highest value the left child 
        }
        if ((rightChild1 < currentSize) && (heapArr[rightChild1].time > heapArr[highestValue].time)) // if right is greater than highest value 
        {
            highestValue = rightChild1; // make the highest value the right child 
        }
        if (highestValue != current) 
        {
            swap(&heapArr[current], &heapArr[highestValue]); // swap 
            current = highestValue; // make the current value the highest value 
        }
        else 
        {
            break; 
        }

       
    }
        

}


 
        

    
   

