//Count number of "for" loops
#include<iostream>
#include<string>
#include<regex>
#include "SemicolonCount.h"

SemicolonCount::SemicolonCount()
{

	this->name = "SemicolonCount"; // Name of the rule
	this->count = 0; // A storeage var for any rule that just has a count
	this->data = ""; // A var to send finialized data back to rule manager

}

// Return the name of the rule. Used to initialize
string SemicolonCount::getName()
{
	return name;
}

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
void SemicolonCount::run(string l)
{
	regex scolon_count("(^.*;.*$)*");

	if (regex_match(l, scolon_count))
		count += 1;
}

// Called after the file has finished being read
// used to send collected metrics back to the
// rule manager. 
// ~~Be sure to add this to your class and customize as needed.
string SemicolonCount::finished()
{
	data = count; //this count is out of scope .finished() needs to receive count from run()


	cout << "\n" << name << ":" << count << "\n";
	// Return count to 0
	count = 0;
	// Put data in a string and return it to the Rule Manager
	return data;
}
