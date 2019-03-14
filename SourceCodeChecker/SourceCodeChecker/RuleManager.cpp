/*
*	Last worked on 3/13/2019
*	RuleManager.cpp
*/

#include "RuleManager.h"

// Initialize the RuleManager instance
RuleManager* RuleManager::instance = new RuleManager();

// Constructior for RuleManager
RuleManager::RuleManager()
{

}

// Will return the instance of the RuleManager
RuleManager* RuleManager::getInstance()
{
	return instance;
}

// For receiving the active rules. Return false if
// there is any errors setting up the rules.
// Create using the rule name?
bool setActiveRules(vector<string> active)
{

}

// Used by parser to send the string
void run(string input)
{

}

// Will be called at the end of a file and retreive the
// final metrics from the rules then push them to storage
void finished()
{

}
