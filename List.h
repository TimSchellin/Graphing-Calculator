#ifndef LIST_H
#define LIST_H

#include "LinkedList.h"

using namespace std;

template <class T>
class List {

private:
	node<T>* headPtr;

public:
	//Constructors
	List(){
		headPtr = NULL;
	}

	List(const List& other) {
		headPtr = NULL;
		CopyList(headPtr);
	}

	//Destructor
	~List() {
		ClearList(headPtr);
	}

	//Assignment operator

	List& operator = (const List& RHS) {
		if (this == RHS) {
			return *this;
		}

		ClearList(headPtr);

		headPtr = NULL;
		CopyList(headPtr);
		return *this;

	}

	node<T>* InsertHead(const T& item) {
		return::InsertHead(headPtr, item);
	}

	node<T>* InsertBefore(node<T>* mark, const T& item) {
		return::InsertBefore(headPtr, mark, item);
	}

	node<T>* InsertAfter(node<T>* mark, const T& item) {
		return::InsertAfter(headPtr, mark, item);
	}

	node<T>* InsertSorted(T i) {
		return::InsertSorted(headPtr, i);
	}

	T Delete(node<T>* iMarker) {
		return::DeleteNode(headPtr, iMarker);
	}

	void Print() const {
		PrintList(headPtr);
	}

	//return pointer to node containing key. NULL if not there
	node<T>* Search(const T &key) {
		return SearchList(headPtr, key);
	}

	//get the node before iMarker
	node<T>* Prev(node<T>* iMarker) {
		return PreviousNode(headPtr, iMarker);
	}

	// return the item at index
	T& operator[](int index) {
		return At(headPtr, index);
	}

	// return the head pointer
	node<T>* Begin() const {
		return headPtr;
	}

	//return the tail of the list: if you ever have to use this, you're screwed
	node<T>* End() const {
		return LastNode(headPtr);
	}

	// use the << operator to print a list
	friend ostream& operator <<(ostream& outs, const List<T>& l) {
        node<T>* walker = l.head_ptr;
        while (walker != NULL) {
            outs << walker->_item << " --> ";
            walker = walker->_next;
        }
        outs << "NULL" << endl;
        return outs;
    }
};

#endif
