#pragma once
//------------------------------------------
//              class node
//------------------------------------------
// Describes a node in a unique-key, history-
// keeping Linked List
//------------------------------------------
#include <string>
using namespace std;

class node {
	friend class LList;
public:
	~node(); // destructor
	node();// constructor
	node(int k, string d); // creates a node. given key & data
	void print();
private:
	int key;		// key to the node
	string data;	// data of the node
	node * next;	// pointer to next node in list
	node * dup;		// pointer to a stack of nodes with
	                // former (old) values for this key
};
