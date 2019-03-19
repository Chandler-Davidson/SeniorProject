#pragma once
/*
*	Last worked on 3/19/2019
*	IntCountRule.h
*
*	This rule will count how many int's can be initialized
*	within a file.
*
*	It will return a count
*/

#ifndef INTCOUNTRULE_H
#define INTCOUNTRULE_H

#include <iostream>
#include <string>
#include "../MasterRule.h"

using namespace std;

class IntCountRule : public MasterRule
{
public:
	IntCountRule();
	virtual void run(string l);
	virtual string finished();
	string getName();

private:
	// Base required variables
	string name;
	int state;
	// Used to store data that is returned to the RuleManager
	//int count;
	//string data;
};

#endif
