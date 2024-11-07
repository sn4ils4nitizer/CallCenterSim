#pragma once
#include <iostream>
#include "Node.h"

class LinkedList
{
private:
	Node* first;

public:
	LinkedList()
	{
		first = new Node(nullptr);
	}

	~LinkedList()
	{
		delete first;
	}

	bool isEmpty()
	{
		return first->next == nullptr;
	}

	void display()
	{
		Node* temp = first->next;

		while (temp != nullptr)
		{
			temp->data.display();
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	void addFront(Call& value)
	{
		Node* newNode = new Node(value);
		newNode->next = first->next;
		first->next = newNode;
	}

	void addBack(Call& value)
	{
		// find the end of the list
		Node* temp = first;

		while (temp->next != nullptr)
			temp = temp->next;

		// attach new node to end of list
		temp->next = new Node(value);
	}

	void removeFront()
	{
		Node* temp = first->next;
		first->next = temp->next;
		temp->next = nullptr;
		delete temp;
	}

	void removeBack()
	{
		Node* temp = first->next;
		Node* trailer = first;

		while (temp->next != nullptr)
		{
			temp = temp->next;
			trailer = trailer->next;
		}

		trailer->next = nullptr;
		delete temp;
	}

	Node* findValue(Call& value)
	{
		Node* temp = first->next;

		while (temp != nullptr)
		{
			if (temp->data.id == value.id)
				return temp;
			temp = temp->next;
		}

		return nullptr;
	}

	void removeValue(Call& value)
	{
		Node* temp = first->next;
		Node* trailer = first;

		while (temp != nullptr && temp->data.id != value.id)
		{
			temp = temp->next;
			trailer = trailer->next;
		}

		if (temp != nullptr)
		{
			trailer->next = temp->next;
			temp->next = nullptr;
			delete temp;
		}
	}

	int countOccurrences(Call& value)
	{
		int counter = 0;

		Node* temp = first->next;
		while (temp != nullptr)
		{
			if (temp->data.id == value.id)
				counter++;
			temp = temp->next;
		}

		return counter;
	}

	Call getFront() {
		if (!isEmpty()) {
			return first->next->data;
		}
		else {
			return Call();
		}
	}
};
