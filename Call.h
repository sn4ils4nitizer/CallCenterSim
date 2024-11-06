#include <iostream>
#include <string>
using namespace std;
#pragma once

class Call
{
public:
	string phoneNumber;
	string time;
	string id;
	string language;

	void display()
	{
		cout << "\t" << id;
		cout << "\t" << phoneNumber;
		cout << "\t" << language;
		cout << "\t" << time;
		//cout << endl;
	}
};
