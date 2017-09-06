// stl.cpp
// stl sort will use c++ style comparison function

#include "lsort.h"
#include <cstring>
#include <string>
#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
void stl_sort(List &l, bool numeric) {
    // Copy struct Nodes in struct List into vector
    Node* current = l.head; // find the beginning
    std::vector<Node*> arrayOfData; // initialize a vector of Node pointers
    arrayOfData.push_back(current);
    while (current->next != nullptr){ // loop through the list until we reach the end
        arrayOfData.push_back(current); // push back the current data
        current = current->next; // move the current pointer to continue iterating through the list
    }
    int sizeOfVector = arrayOfData.size(); // total number of elements
    // Start from head
    // Node* current = l.head;
    // Call the sort function
    if (numeric){
        sort(arrayOfData.begin(), arrayOfData.end(), node_number_compare); // Call number compare since data is numeric
    }
    else{
        sort(arrayOfData.begin(), arrayOfData.end(), node_string_compare); // Call string compare since data is strings
    }
    // Update the links between struct Nodes to reflect the sorted order
    // ~List(); // Clear the linked list to prepare for the update
    // delete &l;
    
    /* New Solution */
    Node * newHead = arrayOfData.at(sizeOfVector-1);  // Store the new head
    // cout << "newHead number " << newHead->number << endl;
    newHead->next = arrayOfData.at(sizeOfVector-2);   // Store the new head next pointer
    l.head = newHead; // Update the list with the new head
    
    int i = sizeOfVector-2; // current number of elements processed
    while (i > 0){
        if (i == 1){ // At the last element
            Node * temp = arrayOfData.at(i); // Get the node of the last element
            temp->next = nullptr; // Set its address to null
        }
        else {
            Node * temp = arrayOfData.at(i); // Create a temp Node that is the current value of the array being processed
            // cout << temp->number << endl;
            temp->next = arrayOfData.at(i-1); // Set the temp Node's next to the current value + 1
        }
        i--; // Increase the current number of elements processed
    }
    /* End New Solution */
    
    
    
    /*
    while (i < sizeOfVector){
        Node* current = arrayOfData.at(i); // Set the current node of the vector to process
        if (numeric){
            int elementInt = current->number;
            string element = to_string(elementInt);
            if (i + 1 == sizeOfVector){ // Have reached the tail
                current->next = nullptr; // Set the next pointer of the last element to be null
                l.push_front(element); // Push the last element to the updated linked list
            }
            else { // Still have not reached the tail
                current->next = arrayOfData.at(i+1); // Set the next pointer of the current node being processed to the next node in the vector
                l.push_front(element); // Push this current element to the updated linked list
            }
        }
        else{
            string element = current->string;
            if (i + 1 == sizeOfVector){ // Have reached the tail
                current->next = nullptr; // Set the next pointer of the last element to be null
                l.push_front(element); // Push the last element to the updated linked list
            }
            else { // Still have not reached the tail
                current->next = arrayOfData.at(i+1); // Set the next pointer of the current node being processed to the next node in the vector
                l.push_front(element); // Push this current element to the updated linked list
            }
        }
        
        i++; // Increase number of elements processed so far
    }
     */
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
