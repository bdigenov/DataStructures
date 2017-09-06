// node.cpp

#include "lsort.h"
#include <iostream>
#include <cstring>

using namespace std;


/*----C++ Style---*/
bool node_number_compare(const Node *a, const Node *b) {
	if (a->number > b->number) return true;
	return false;
}

bool node_string_compare(const Node *a, const Node *b) {
	
	int lengtha, lengthb,minlength;
	
	lengtha = a->string.length();
	lengthb = b->string.length();
	minlength = lengtha;
	if (lengthb < minlength) minlength = lengthb;
	
	for (int i = 0; i < minlength; i++ ) {

		if (a->string[i] > b->string[i]) {
			return true;
		}
		if (b->string[i] > a->string[i]) {
			return false;
		}
	}
    
    //If the for loop never broke, check to see which number is larger 
    if (lengtha > lengthb ) {
        return true
    }
    
	return false;
}


/*------------------------C Style-----------------------*/
/*--------------------Number Compare--------------------*/
// The return value is an int.  When it's:
// * negative   -- a's value is less than b's value
// * positive   -- a's value is greater than b's value
// * =0         -- a's value is equal to b's value
// int void_number_compare will return with numbers is ascending order
int void_number_compare(const void *a, const void *b) {
    Node nodeA = *((Node*)(a));
    Node nodeB = *((Node*)(b));
    int intA = nodeA.number;
    int intB = nodeB.number;
    return intA  - intB;
}

/*--------------------String Compare--------------------*/
// int void_string_compare will return with strings in ascending length
int void_string_compare(const void *a, const void *b) {
    Node nodeA = *((Node*)(a));
    Node nodeB = *((Node*)(b));
    string stringA = nodeA.string;
    string stringB = nodeB.string;
    int lengthA, lengthB;
    lengthA = stringA.length();
    lengthB = stringB.length();
    return lengthA - lengthB;
}

void dump_node(Node *n) {
    while(n!=NULL)
    {
        cout << n->number << endl;
        cout << n->string << endl;
        // printf("%d",n->number);
        // printf("%s",n->string);
        n=n->next;
    }
}


