/*
*	Last worked on 3/19/2019
*	Parser.cpp
*	
*	Receive a file and parse it into lines then
*	send each line to Rule Manager.
*/
#include<iostream>
#include<fstream>
#include "Parser.h"
using namespace std;

// Will intialize ruleManager if called by just Parser
Parser::Parser()
{
	ruleManager = ruleManager->getInstance();
}

/*
For some reason this breaks... Have to look into it later
// Just calls Parse using the filePath as a shortcut
Parser::Parser(string path)
{
	ruleManager = ruleManager->getInstance();

	Parse(path);
}
*/
// TODO: Add a way to tell the RuleManager what
//		 file is currently being used

//Main function used to parse files
// Doesn't need to return anything
// it calls Rule Manager directly
void Parser::Parse(string filePath)
{
	// Create input file stream and open file
	ifstream myfile;
	cout << filePath;
	myfile.open(filePath);

	// Function to send RuleManager filepath

	string line;

	if (myfile.is_open())
	{
		// Tell RuleManager what file is being
		// parsed currently
		ruleManager->setName(filePath);

		// Pull out each line to send to Rule Manager
		while (getline(myfile, line))
		{
			// Send the line to rule manager
			ruleManager->run(line);
		}
		// Close the file
		myfile.close();
		ruleManager->finished();
	}
}