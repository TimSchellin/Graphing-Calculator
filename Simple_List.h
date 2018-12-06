
#include "Linked_List.h"

#ifndef SIMPLE_LIST_H
#define SIMPLE_LIST_H

template <typename T>
class Simple_List {
public:

	//Constructor

	Simple_List() {
		head_ptr = nullptr;
	}

	//Copy constructor

	Simple_List(const Simple_List& other) {
		//copy the junk over
		head_ptr = copy_list(other.head_ptr);
	}

	//Destructor

	~Simple_List() {
		clear_list(head_ptr);
	}

	//Assignment operator --erroneous

	Simple_List& operator=(const Simple_List& RHS) {
		//self-check
		if (head_ptr == RHS.head_ptr) {
			return *this;
		}
		//clean up the dynamic memory of LHS
		clear_list(head_ptr);
		//instantiate the LHS again
		head_ptr = nullptr;
		//copy the junk over
		head_ptr = copy_list(RHS.head_ptr);
		//return
		return *this;
	}

	node<T>* insert_head(const T& item) {
		return::insert_head(head_ptr, item);
	}

	node<T>* insert_before(node<T>* mark, const T& item) {
		return::insert_before(head_ptr, mark, item);
	}

	node<T>* insert_after(node<T>* mark, const T& item) {
		return::insert_after(head_ptr, mark, item);
	}

	//If I keep both--error: fxns only differ in return type cannot be overloaded
	   //insert item. Assume sorted list
	node<T>* InsertSorted(T item) {
		return::InsertSorted(head_ptr, item);
	}

	//delete node pointed to by iMarker
	T Delete(node<T>* iMarker) {
		return::delete_head(head_ptr);
		//        return::delete_node(head_ptr, iMarker); //for polynomial, but not for stack class
	}


	//print the list

	void Print() const {
		return print_list(head_ptr);
	}

	//return pointer to node containing key. NULL if not there

	node<T>* Search(const T &key) {
		return search_list(head_ptr, key);
	}



	//get the previous node to iMarker

	node<T>* Prev(node<T>* iMarker) {
		return PreviousNode(head_ptr, iMarker);
	}


	//return the item at index

	T& operator[](int index) {
		return At(head_ptr, index);
	}

	//return the head of the list
	node<T>* Begin() const {
		//cout << this->head_ptr->_item << endl;
		return head_ptr;
	}

	//return the tail of the list: if you ever have to use this, you're screwed

	node<T>* End() const {
		return LastNode(head_ptr);
	}

	//NOT YET IMPLEMENTED
	//insertion operator for list

	/*
	template <class U>
	friend ostream& operator<<(ostream& outs, const Simple_List<U>& l) {
		node<U>* walker = l.head_ptr;
		while (walker != nullptr) {
			outs << " [" << walker->_item << "] -->";
			walker = walker->_next;
		}
		outs << "|||" << endl;

		return outs;
	}
	*/
private:
	node<T>* head_ptr;

};

#endif /* SIMPLE_LIST_H */