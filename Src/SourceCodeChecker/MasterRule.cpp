/*
*	Last worked on 3/19/2019
*	MasterRule.cpp
*/

#include "MasterRule.h"
#include<string>
#include<iostream>
using namespace std;

MasterRule::MasterRule()
{
	// Base required variables
	name = ""; // Name of the rule
	//int state = 0; // ???
	// Used to store data that is returned to the RuleManager
	count = 0; // A storeage var for any rule that just has a count
	data; // A var to send finialized data back to rule manager
}

string MasterRule::getName()
{
	return this->name;
}

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
void MasterRule::run(string l)
{
	//Read line and parse line
}

// Called after the file has finished being read
// used to send collected metrics back to the
// rule manager. 
// ~~Be sure to add this to your class and customize as needed.
string MasterRule::finished()
{
	data = count;
	cout << "\n" << name << ":" << count << "\n";

	count = 0;
	// Put data in a string and return it to the Rule Manager
	return data;
}