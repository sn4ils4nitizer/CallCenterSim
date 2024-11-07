#pragma once
#include "QInterface.h"
#include "LinkedList.h"

class DynamicQ : QInterface {
private:
	LinkedList list;
public:
	void push(Call& item) {
		list.addFront(item);
	}

	void pop() {
		list.removeFront();
	}

	Call peek() {
		return list.getFront();
	}

	void display() {
		list.display();
	}

	bool isEmpty() {
		return list.isEmpty();
	}
};