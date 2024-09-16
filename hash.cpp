// CPP program to implement hashing with chaining
#include <iostream>
#include "hash.hpp"
#include <sstream>

using namespace std;

node* HashTable::createNode(string restaurantName, node* next)
{
    // new node on the heap 


    node *newNode = new node{restaurantName, PriorityQ(50), next}; // create a new node on the heap, and call priority Q 
    // newNode->restaurantName = restaurantName; 
    // newNode->next = next; 
    // newNode->pq = *(new PriorityQ(50));
    return newNode; 
    
}

HashTable::HashTable(int bsize)
{
    tableSize = bsize;
    //cout << "hi1" << endl; 
    numCollision = 0; 
    table = new node*[tableSize]; // make memory for the table 
    for (int i = 0; i < tableSize; i++) {
        table[i] = nullptr; // set everything in table to null ptr 
    }
    //cout << "hi2" << endl; 
    // for(int i = 0; i < tableSize; i++)
    // {
    //     table[i] = new node;
    //     //cout << "hi3" << endl; 
    //     table[i]->next = NULL; 
    //    //cout << "hi4" << endl; 
    // }



}

HashTable::~HashTable() 
{

    for(int i = 0; i < tableSize; i++) 
    { // For every bucket
        node *temp = table[i];
        //node *temp_next; 
        //node *temp_next = table[i+1]; 
        while(temp != nullptr) 
        {
            node *extra = temp; // make an extra value for destructor to be able to to then delete 
            temp = temp->next; //set temp to temps next value 
            delete extra; // delete this extra value 
            
        } 
           // table[i] = NULL;
         // end if
    } // end for loop

    delete[] table; // delete the whole table 


}

void HashTable::displayTable() // display the whole table 
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "|";
        node *current = table[i];
        while (current != nullptr)
        {
            cout << current->restaurantName << "-->"; // add the arrow 
            current = current->next; // traverse through 
        }
        cout << "NULL" << endl;
    }

}

unsigned int HashTable::hashFunction(string restaurantName) 
{
    unsigned int hashValue = 0;
    for (int i = 0; i < restaurantName.length(); i++) // runs through the length of the name of restaurant 
    {
        char letter = restaurantName[i]; 
        hashValue += letter; // add up all of the ascii values 
    }
    unsigned int index = hashValue % tableSize; // mod by table size to find the value 
    return index;


}

node* HashTable::searchItem(string restaurantName)
{
    int i; 
    i = hashFunction(restaurantName); // call the hash function to find where the restaurant is located 
    node *current = table[i]; // make a current value for that table 
    while(current != nullptr)
    {
        
        if (current->restaurantName == restaurantName) // check if they are the same name and return, if not continue to traverse  
        {
            return current; 
        }
        current = current->next; 
    }
   
    return nullptr;

}

void HashTable::insertItem(ReviewInfo restaurant)
{
    int iInsert; 
    iInsert = hashFunction(restaurant.restaurantName);
    //currentInsert->restaurantName = iInsert; 
    //currentInsert->next = NULL; 
    node *temp = searchItem(restaurant.restaurantName); 
    if(temp == nullptr)
    {
       
        node *head = table[iInsert]; // make a head value to run through the table 
        node *currentInsert; // current node to insert 
        currentInsert = createNode(restaurant.restaurantName, head); // create the node 
        currentInsert->pq.insertElement(restaurant);  // insert the element 
        if(head == nullptr)
        {
            table[iInsert] = currentInsert; // insert the node into location in the table 
        }
        else 
        {
            numCollision++; // add number of collisions 
            table[iInsert] = currentInsert; // insert it in 
        }
       
      
    }
    else 
    {
        // insert into the pq 
        temp->pq.insertElement(restaurant); 

    }
}

    
    // else 
    // {
    //     node *temp = table[iInsert]; 
    //     while(temp!=nullptr)
    //     {
    //         if(temp->restaurantName == restaurant.restaurantName)
    //         {
    //             return; // duplicate 
    //         }
    //         temp = temp->next; 
    //         temp = table[iInsert]; 
    //     }
    //     while(temp != nullptr && currentInsert->restaurantName > temp->restaurantName)
    //     {
    //         temp = temp->next; 
    //         currentInsert->next = temp; 
    //     }
    // }






void HashTable::setup(string fname) //set up and file run through 
{

    ifstream file;
    file.open(fname); 
    string line; 
    string time; 
    while(getline(file,line))
    {
        ReviewInfo newReview;
        stringstream ss(line); 
        getline(ss, newReview.restaurantName,';'); 
        cout << newReview.restaurantName << endl;
        getline(ss, newReview.review,';'); 
        getline(ss, newReview.customer,';'); 
        getline(ss,time,';');
        cout << newReview.customer << endl;
        newReview.time = stoi(time); 
        insertItem(newReview);  // inset the item into the hash tablec
        //cout << "hi" << endl; 

    }
   

}