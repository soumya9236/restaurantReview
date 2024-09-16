#include <iostream>
#include "hash.hpp"
#include "PriorityQueue.hpp"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void displayMenu() // do not modify
{
    cout << "------------------" << endl;
    cout << "1: Build the data structure (execute this option one time)" << endl;
    cout << "2: Add a review" << endl;
    cout << "3: Retrieve most recent review for a restaurant" << endl;
    cout << "4: Pop most recent review for a restaurant" << endl;
    cout << "5: Print reviews for a restaurant" << endl;
    cout << "6: Display number of collisions" << endl;
    cout << "7: Display table results" << endl;
    cout << "8: Exit" << endl;
    cout << "------------------" << endl;
}

int main(int argc, char* argv[])
{
    
    if (argc <3)
    {
        cout<<"need correct number of arguments"<<endl;
    }
	
    string fname = argv[1];
    int tableSize = stoi(argv[2]);
    int ch = 0; 
    string chs; 
    HashTable ht(5); 
    bool ran = false; 
    while(ch!=8)
    {
        displayMenu();
        cout << "Enter your choice >>";
        getline(cin, chs);
        ch = stoi(chs);
        //bool ran = false; 
        switch (ch)
        {
            case 1:// BUILD STRUCTURE
			{

				//FINISH THIS 
                if(ran == false)
                {
                    ht.setup(fname); 
                    cout << "data structure is built" << endl; 
                    ran = true; 
				    break;

                }
                else
                {
                    cout << "The data structure has already been built." << endl; 
                }
                break; 
              
            }
            case 2: // ADD REVIEW 
			{
                string name2; 
                string customer2; 
                string review2; 
                int time2; 
                string timeString; 

                cout << "Restaurant name: " ; 
                getline(cin, name2);
                //cout << endl; 

                cout << "Customer: "; 
                getline(cin, customer2);
                //cout << endl; 

                cout << "Review: "; 
                getline(cin, review2);
                //cout << endl; 

                cout << "Time: "; 
                getline(cin,timeString);  
                //cout << endl; 
                // add in if time is greater than 2400

                time2 = stoi(timeString); 
                ReviewInfo addingNewReview{name2, customer2, review2, time2}; 
                ht.insertItem(addingNewReview); 
                
                
				break;
            }
            case 3: // RETRIEVE MOST RECENT REVIEW 
			{
                cout << "Restaurant name: " ; 
                string name1; 
                getline(cin, name1); 
                //ht.searchItem(name1); 
                node *loc = ht.searchItem(name1); // have to make a new node to call priority queue functions 
                if(loc->restaurantName == name1)
                {
                    loc->pq.peek(); 
                    // call peek function 
                    //ht->pq; 
                   //ht.
                    
                }
                else 
                {
                    cout << "no record found" << endl; 

                }
                //
				break;
            }
            case 4: // POP 
			{
                // FINISH THIS 
                cout << "Restaurant name: " ; 
                string name; 
                getline(cin, name); 
                //ht.searchItem(name); 
                cout << endl; 
                //bool found = false; 
                node *loc = ht.searchItem(name); // have to make a new 
                if(loc->restaurantName == name)
                {
                    //cout << "retrieved result: "; 
                    loc->pq.pop(); 
                    //cout << endl; 
                    //cout << 
                    // add current size stuff 
                    // pop function 
                    
                }
                else 
                {
                    cout << "retrieved result: " << endl; 
                    cout << "no record found" << endl; 
                }
            
				break;
            }
            case 5: // PRINT REVIEWS 
			{
				//
                string restaurants;
                cout << "Restaurant Name:";
                //cin.ignore();
                getline(cin, restaurants);

                node *restaurantNode = ht.searchItem(restaurants);
                if(restaurantNode != nullptr)
                {
                    //cout << "Restaurant: " << restaurantName << endl;
                    restaurantNode->pq.print(); // accesing the priority queue with the restaurant in restaurantNode which is the input value 
                }
                else 
                {
                    cout << "no record found" << endl;
                } 
              
				break;
			}
            case 6: // COLLISIONS 
                //
                cout << "Number of collisions:" << ht.getNumCollision() << endl; 
                break;
            case 7: // DISPLAY TABLE RESULTS 
                //
                ht.displayTable(); 
                break;
            case 8: // HELLA LEAVE 
                
				break;

            default:
                cout << "Enter a valid option." << endl;
                break;
        }
    }
}
