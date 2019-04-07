#ifndef FORLOOPCOUNT_H
#define FORLOOPCOUNT_H

#include <iostream>
#include <string>
#include "../MasterRule.h"

using namespace std;

class ForLoopCount : public MasterRule
{
public:
	ForLoopCount();
	virtual void run(string l);
	virtual string finished();
	string getName();

private:
	// Base required variables
	string name;
	//int state;
	// Used to store data that is returned to the RuleManager
	//int count;
	//string data;
};

#endif
