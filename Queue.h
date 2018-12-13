
#ifndef QUEUE_H
#define QUEUE_H

#include "Linked_List.h"
#include <iostream>
#include <cassert>

using namespace std;

template <typename T>
class Queue {
public:
	Queue() {
		this->front = nullptr;
		this->rear = nullptr;
		this->size = 0;
	}

	~Queue() {
		clear_list(front);
		front = nullptr;
		rear = nullptr;
	}

	Queue<T>& operator=(const Queue<T>& rhs) {
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

		return *this;
	}

	void push(const T& item) {
		node<T>* walker = front;
		if (walker == rear) {
			insert_head(front, item);
			rear = LastNode(front);
		}
		else {
			while (walker->_next != rear) {
				walker = walker->_next;
			}
			insert_after(front, walker, item);
			rear = LastNode(front);
		}
		this->size++;
	}

	//pop items from the front
	T pop() {
		assert(!empty());
		size--;
		cout << "\nyer1\n";
		T hold = delete_head(front);               //THIS MIGHT BE THE ISSUE
		cout << "\nyer2\n";
		rear = LastNode(front);
		if (empty()) {
			rear = front; 
		}
		return hold;
	}

	T top() {
		assert(!empty());
		return front->_item;
	}

	bool empty() {
		return this->size == 0;
	}

private:
	node<T>* front;
	node<T>* rear;
	int size;
};

#endif