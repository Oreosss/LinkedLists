//-----------------------------------------------------------
//						CS 215 – Fall 2019
//							Project 4
//-----------------------------------------------------------
// Author: <OREOLUWA OLUKOTUN>
// Section: <003>
// Description: Linked List
// Assistance: I received help from the following:
// Eli Rice – He helped with some of the functions
//-----------------------------------------------------------




#include <iostream>
#include "LList.h"

//----------------------------------------------------
//				constructor & destructor
//----------------------------------------------------
// FINISH THESE!
LList::LList() {  

	head = NULL;
	cout << "LList: constructed!\n";
}

LList::~LList() { 
	//node * p = head;// assigning first item in the list to variable p
	//node* nextDel = p -> next; // pointer to next node object


	if (head != NULL) { // if the next item is not empty
		delete head; // deletes object that is pointed to by next 
		head = NULL; // assigns the item pointed to after the next
	}

	 // deletes the first item (head) if it doesnt have any next items 

	cout << "LList: destructed!\n";
}

//----------------------------------------------------
//				         search
//----------------------------------------------------
// Given: key to search for
// Returns: pointer to a node in the list found to have
//          the given search key, or NULL for not found
//----------------------------------------------------
node * LList::search(int srchKey) {
	node * p = head; // assigns first item on list to head
	while (p != NULL) { // while not end of list
		if (p->key == srchKey)  // if key is found return node
			return p;
		p = p->next;// moves to next node on the list
		
	}

	return NULL; // not found

} // search()

//----------------------------------------------------
//				   findNode
//----------------------------------------------------
// Given: a key to search for
// Searches for a node with the given key, and if 
// found, invokes the print() method in the found node.
// Otherwise, prints "not found"
//----------------------------------------------------
void LList::findNode(int srchkey) {
	node * p = NULL;
	p = search(srchkey); // invokes search function and assigns node found to variable p

	if (p != NULL) { // if found invoke print method
		p->print();
	}

	else { // otherwise prints not found
		cout << "not found" << endl;
	}

} // findNode()

//----------------------------------------------------
//				    getb4
//----------------------------------------------------
// Given: a pointer to a node in the list
// Returns: a pointer to the node in the list BEFORE
//               the one pointed to by r, OR
//          NULL when r is the head or not found in
//               the list
//----------------------------------------------------
node * LList::getb4(node * r) {
	node * b4 = NULL;
	node * p = head->next;
	node * prev = head ; // for previous 
	node * found = search(r->key);
	if (head == r) {
		
		b4 = NULL; // if head is the first item on the list OR if r is a null pointer return null OR if the node is not on the list
		
	}

	if (r == NULL) {
		
		b4 = NULL;
		
	}

	if (found == NULL) {
	
		b4 = NULL;
		
	}


	while (p != NULL) { // as long as not end of the list
		if (p == r) { // if r is found on the list, returns the pointer to the node that has R as its next which is prev
			b4 = prev;
				
		}         // returns the pointer to what is before r, that is the node that has Ras its next
		prev = p; // assigns current value to prev
		p = p->next; // moves to next item on the list 

	}

	
	return b4;
} // getb4()

//----------------------------------------------------
//				       insert
//----------------------------------------------------
// Given: key and data for a new node
// Allocates/populates a new node
// When a node with the same key already exists:
//     the current/old node is replaced by the new one
//     and the old one is placed on the new one's 
//     duplicate list (it's NEXT should be set to NULL,
//     since it is no longer "in the list")
// Otherwise, the new node is prepended to the head
//     of the list.
//----------------------------------------------------
void LList::insert(int k, string d) {
	
	node * newNode = new node;  // creates memory location for new node object
	newNode -> key = k;																 // assigns k as key to new node object
	newNode ->data = d;																// assigns d as data for new node object
	node * p = head;															   // assigns head to variable p
	if (p == NULL) {			// if head is empty mahes newNode list head
		head = newNode ;
		//cout << "here" << endl;
	}

	else {// if head is not empty 
		node * found ;
		node * prev;
		found = search(newNode->key); // searches to see if newNode key is already in list (that is if there is a duplicate)
		
		if (found == NULL) { // if not in list
			head = newNode;; // makes the item head of list (basically a STACK), stacking on top or prepending to the list
			head -> next = p;  // makes p which currently holds the former head the next object in list
			//cout << "here" << endl;
	
		}

		if ((found != NULL) && (found -> key == head -> key)) { // ensures found is not null to prevent program crasging & if the found item is the head
			head = newNode; // makes the new node head
			head->dup = p; // makes the old head (which has the same key as new node) a duplicate of newNode
			head->next = p->next; // connecting the new head to the rest of the list
			
			p->next = NULL; // disconnect the head from the rest of the list by making its next pointer null

		}
		
		if (((found != NULL) && (found -> key != head -> key))) { // if the found item has a duplicate that is not  the head
			prev = getb4(found); // getting the before of whats found because thats the node thats already in the list
			//prev->print();
			if (prev != NULL) {
				// gets the node before the duplicate of new node
				node * temp = found; // creating a temporary variable for the found node so it can be NULLed out at the end
				newNode->dup = temp; // assigning the node thats found in the list as a dulicate of the newnode
				newNode->next = temp->next;// connects newNode to the restof the list by assigning the found variable's next to newNode's next(connecting it to its successor)
				 prev->next = newNode; // connecting newnode to its predecessorand joining it to the list
				 temp = NULL;//disconnecting the old node from the list and clearinfg it out
			}
		}
	}
		
} // insert()

