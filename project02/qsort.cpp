// qsort.cpp
// Qsort is a c function
// Will use C style comparison function

#include "lsort.h"
#include <cstring>
#include <string>
#include <cstdlib>
#include <array>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
void qsort_sort(List &l, bool numeric) {
    // Copy struct Nodes in struct List into vector
    Node* current = l.head; // find the beginning
    std::vector<Node*> arrayOfData; // initialize a vector of Node pointers
    while (current->next != nullptr){ // loop through the list until we reach the end
        arrayOfData.push_back(current); // push back the current data
        current = current->next; // move the current pointer to continue iterating through the list
    }
    int sizeOfVector = arrayOfData.size(); // total number of elements
    // Start from head
    Node* element = l.head;
    // Call the sort function
    if (numeric){
        qsort(&arrayOfData[0], sizeOfVector, sizeof(element->number), void_number_compare); // Call number compare since data is numeric
    }
    else{
        qsort(&arrayOfData[0], sizeOfVector, sizeof(element->string), void_string_compare); // Call string compare since data is strings
    }
    // Update the links between struct Nodes to reflect the sorted order
    // ~List(); // Clear the linked list to prepare for the update
    delete &l;
    
    int i = 0; // current number of elements processed
    
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
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
