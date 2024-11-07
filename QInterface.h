#pragma once
#include <string>
#include "Call.h"

class QInterface {
public:
	virtual void push(Call& item) = 0;
	virtual Call peek() = 0;
	virtual void pop() = 0;
	virtual bool isEmpty() = 0;
	virtual void display() = 0;
};