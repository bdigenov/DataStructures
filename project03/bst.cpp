// bst.cpp: BST Map

#include "map.h"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

// Prototypes ------------------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value);
Node *search_r(Node *node, const std::string &key);
void    dump_r(Node *node, std::ostream &os, DumpFlag flag);

// Methods ---------------------------------------------------------------------

void            BSTMap::insert(const std::string &key, const std::string &value) {
		
	if(search(key) != NONE){
		Node *n = search_r(root, key);
		n->entry.second = value;
	} else {
		this->root = insert_r(root, key, value);
	}
	
	
}

const Entry     BSTMap::search(const std::string &key) {
	if(root == nullptr){
		return NONE;
	
	} else {
		Node* n = search_r(root, key);
		if(n != nullptr){
			return n->entry;
		} else {
			return NONE;
		}
	}
}

void            BSTMap::dump(std::ostream &os, DumpFlag flag) {
	dump_r(root, os, flag);
}

// Internal Functions ----------------------------------------------------------

Node *insert_r(Node *node, const std::string &key, const std::string &value) {
	
	std::pair <std::string, std::string> entry (key, value);
	if(node == nullptr){
		Node* n = new Node { entry, 0, nullptr, nullptr };
		return n;
	}
	if(key <= node->entry.first){
		node->left = insert_r(node->left, key, value);
	} else {
		node->right = insert_r(node->right, key, value);
	}
	
    return node;
}

Node *search_r(Node *node, const std::string &key) {
	Node* ans = nullptr;
	
	if(node == nullptr){
		return nullptr;
	}
	
	if(key == node->entry.first){
		return node;
	} else if (key < node->entry.first){
		ans = search_r(node->left, key);
	} else {
		ans = search_r(node->right, key);
	}
	
    return ans;
}

void dump_r(Node *node, std::ostream &os, DumpFlag flag) {
	
	if(node == nullptr){
		return;
	}
	
	dump_r(node->left, os, flag);
	
	
	switch(flag){
		case DUMP_KEY:
			os << node->entry.first << endl;
			break;
		case DUMP_VALUE:
			os << node->entry.second << endl;
			break;
		case DUMP_KEY_VALUE:
			os << node->entry.first << " : " << node->entry.second << endl;
			break;
		case DUMP_VALUE_KEY:
			os << node->entry.second << " : " << node->entry.first << endl;
			break;
	}	
	
	
	dump_r(node->right, os, flag);
	
	
	
}

// vim: set sts=4 sw=4 ts=8 expandtab ft=cpp:
