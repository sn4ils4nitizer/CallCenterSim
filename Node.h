#pragma once
#include <string>

class Node
{
public:
	std::string data;
	Node* next;

	Node(std::string value)
	{
		data = value;
		next = nullptr;
	}

	~Node()
	{
		if (next != nullptr)
			delete next;
	}
};
