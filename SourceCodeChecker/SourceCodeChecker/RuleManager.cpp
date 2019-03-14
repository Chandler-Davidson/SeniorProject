/*
*	Last worked on 3/13/2019
*	RuleManager.cpp
*/

#include "RuleManager.h"

// Set to NULL initialy
RuleManager* RuleManager::instance = new RuleManager();

// Will return the instance of the RuleManager
RuleManager* RuleManager::getInstance()
{
	return instance;
}

// Constructior for RuleManager
RuleManager::RuleManager()
{
}
