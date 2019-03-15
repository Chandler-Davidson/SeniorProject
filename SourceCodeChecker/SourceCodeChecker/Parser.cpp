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
#include "RuleManager.h"

using namespace std;

// TODO: Add a way to tell the RuleManager what
//		 file is currently being used

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

	// Function to send RuleManager filepath

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