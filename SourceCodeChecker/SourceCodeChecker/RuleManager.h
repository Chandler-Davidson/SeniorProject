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

#include <iostream>
#include <vector>
#include <string>

class RuleManager
{
public:
	// Used to get the instance of Rule Manager
	static RuleManager* getInstance();
	// Used by parser to send the string
	void run(string input);
	// Will be called at the end of a file and retreive the
	// final metrics from the rules then push them to storage
	void finished();

private:
	// Private constructor so it can't be called
	Singleton();
	// List of rules stored on the hard disk
	vector<Rule> rules;
	// Dynamically created by list sent from File Manager
	vector<int> activeRules;
	// The instance will be stored here
	static RuleManager* instance;
	// Probably won't be used because we will be queueing
	// an actual database.
	//Storage dataStore;
};