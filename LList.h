#pragma once
//------------------------------------------
//              class LList
//------------------------------------------
// A dynamic, unique-key, history-keeping, 
// singly Linked List
//------------------------------------------
#include "node.h"

class LList {
public:
	LList();
	~LList();
	void print();
	void insert(int k, string d);
	bool drop(int k);
	void findNode(int srchkey);
	void sort();
	
	
private:
	node * head; // pointer to the first node on the list
	node * search(int srchKey); // searches and returns a node given a key
	node * getb4(node * r); // gets the node before the given node
	node * max();// returns the node with max key
	bool remove(node * r); // removes the node given if found
};
