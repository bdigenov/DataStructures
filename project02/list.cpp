// list.cpp

#include "lsort.h"

#include <memory>

// Constructor
List::List() {
    head = 0;
}

// Destructor
List::~List() {
    Node* current = head;
    while( current != 0 ) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
}

// Push_front inserts a new struct Node to the front of the list
void List::push_front(const std::string &s) {
    Node* temp = new Node;
    temp->number = std::stoi(s);
    temp->string = s;
    temp->next = head;
    head = temp;
}


// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
