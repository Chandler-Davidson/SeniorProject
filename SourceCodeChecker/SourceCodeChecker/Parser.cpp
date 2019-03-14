/*
*	Last worked on 3/13/2019
*	Parser.cpp
*	
*	Receive a file and parse it into lines then
*	send each line to Rule Manager.
*/

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Parser
{
public:
	// Doesn't need to return anything
	// it calls Rule Manager directly
	void Parse(string filePath);
	
private:
	RuleManager ruleManager;
};

/*
	Main function used to parse files
*/
void Parser::Parse(string filePath)
{
	// Create input file stream and open file
	ifstream myfile;
	myfile.open(filePath);

	string line;

	if (myfile.is_open())
	{
		// Pull out each line to send to Rule Manager
		while (getline(myfile, line))
		{
			// Send the line to rule manager
			ruleManager.run(line);
		}
		// Close the file
		myfile.close();
		ruleManager.finished();
	}
}

void main()
{
	Parser myparser;
	myparser.Parse("Test1.cpp");
}