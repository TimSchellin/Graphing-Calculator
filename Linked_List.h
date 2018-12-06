
#ifndef LinkedList_H
#define LinkedList_H

#include <iostream>
#include <cassert>
#include <stdio.h>

using namespace std;
template <typename T>
//node is a 2-part struct, consisting of item and node pointer
struct node {
	T _item;
	node<T>* _next;

	//constructor

	node(const T& item = T(), node<T> *next = nullptr) {
		_item = item;
		_next = next;
	}

};

//IMPLEMENTED

template<typename T>
//insert_head takes in the address of head_ptr and item to populate the new head node
//and returns the address of the new head_ptr
node<T>* insert_head(node<T>* &head_ptr, const T& item) {
	//1. create a new node
	//2. next points to the head_ptr
	//3. point head_ptr to where temp is pointing to
	//4. return head_ptr

	//cout << "headptr location: " << head_ptr << endl;;
	node<T>* new_node = new node<T>(item);
	//cout << "new node location: " << new_node << endl;
	new_node->_next = head_ptr;
	//cout << "new_node->next location: " << new_node->_next << endl;
	head_ptr = new_node;
	//cout << "headptr location after reassignment: " << head_ptr << endl;
	return head_ptr;

}

//IMPLEMENTED

template<typename T>

node<T>* insert_after(node<T>* head_ptr, node<T>* mark, const T& item) {
	//    node<T>* new_node = new node<T>(item);
	//    new_node->_next = mark->_next;
	//    mark->_next = new_node;
	node<T>* new_node = new node<T>(item);
	new_node->_next = mark->_next;
	mark->_next = new_node;
	return new_node;

	//cout << "mark_item: " << mark->_item << endl;
	//cout << "mark location: " << mark << endl;
	//cout << "mark->next location: " << mark->_next << endl;
	//return insert_head(mark->_next, item);
}

//IMPLEMENTED

template<typename T>
//insert_before takes in the address of the mark, and create a new node before the
//mark and populate the new node with item and returns the address of the new node ptr
node<T>* insert_before(node<T>* head_ptr, node<T>* mark, const T& item) {
	//1. create a NEW node named new_node, populated with item
	//2. get a walker to traverse down the linked list to node where the _next points to mark
	//3. the node whose _next pointed to mark now points to new_node
	//5. new_node's _next points to mark
	//6. return insert_ptr
	node<T>* new_node = new node<T>(item);

	node<T>* walker = head_ptr;

	while (walker != nullptr) { //don't fall off!
		if (walker->_next == mark) {
			// walker is pointing to the node before the mark
			walker->_next = new_node;
			//walker -> next = new node<T>(item);
			new_node->_next = mark;
			return new_node;
		}

		walker = walker->_next;
	}
	//if you get here, that mean you never found mark:
	//  mark was not even on this list.
	assert(false);
	return new_node;

}

//Not yet tested

template <typename T>
//find the pointer to the previous node of prevToThis
node<T>* PreviousNode(node<T>* head_ptr, node<T>* prevToThis) {
	node<T>* walker = head_ptr;
	while (walker != nullptr) {
		if (walker->_next == prevToThis) {
			return walker;
		}
		walker = walker->_next;
	}
	return nullptr;
}

//IMPLEMENTED

template<typename T>
//get a walker and traverse down the linked list and print out the items in the list
void print_list(node<T>* head_ptr) {
	//1. get a walker
	//2. keep walking down linked list as long as walker != nullptr
	//3. output
	node<T>* walker = head_ptr;
	//    Term t(0, 0);
	while (walker != nullptr) {
		//only print if walker item is not a 0X^0 term
		if (walker->_next != nullptr) {
			cout << " [" << walker->_item << "] +";
		}
		else {
			cout << " [" << walker->_item << "]";
		}

		//traverse the walker down. New syntax!
		walker = walker->_next;
	}
	//    cout << "|||" << endl;
}

//IMPLEMENTED

template <typename T>
//duplicate the list...
node<T>* copy_list(node<T>* head_ptr) {

	if (head_ptr->_next == nullptr) {
		return head_ptr;
	}

	node<T>* new_node = new node<T>(head_ptr->_item);
	node<T>* og_list_walker = head_ptr->_next;
	node<T>* new_list_walker = new_node;

	while (og_list_walker != nullptr) {
		insert_after(new_node, new_list_walker, og_list_walker->_item); //head_ptr, item
		og_list_walker = og_list_walker->_next;
		new_list_walker = new_list_walker->_next;
	}

	return new_node;
}

//NOT YET IMPLEMENTED

//template<typename T>
////recursive?
//void print_list_backward(node<T>* head_ptr) {
//
//}

//IMPLEMENTED

