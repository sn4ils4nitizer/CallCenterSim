#pragma once
#include <string>
class QInterface {
public:
	virtual void push(std::string& item) = 0;
	virtual std::string peek() = 0;
	virtual void pop() = 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;
};