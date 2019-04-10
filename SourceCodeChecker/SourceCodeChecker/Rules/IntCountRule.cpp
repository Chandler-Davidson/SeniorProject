//Count number of int declarations
#include<iostream>
#include<string>
#include<regex>
#include "IntCountRule.h"
#include "MasterRule.h"
using namespace std;

IntCountRule::IntCountRule()
{

	string name = "IntCountRule"; // Name of the rule
	int count = 0; // A storeage var for any rule that just has a count
	string data = ""; // A var to send finialized data back to rule manager
	
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


	cout <<  count << "\n";
	// Return count to 0
	count = 0;
	// Put data in a string and return it to the Rule Manager
	return data;
}
