// quick.cpp

#include "lsort.h"

#include <iostream>

using namespace std;
// Prototypes

Node *qsort(Node *head, CompareFunction compare);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
	if(numeric){
		l.head = qsort(l.head, node_number_compare);
	} else {
		l.head = qsort(l.head, node_string_compare);
	}
}

Node *qsort(Node *head, CompareFunction compare) {
	Node* left;
	Node* right;
	
	partition(head, head, left, right, compare);
	if(left->next != nullptr){
		left = qsort(left, compare);
	}
	if(right != nullptr){
		if(right->next != nullptr){
			right = qsort(right, compare);
		}
	}
	
	head = concatenate(left, right);
	
	return head;
	
}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, CompareFunction compare) {
	
	if(head->next != nullptr){
		Node *curr = head->next;
		
		Node* lefthead = nullptr;
		Node* lcurr = nullptr;
		Node* lfollow = nullptr;
		Node* righthead = nullptr;
		Node* rcurr = nullptr;
		Node* rfollow = nullptr;
		 
		
		while(curr != nullptr){
			if(compare(pivot, curr)){
				if(lefthead == nullptr){
					lefthead = curr;
					curr = curr->next;
					lefthead->next = nullptr;
				} else {
					lcurr = lefthead;
					lfollow = nullptr;
					while(lcurr != nullptr){
						lfollow = lcurr;
						lcurr = lcurr->next;
					}
					lfollow->next = curr;
					curr = curr->next;
					lfollow->next->next = nullptr;
				}
			} else {
				if(righthead == nullptr){
					righthead = curr;
					curr = curr->next;
					righthead->next = nullptr;
				} else {
					rcurr = righthead;
					rfollow = nullptr;
					while(rcurr != nullptr){
						rfollow = rcurr;
						rcurr = rcurr->next;
					}
					rfollow->next = curr;
					curr = curr->next;
					rfollow->next->next = nullptr;
				}
			}
		}
		if(lefthead == nullptr){
			lefthead = pivot;
			lefthead->next = nullptr;
		} else {
			lcurr = lefthead;
			lfollow = nullptr;
			while(lcurr != nullptr){
				lfollow = lcurr;
				lcurr = lcurr->next;
			}
			lfollow->next = pivot;
			lfollow->next->next = nullptr;
		}		
		left = lefthead;
		right = righthead;
	} else {
		left = head;
		right = nullptr;
	}	
	
}

Node *concatenate(Node *left, Node *right) {
	
	
	Node *curr = left;
	Node *follow;
	while(curr != nullptr){
		follow = curr;
		curr = curr->next;
	}
	follow->next = right;

	
	
	return left;
	
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
