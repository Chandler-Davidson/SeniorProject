/*
*	Last worked on 3/19/2019
*	IntCountRule.cpp
*/
#include "IntCountRule.h"
//Count number of "for" loops
#include<iostream>
#include<string>
#include<regex>

IntCountRule::IntCountRule()
{
	// Base required variables
	this->name = "IntRuleCount"; // Name of the rule
	//int state = 0; // ??? Not sure what I had in mind here
	// Used to store data that is returned to the RuleManager
	this->count = 0; // A storeage var for any rule that just has a count
	this->data = ""; // A var to send finialized data back to rule manager

/* example
	ifCount = 0;
*/
}

// Return the name of the rule. Used to initialize
string IntCountRule::getName()
{
	return name;
}

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
void IntCountRule::run(string l)
{
	regex int_count("^.*int.[a-zA-Z,_0-9]*.*;$");

	if (regex_match(l, int_count))
		count += 1;
}

// Called after the file has finished being read
// used to send collected metrics back to the
// rule manager. 
// ~~Be sure to add this to your class and customize as needed.
string IntCountRule::finished()
{
	data = count;
	cout << "\n" << count << "\n";
	// Return count to 0
	count = 0;
	// Put data in a string and return it to the Rule Manager
	return data;
}
