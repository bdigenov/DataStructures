// treap.cpp: Treap Map

#include "map.h"

#include <climits>
#include <random>
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


// Prototypes ------------------------------------------------------------------

static Node *insert_r(Node *node, const std::string &key, const std::string &value);
//extern Node *search_r(Node *node, const std::string &key);
static Node *search_r(Node *node, const std::string &key);
extern void    dump_r(Node *node, std::ostream &os, DumpFlag flag);
static Node *rotate_right(Node *p);
static Node *rotate_left(Node *p);
static int get_random();
static void delete_tree(Node* n);

// Methods ---------------------------------------------------------------------
TreapMap::~TreapMap() {
      //cout << "IN DECONSTRUCTOR" << endl;
      delete_tree(root);
}

void            TreapMap::insert(const std::string &key, const std::string &value) {
                //cout << "IN INSERT FUNCTION FOR KEY: " << key << " AND VALUE " << value << endl;
                
                //If the key is already in the treap update the value 
                if (search(key) != NONE) {
                    Node* node = search_r(root,key);
                    node->entry.second = value;
                }
                
                //If it is a new key, place it in the treap 
                else {
                    this->root = insert_r(root,key,value);                   
                }
}

const Entry     TreapMap::search(const std::string &key) {
     //cout << "IN SEARCH FUNCTION" << endl;
    //Check to see if the tree is empty
    if (root == nullptr) return NONE;
    
    else {
        if (search_r(root,key) != nullptr){
            Node* n = search_r(root,key);
            return n->entry;
        }
        
        else return NONE;
    }
    
    return NONE;
}

void            TreapMap::dump(std::ostream &os, DumpFlag flag) {
	dump_r(root, os, flag);
}

// Internal Functions ----------------------------------------------------------

void delete_tree(Node* n) {
      //cout << "IN DELETE TREE FUNCTION" << endl;
    //Recursively delete left half of tree 
    if (n->left) {
        delete_tree(n->left);
    }
    if (n->right) {
        delete_tree(n->right);
    }
    
    delete n;
}

//The implementation for this will eventually be in the BST file 
Node *search_r(Node *node, const std::string &key) {
      //cout << "IN SEARCH_R" << endl;
    //If treap is empty or end of treap return that there are no matches or if it is a match 
    if (node == nullptr || node->entry.first==key) {
        return node;
    }
    
    //If key is less than the value of present node continue down left of treap 
    if (key <= node->entry.first) {
        return search_r(node->left, key);
    }
    
    //If key is greater than the value of present node continue down right of treap 
    else {
        return search_r(node->right, key);
    }
}

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
      //cout << "IN INSERT_R" << endl;
     Node* n = new Node();
     
    //if the root is null then make the root the new node 
    if (node == nullptr) {
        n->entry.first = key;
        n->entry.second = value;
        n->right = nullptr;
        n->left = nullptr;
        n->priority = get_random();
        return n;
    }
    
    if (key <= node->entry.first) {
        
        //Recursively insert down left side of tree 
        node->left = insert_r(node->left,key, value);
        
        //perform rotations for treap max heap
        if (node->left->priority > node->priority) {
            node = rotate_right(node);
        }
    }  
     
    else {
        //Recursively insert down right side of tree 
        node->right = insert_r(node->right,key, value);
        
        //perform rotations for treap max heap
        if (node->right->priority > node->priority) {
            node = rotate_left(node);
        }
    }
    
    return node;
}

Node *rotate_right(Node *p) {
    //cout << "IN ROTATE RIGHT" << endl;
    Node* c = p->left;
    Node* T2 = c->right;
    
    c->right = p;
    p->left = T2;
    
    return c;
}

Node *rotate_left(Node *p) {
    //cout << "IN ROTATE LEFT" << endl;
    Node* c = p->right;
    Node* T2 = c->left;
    
    c->left = p;
    p->right = T2;
    
    return c;
}

int get_random() {
    int max = 100;
    random_device               rd;
    default_random_engine       g(rd());
    uniform_int_distribution<>  d(1, max);
    return d(g);
}