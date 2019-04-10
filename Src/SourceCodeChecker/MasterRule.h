/*
*	Last worked on 3/19/2019
*	MasterRule.h
*	
*	This is a general class that all other rules will
*	inherent from.
*	
*	Each rule will check for one metric within a line from
*	the file parsed by the parser
*/

#ifndef MASTERRULE_H
#define MASTERRULE_H

#include <iostream>
#include <string>

using namespace std;

class MasterRule
{
public:
	MasterRule();
	virtual void run(string l);
	virtual string finished();
	virtual string getName();

protected:
	// Used to store data that is returned to the RuleManager
	int count;
	string data;

private:
	// Base required variables
	string name;
	int state;
};

#endif
