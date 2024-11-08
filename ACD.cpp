#include "ACD.h"
#include <string>
#include <ctime>
using namespace std;

int ACD::id = 1000;

string ACD::getTime()
{
	const size_t SIZE = 26;
	char *buffer = new char[SIZE];
	time_t now = time(0);
	ctime_s(buffer, SIZE, &now);

	return string(buffer);
}

string ACD::random(int min, int max)
{
	int r = min + (rand() % (max-min));
	return to_string(r);
}

void ACD::newCall()
{
	Call call;
	call.phoneNumber = random(100, 1000) + "-" 
		             + random(100, 1000) + "-" 
					 + random(1000, 10000);
	call.time = getTime();
	call.id = to_string(ACD::id++);
	switch(rand() % 4)
	{
	case 0: call.language = "EN"; break;
	case 1: call.language = "SP"; break;
	case 2: call.language = "FR"; break;
	case 3: call.language = "CH"; break;
	}

	cout << ">>>>>>>> New call coming in: ";
	call.display();

	// TODO:  Enqueue the call.
	callQueue.push(call);
}

void ACD::handleCall()
{
	// TODO: if a call is waiting in the queue
	if (!callQueue.isEmpty())
	{
		cout << "<<<<<<<< Call has been handled: ";
		// TODO: Dequeue the call and display it.
		callQueue.peek().display();
		callQueue.pop();
	}
	else
		cout << "<<<<<<<< No calls to handle." << endl;
}

void ACD::display()
{
	// TODO:  if calls are waiting in the queue
	if (!callQueue.isEmpty())
	{
		cout << "Next caller in line: ";
		// TODO:  Display the next call to be handled.
		callQueue.peek().display();
	}
	else
		cout << "<<<<<<<< No calls to handle." << endl;
}

bool ACD::isCallWaiting() {
    return !callQueue.isEmpty();
}