//----------------------------------------------------
//				       remove
//----------------------------------------------------
// Given: a pointer to a node in the list to be removed
//        BUT NOT DELETED/DESTROYED
// Returns: TRUE - when the node was successfully removed
//          FALSE - when the given node is NULL or the node
//                  is not actually in the list.
// Simply removes the node from the linked list.
// (including setting the NEXT pointer in the node to NULL)
//----------------------------------------------------
bool LList::remove(node * r) {
	//node * rem = r; // pointer to node that is to be removed
	//bool removed = false;
	node * found = search(r->key);


	if (r == NULL) {// if the given pointer is null return false
		return false;
	}
	if (found == NULL) {// if the given pointer is not found on the list return false
		return false;
	}
	if (head == NULL) {
		return NULL;
	}

	if (r == head) {
		head = head->next;
		return true;
	}
	else {
		if (found != NULL) {
			node * prev = getb4(r);
			prev->next = r->next;
			r->next = NULL;
			//r->dup = NULL;
			return true;
				
		}
		

		
	}
		

	
} // remove()

//----------------------------------------------------
//				       drop
//----------------------------------------------------
// Given: key of a node to drop
// Returns: TRUE when a node was found and deleted
//          FALSE when a node with the given key not found,
//                or the remove() fails.
// Searches for a node in the list with the given key:
// When found, removes and deletes the node
//----------------------------------------------------
bool LList::drop(int k) {
	node * p = search(k); // assigns the found node to node p
	
	if (p == NULL) {
		return false;
	}
	else {
		if (remove(p) == true) {
			delete p; // delete deallocate the node
			p = NULL;
			return true;// sucessfully deallocated it
		}
		else
			return false;
	}
	//return false;
} // drop()

//----------------------------------------------------
//				        max
//----------------------------------------------------
// Returns: a pointer to the node with the highest key
//          or NULL when there list is empty.
node * LList::max() {

	node * max = head; // make the current head the max
	node * p = head->next; // the variable for comparison , also helps to move to next node on the list

	while (p != NULL) {// as long as the next pointer is not empty

		if (p->key > max->key) { // if the current node is greater than the current max node
			max = p; // make the cyrrent node the max
			//return max;
		}
		p = p->next;// move on to next node 
	}

	return max;// returns the max element
} // max()

//----------------------------------------------------
//				       sort
//----------------------------------------------------
// Sorts the list in ascending order by key values
void LList::sort() {

	
	LList temp; // create temp LLIST
	node * m = head; // initialize max as head
	 
	
	
	while (head != NULL) { // while the list is not empty
		m = max(); // get the max and assign to m
		node * d = m->dup; // node to store dups of found m
		remove(m);// remove m from the old list 
		temp.insert(m->key, m->data);// insert the node m into the new temp list

		while (d){ // while the duplicate node is not null
			temp.insert(d->key,d->data); // inserts the duplicates key and data to the list
			d = d->dup; // moving on to the next duplicate
		}
	}

	head = temp.head;// assigns the new list to the old list
	temp.head = NULL;// clears out the temporary list

} // sort()

  //----------------------------------------------------
  //				    print
  //----------------------------------------------------
  // prints each node in the list, or EMPTY when there
  // are no nodes to print
  //----------------------------------------------------
void LList::print() {
	if (head == NULL)
		cout << "EMPTY\n\n";
	else {
		node * p;
		p = head;
		while (p != NULL) {
			p->print();
			p = p->next;
		}
		cout << endl;
	}
} // print()