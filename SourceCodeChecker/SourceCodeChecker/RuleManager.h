/*
*	Last worked on 3/13/2019
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
#include "MasterRule.h"

using namespace std;

class RuleManager
{
public:
	// Used to get the instance of Rule Manager
	static RuleManager* getInstance();
	bool setActiveRules(vector<string> active);
	void run(string input);
	void finished();

private:
	// Private constructor so it can't be called
	RuleManager();
	// List of rules stored on the hard disk
	vector<MasterRule> rules;
	// Dynamically created by list sent from File Manager
	vector<int> activeRules;
	// The instance will be stored here
	static RuleManager* instance;
	// Probably won't be used because we will be queueing
	// an actual database.
	//Storage dataStore;
};

#endif
