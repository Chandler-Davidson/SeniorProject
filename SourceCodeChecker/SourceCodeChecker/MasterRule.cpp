/*
*	Last worked on 3/14/2019
*	MasterRule.cpp
*/

#include "MasterRule.h"

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
void MasterRule::run(string l)
{
	//Read line
}

// Called after the file has finished being read
// used to send collected metrics back to the
// rule manager. 
// ~~Be sure to add this to your class and customize as needed.
string MasterRule::finished()
{
	// Put data in a string and return it to the Rule Manager
	return data;
}
