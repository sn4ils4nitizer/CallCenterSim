#pragma once
#include "QInterface.h"
#include "LinkedList.h"

class DynamicQ : QInterface {
private:
	LinkedList list;
public:
	void push(std::string& item) {
		list.addFront(item);
	}

	void pop() {
		list.removeFront();
	}

	std::string peek() {
		return list.getFront();
	}

	void display() {
		list.display();
	}

	bool isEmpty() {
		return list.isEmpty();
	}
};