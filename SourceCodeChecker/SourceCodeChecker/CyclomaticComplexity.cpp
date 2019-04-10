//Count number of comment lines
#include<iostream>
#include<string>
#include<regex>
#include "CyclomaticComplexity.h"

CyclomaticComplexity::CyclomaticComplexity()
{

	string name = "CyclomaticComplexity"; // Name of the rule
	int count = 0; // A storeage var for any rule that just has a count
	string data = ""; // A var to send finialized data back to rule manager

}

// Return the name of the rule. Used to initialize
string CyclomaticComplexity::getName()
{
	return name;
}

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
void CyclomaticComplexity::run(string l)
{
	//Count comment lines beginning with"//"
	regex cc1("^.*//.*$");

	if (regex_match(l, cc1))
		count += 1;
}

// Called after the file has finished being read
// used to send collected metrics back to the
// rule manager. 
// ~~Be sure to add this to your class and customize as needed.
string CyclomaticComplexity::finished()
{
	data = count;                    


	cout << "\n" << count << "\n";
	// Return count to 0
	count = 0;
	// Put data in a string and return it to the Rule Manager
	return data;
}
