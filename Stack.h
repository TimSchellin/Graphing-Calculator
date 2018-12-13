#ifndef STACK_H
#define STACK_H

#include "Simple_List.h"
//#include "Linked_List.h"
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class Stack {
public:

	Stack() {
		size = 0;
	}

	Stack<T>& operator=(const Stack<T>& rhs) {
		//cout << "\nstack assignment operator called";
		stack = rhs.stack;
		size = rhs.size;
		//cout << "\nstack assignment executed";
		return *this;
	}

	void push(const T& item) {
		size++;
		stack.insert_head(item);
	}

	T pop() {
		assert(stack.Begin() != nullptr);
		size--;
		return stack.Delete(stack.Begin());
	}

	T top() {
		assert(stack.Begin() != nullptr);
		return stack.Begin()->_item;
	}

	bool empty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}
	//WOW I DIDN'T THINK THIS WOULD WORK
	/*
	template <class U>
	friend ostream& operator<<(ostream& outs, const Stack<U>& s) {
		node<U>* walker = s.stack.Begin();
		while (walker != s.stack.End()) {
			outs << " [" << walker->_item << "]";
			walker = walker->_next;
		}
		return outs;
	}
	*/
private:
	int size;
	Simple_List<T> stack;

};

#endif /* STACK_H */