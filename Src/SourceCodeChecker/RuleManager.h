/*
*	Last worked on 3/19/2019
*	RuleManager.h
*	
*	Receives a list of rules to run from File Manager
*	and creates an array to send the data from the parser.
*	
*	Receives a line from the parser and will send to each
*	"active" rule to check for it's metric.
*	
*	Implemented as a singleton so the rules are not lost
*	while passing each line.
*/

#ifndef RULEMANAGER_H
#define RULEMANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include "MasterRule.h"
//Won't be used once factory is setup
#include "Rules/IntCountRule.h"
#include "Rules/ForLoopCount.h"
#include "Rules/SemicolonCount.h"

using namespace std;

class RuleManager
{
private:
	// The instance will be stored here
	static RuleManager* instance;
	// Private constructor so it can't be called
	RuleManager();
	// To remove all pointers
	~RuleManager();
	// Used to map the file strings to their class
	//TODO: Create factory to add all rules that we
	//       create so that we can instantiate each
	//		 of the rules that we have.
	//		OR
	//		Be able to create from the string

	// List of rules stored on the hard disk
	vector<unique_ptr<MasterRule>> rules;
	// Dynamically created by list sent from File Manager
	vector<int> activeRules;
	// Stores the current files filename
	string fileName;
	// Probably won't be used because we will be queueing
	// an actual database.
	//Storage dataStore;

public:
	// Used to get the instance of Rule Manager
	static RuleManager* getInstance();
	bool setActiveRules(vector<string> active);
	void setName(string fileName);
	void run(string input);
	void finished();
};

#endif
