#ifndef LINKED_LIST_H
#define LINKED_LIST_H

//Linked List General Functions:

#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
struct node {
	node() {
		_next(NULL);
	}

	node(const T& item = T(), node<T>* next = NULL){
		_item = item;
		_next = next;
	}

	T _item;
	node<T>* _next;
};

//Linked List General Functions:
template <typename T>
void PrintList(node<T>* head) {
	node<T>* walker = head;
	cout << " " << walker->_item << " ";
	walker = walker->_next;
}

template <typename T>
node<T>* SearchList(node<T>* head, T key) {
	node<T>* walker = head;
	while (walker->_next != NULL) {
		if (walker->_item == key) {
			return walker;
		}
		walker = walker->_next;
	}
	return NULL;
}

template <typename T>
node<T>* InsertHead(node<T> *&head, T insertThis) {
	node<T>* newNode = new node<T>(insertThis);
	newNode->_next = head;
	head = newNode;
	return head;
}

template <typename T>
node<T>* InsertAfter(node<T>*& head, node<T>* afterThis, T insertThis) {
	node<T>* newNode = new node<T>(insertThis);
	newNode->_next = afterThis->_next;
	afterThis->_next = newNode;
	return newNode;
}

template <typename T>
node<T>* InsertBefore(node<T>*& head, node<T>* beforeThis, T insertThis) {
	if (beforeThis == head) {
		return::InsertHead(head, insertThis);
	}
	else {
		node<T>* walker = head;
		while (walker != NULL) {
			if (walker->_next == beforeThis) {
				return::InsertAfter(head, walker, insertThis);
			}
			walker = walker->_next;
		}
	}
	return NULL;
}

template <typename T>
node<T>* PreviousNode(node<T>* head, node<T>* prevToThis) {
	node<T>* walker = head;
	while (walker != NULL) {
		if (walker->_next == prevToThis) {
			return walker;
		}
		walker = walker->_next;
	}
	return NULL;
}

template <typename T>
T DeleteNode(node<T>*&head, node<T>* deleteThis) {
	T item = deleteThis->_item;
	if (deleteThis == head) {
		head = head->_next;
	}
	node<T>* walker = head;
	while (walker != NULL) {
		if (walker->_next == deleteThis) {
			walker->_next = deleteThis->_next;
		}
		walker = walker->_next;
	}
	delete deleteThis;
	return item;
}

template <typename T>
node<T>* CopyList(node<T>* head) {
	node<T>* newHead = new node<T>(head->_item, NULL);
	node<T>* srcWalker = head->_next;
	node<T>* destWalker = newHead;
	while (srcWalker != NULL) {
		destWalker = InsertAfter(newHead, destWalker, srcWalker->_item);
		srcWalker = srcWalker->_next;
	}
	return newHead;
}

template <typename T>
void ClearList(node<T>*& head) {                    //delete all the nodes
	while (head != NULL) {
		T trash = DeleteNode(head, head);
	}
	delete head;
}

template <typename T>
T& At(node<T>* head, int pos) {
	int count = -0;
	node<T>* walker = head;
	while (walker != NULL) {
		if (count == pos) {
			return walker->_item;
		}
		count++;
		walker = walker->_next;
	}
	//return NULL;
}

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename T>
node<T>* InsertSortedUnique(node<T>* &head, T item, bool ascending = true) {
	if (SearchList(item) == NULL) {
		return::InsertSorted(head, item);
	}
	return head;
}

template <typename T>
node<T>* InsertSorted(node<T>* &head, T item, bool ascending = true) {
	node<T>* sortedNode;
	node<T>* goHere = WhereThisGoes(head, item);
	if (goHere == NULL) {
		sortedNode = InsertHead(head, item);
	}
	else {
		sortedNode = InsertAfter(head, goHere, item);
	}
	return sortedNode;
}

template <typename T>
node<T>* WhereThisGoes(node<T>* head, T item, bool ascending = true) {
	node<T>* walker = head;
	if (item < head->_item) {
		return NULL;
	}
	while (walker != NULL) {
		if (walker->_next == NULL || item < walker->_next->_item) {
			return walker;
		}
		walker = walker->_next;
	}
}

template <typename T>
node<T>* LastNode(node<T>* head) {
	node<T>* walker = head;
	while (walker != NULL) {
		if (walker->_next == NULL) {
			return walker;
		}
		walker = walker->_next;
	}
	return NULL;
}

void PrintList(node<int>* head) {
	node<int>* walker = head;
	while (walker != NULL) {
		cout << walker->_item << " --> ";
		walker = walker->_next;
	}
	cout << "NULL" << endl;
}

#endif
