//Count number of "for" loops
#include<iostream>
#include<string>
#include<regex>
#include "ForLoopCount.h"

ForLoopCount::ForLoopCount()
{
	
	string name = "ForLoopCount"; // Name of the rule
	int count = 0; // A storeage var for any rule that just has a count
	string data = ""; // A var to send finialized data back to rule manager
	
}

// Return the name of the rule. Used to initialize
string ForLoopCount::getName()
{
	return name;
}

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
void ForLoopCount::run(string l)
{
	regex for_count( "^.*for.*\\)$");

	if (regex_match(l, for_count))
		count += 1;
}

	// Called after the file has finished being read
	// used to send collected metrics back to the
	// rule manager. 
	// ~~Be sure to add this to your class and customize as needed.
	string ForLoopCount::finished()
	{
		data = count;                      //this count is out of scope .finished() needs to receive count from run()


		cout << "\n" << count << "\n";
		// Return count to 0
		count = 0;
		// Put data in a string and return it to the Rule Manager
		return data;
	}
	