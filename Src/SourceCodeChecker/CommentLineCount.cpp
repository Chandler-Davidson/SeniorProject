//Count number of comment lines
#include<iostream>
#include<string>
#include<regex>
#include "CommentLineCount.h"

CommentLineCount::CommentLineCount()
{

	string name = "CommentLineCount"; // Name of the rule
	int count = 0; // A storeage var for any rule that just has a count
	string data = ""; // A var to send finialized data back to rule manager

}

// Return the name of the rule. Used to initialize
string CommentLineCount::getName()
{
	return name;
}

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
void CommentLineCount::run(string l)
{
	//Count comment lines beginning with"//"
	regex comment_count("^.*//.*$");

	if (regex_match(l, comment_count))
		count += 1;
}

// Called after the file has finished being read
// used to send collected metrics back to the
// rule manager. 
// ~~Be sure to add this to your class and customize as needed.
string CommentLineCount::finished()
{
	data = count;                      //this count is out of scope .finished() needs to receive count from run()


	cout << "\n" << count << "\n";
	// Return count to 0
	count = 0;
	// Put data in a string and return it to the Rule Manager
	return data;
}