#pragma once
#include <string>
#include "Call.h"

class Node
{
public:
	Call data;
	Node* next;

	Node(Call& value) : data(value), next(nullptr){}
	Node(Node* nextNode) : next(nextNode), data(Call()) {}
	//{
		// data = value;
		// next = nullptr;
	//}

	~Node()
	{
		if (next != nullptr)
			delete next;
	}
};