template<typename T>
T delete_head(node<T>*& head_ptr) {

	//0. assert that the list is not empty
	//1. get a temp node_ptr to point to the head node
	//2. get a T variable to store item in head node
	//3. get head_ptr to skip the head node and point to the node after it
	//4. delete temp, which points to the head node

	assert(head_ptr != nullptr);
	T hold_this = head_ptr->_item;
	node<T>* temp = head_ptr;
	head_ptr = head_ptr->_next;
	delete temp; //this is where the exception is thrown

	return hold_this;
}


//IMPLEMENTED

template<typename T>
//delete the node from linked list and return the item in node
T delete_node(node<T>* head_ptr, node<T>* mark) {
	//1. get a walker to traverse down the linked list & find mark
	//2. when node._next == mark is found:
	//3. store the item in temp T
	//4. walker._next = mark._next
	//5. no need of garbage collection?

	assert(head_ptr != nullptr);

	//implemented for the stack & queue lab
	T temp_item;
	node<T>* walker = head_ptr;

	//    if (head_ptr->_item == mark->_item) {
	//        temp_item = mark->_item;
	//        //delete
	//        delete_head(mark);
	//        //return
	//        return temp_item;
	//    }

	while (walker != nullptr) {
		if (walker->_next == mark) {
			node<T>* temp = mark;
			temp_item = mark->_item;
			walker->_next = mark->_next;
			delete temp; ////
			return temp_item;
		}
		walker = walker->_next;
	}

	return 0;
}

//IMPLEMENTED

template<typename T>
//find an item in linked list. Return the address of the node where item is found -- ALSO CALLED searchList
node<T>* search_list(node<T>* head_ptr, const T& item) {
	//1. get a walker to traverse down the linked list
	//2. if ._item == item, return the walker as it's on that node
	node<T>* walker = head_ptr;
	while (walker != nullptr) {
		if (walker->_item == item) {
			return walker;
		}
		walker = walker->_next;
	}
	//return nullptr if item is not found
	return nullptr;
}

//IMPLEMENTED

template<typename T>
//delete all node
void clear_list(node<T>*& head_ptr) {
	//    node<T>* walker = head_ptr;
	//cout << "CLEAR LIST CALLED";

	while (head_ptr != nullptr) {
		//cout << "headptr: " << head_ptr << endl;
		delete_head(head_ptr);
	}
}

//IMPLEMENTED

template<typename T>
//_item at this position
T& At(node<T>* head_ptr, int pos) {

	int count = 0;
	node<T>* walker = head_ptr;

	while (count != pos) {
		walker = walker->_next;
		count++;
	}
	return walker->_item;
}


//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//IMPLEMENTED

template <typename T>
node<T>* InsertSorted(node<T>* &head_ptr, T item, bool ascending = true) {

	node<T>* p = WhereThisGoes(head_ptr, item, ascending);
	if (p == nullptr) {
		return insert_head(head_ptr, item);

	}
	return insert_after(head_ptr, p, item);
}

template <typename T>
node<T>* InsertSorted_Unique(node<T>* &head_ptr, T item, bool ascending = true) {


	if (head_ptr == nullptr) {
		return insert_head(head_ptr, item);
	}

	node<T>* p = WhereThisGoes(head_ptr, item, ascending);

	// editing to get descending
	if (item > p->_item) {
		return insert_head(head_ptr, item);
	}
	else if (item == p->_item) {
		//call insert sorted and add
		////        item = item + p->_item;
		//        return nullptr;
		return InsertSorted_and_add(head_ptr, item, ascending);
	}

	return insert_after(head_ptr, p, item);
}

//Not yet implemented

template <typename T>
//when a duplicate is found, add the duplicate
node<T>* InsertSorted_and_add(node<T>* &head_ptr, T item, bool ascending = true) {
	//Call whereThisGoes to find the placement for item on list
	node<T>* p = WhereThisGoes(head_ptr, item, ascending);
	item = item + p->_item;
	return head_ptr;
}


//IMPLEMENTED

template <typename T>
//node after which this item goes //order: 0 ascending
//two pointers walk down the list and figure out where item goes
node<T>* WhereThisGoes(node<T>* head_ptr, T item, bool ascending = true) {
	//returns nullptr if item < head_ptr._item or if head_ptr == nullptr
	if (item > head_ptr->_item || item == head_ptr->_item || head_ptr == nullptr) {
		//        cout << item << " goes to the beginning of list." << endl;
		return head_ptr; //return head_ptr instead of nullptr
	}
	//return the location of the prev node where you want to insert the item
	node<T>* walker1 = head_ptr;
	node<T>* walker2 = head_ptr->_next;
	while (walker2 != nullptr) {
		if (item > walker2->_item) {
			//            cout << item << " goes before " << walker2->_item << endl;
			return walker1;
		}
		walker1 = walker1->_next;
		walker2 = walker2->_next;
	}
	return walker1;
}

//Implemented -- not yet tested

template <typename T>
//Last Node in the list
node<T>* LastNode(node<T>* head_ptr) {
	node<T>* walker = head_ptr;
	while (walker != nullptr) {
		walker = walker->_next;
	}
	return walker;
}

#endif /* LinkedList_hpp */
