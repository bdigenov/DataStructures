// merge.cpp

#include "lsort.h"
#include <iostream>

using namespace std;


// Prototypes
Node *msort(Node *head, CompareFunction compare);
void  split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, CompareFunction compare);

// Implementations

//Calls the recursive msort with the proper comparison function for either strings or ints
void merge_sort(List &l, bool numeric) {
	if(numeric){
		l.head = msort(l.head, node_number_compare);
	}
	
	else {
		l.head = msort(l.head, node_string_compare);
	}
}

//Recursive merge sort function 
Node *msort(Node *head, CompareFunction compare) {
	
	//Nodes that become the heads of the two new sides
	Node* left;
	Node* right;
	
	//Split the list in half
	split(head, left, right);
	
	//If the list can still be split call msort again
	if (left->next != nullptr) {
		left = msort(left, compare);			
	}
	
	if (right->next != nullptr){
		right = msort(right, compare);
	}
	
	//Jump back out of recursive layers calling merge function to bring list back together
	head = merge(left, right, compare);
	
	return head;
}

void split(Node *head, Node *&left, Node *&right) {
	Node* quick_traverse_pointer;
	Node* slow_traverse_pointer;
	
	//Deal with empty or size of one list 
	if (head == nullptr || head->next == nullptr) {
		left = head;
		right = nullptr;
	}
	
	//Otherwise traverse with a doubly iterating pointer and singly iterating pointer
	else {
		slow_traverse_pointer = head;
		quick_traverse_pointer = head->next;
		
		while ( quick_traverse_pointer != nullptr) {
			quick_traverse_pointer = quick_traverse_pointer->next;
			
			//Once the quick traverse pointer reaches the end the slow one will be half way
			if (quick_traverse_pointer != nullptr ) {
				slow_traverse_pointer = slow_traverse_pointer->next;
				quick_traverse_pointer = quick_traverse_pointer->next;
			}
		}
		
		//Once quick is at the end set the beginning of left side to head and beginning of right side
		//to the mid point (which is where the slow pointer ended up)
		left = head;
		right = slow_traverse_pointer->next;
		slow_traverse_pointer->next = nullptr;
	}
}

//This function will compare the values at the front of each half list and place the smaller value in the final list
Node *merge(Node *left, Node *right, CompareFunction compare) {
	Node* return_node;
	
	if (left == nullptr) return right;
	else if (right == nullptr) return left;
	
	//The compare function will return true if the first value is > than the second 
	if (compare(left, right)) {
		return_node = right;
		return_node->next = merge(left, right->next, compare);
	}
	
	else {
		//Set the return_node to the furthest left (so that the head of the sorted list is the furthest left in the end)
		return_node = left;
		return_node->next = merge(left->next, right, compare);
	}
	
	return(return_node);

}

