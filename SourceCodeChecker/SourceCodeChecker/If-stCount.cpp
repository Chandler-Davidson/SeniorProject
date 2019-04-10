//Count number of "if" statements
#include<iostream>
#include<string>
#include<regex>
#include "If-stCount.h"
#include"RuleManager.h"

IfCountRule::IfCountRule()
{

	string name = "CommentLineRule"; // Name of the rule
	int count = 0; // A storeage var for any rule that just has a count
	string data = ""; // A var to send finialized data back to rule manager

}

// Return the name of the rule. Used to initialize
string IfCountRule::getName()
{
	return name;
}

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
void IfCountRule::run(string l)
{
	//Count "if" statements
	regex if_count("^.*if.[a-zA-z0-9_\\(]*.*\\)$");

	if (regex_match(l, if_count))
		count += 1;
}

// Called after the file has finished being read
// used to send collected metrics back to the
// rule manager. 
// ~~Be sure to add this to your class and customize as needed.
string IfCountRule::finished()
{
	data = count;                      


	cout << "\n" << count << "\n";
	// Return count to 0
	count = 0;
	// Put data in a string and return it to the Rule Manager
	return data;
}
