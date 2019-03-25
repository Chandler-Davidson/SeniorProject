/*
*	Last worked on 3/19/2019
*	IntCountRule.cpp
*/

#include "IntCountRule.h"

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
	// Check for the string "int"
	int found = l.find("int ");
	// Check to make sure there is something before
	// the point so you don't get an out of scope error
	if (found - 1 > 0)
	{
		// Make sure there no letters immediately
		// before it.
		if (l.substr(found - 1, 1) == " ")
		{
			// Check to make sure there is something after
			// the point so you don't get an out of scope error
			if (found + 4 < l.size())
			{
				count++;
			}
			else
				// If there isn't tick count up one
				if (l.substr(found + 4, 1) == " ")
				{
					// If there isn't tick count up one
					count++;
				}
		}
	}
	else
	{
		// Check to make sure there is something before
		// the point so you don't get an out of scope error
		if (found + 4 <= l.size())
		{
			if (l.substr(found + 4, 1) == " ")
			{
				// If there isn't tick count up one
				count++;
			}
		}
	}
	// Otherwise don't do anything

	//TODO: Need loop this on the line continuing on to make sure someone
	// doesn't initialize two or more on the same line. 
	// i.e. int five = 5; int six = 7; // etc..

	//TODO: Exclude int's in comments
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