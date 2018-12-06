
#ifndef QUEUE_H
#define QUEUE_H

#include "Linked_List.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Queue {
public:

	//constructor

	Queue() {
		this->front = nullptr;
		this->rear = nullptr;
		this->size = 0;
	}

	//copy constructor
	//NOT YET TESTED

	/*
	Queue(const Queue& other) {
		this->front = copy_list(other->front);
		this->rear = LastNode(this->front);
		this->size = other->size;
	}
	*/

	//destructor

	~Queue() {
		//cout << "destructor called\n";
		// Delete the list, set front and rear to null
		clear_list(front);
		front = nullptr;
		rear = nullptr;
	}

	//assignment operator
	//NOT YET TESTED

	Queue<T>& operator=(const Queue<T>& rhs) {
		//cout << "ass\n";
		//self-check
		if (*this == rhs) {
			return *this;
		}

		//clean up
		clear_list(front);
		rear = front;

		//re-instantiate lhs attributes
		this->front = copy_list(rhs.front);
		this->rear = LastNode(this->front);
		this->size = rhs->size;

		//copy junk over

		return *this;
	}

	// pushes item to the rear

	void push(const T& item) {
		//cout << "PUSHED YA BABE\n";
		// declare a walker to traverse down the queue
		node<T>* walker = front;
		//cout << "front location: " << front << endl;
		//cout << "rear location: " << rear << endl;
		// if the queue is empty, create a new node of capacity 1
		if (walker == rear) {
			//cout << "helloya waddle\n";
			insert_head(front, item);
			rear = LastNode(front);
			//qqq LastNode takes way too long to run
			//            walker->_next = rear;
		}// Does this work?
		else {
			//cout << "hello babe\n";
			while (walker->_next != rear) {
				walker = walker->_next;
			}
			insert_after(front, walker, item);
			//resetting rear
			rear = LastNode(front);
		}

		//cout << "front: " << front << endl;
		//queue size enlarges by 1
		this->size++;
	}

	//pop items from the front

	T pop() {
		// cannot pop an empty queue
		assert(!empty());

		//decrement the queue size
		size--;
		// hold the item front of the queue and delete front
		//cout << "POPPPED" << endl;
		//cout << "frontey: " << front << endl;
		T hold = delete_head(front);               //THIS MIGHT BE THE ISSUE
		//cout << "HEAD DELETED\n";
		//NOOOOOOOO!!! What about the rear??
		// reset rear to the last element
		rear = LastNode(front);

		//Do i need this??
		if (empty()) {
			rear = front; //does this work? I am aligning my rear to my front 
		}
		return hold;
	}

	T top() {
		// cannot check top of an empty queue
		assert(!empty());

		return front->_item;
	}

	bool empty() {
		return this->size == 0;
	}

	/*
	template <class U>
	friend ostream& operator<<(ostream& outs, const Queue<U>& q) {
		node<U>* walker = q.front;
		while (walker != q.rear) {
			outs << " [" << walker->_item << "]";
			walker = walker->_next;
		}
		return outs;
	}

	int getSize() {
		return size;
	}*/

private:
	node<T>* front;
	node<T>* rear;
	int size;
};


#endif /* QUEUE_H */