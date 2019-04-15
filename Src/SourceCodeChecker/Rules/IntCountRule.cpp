//Count number of "for" loops
#include<iostream>
#include<string>
#include<regex>
#include "IntCountRule.h"

IntCountRule::IntCountRule()
{

	this->name = "IntCountRule"; // Name of the rule
	this->count = 0; // A storeage var for any rule that just has a count
	this->data = ""; // A var to send finialized data back to rule manager

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
	// Format data
	data.append(this->getName());
	data.append(": ");
	data.append(std::to_string(count));

	// Return count to 0
	count = 0;

	return data;
}