/*
*	Last worked on 3/19/2019
*	RuleManager.cpp
*/

#include "RuleManager.h"

RuleManager* RuleManager::instance = 0;

// Constructior for RuleManager
RuleManager::RuleManager()
{
	//int i = 0;
	//// Get list of rules on creation
	//for (std::filesystem::directory_entry p : std::filesystem::directory_iterator("Rules"))
	//{
	//	string ruleName = p.path().string();
	//	int end = ruleName.find(".cpp");
	//	if (end != string::npos)
	//	{
	//		// Start at the end of the directory name
	//		// and substract directory name and .cpp
	//		// from the total length.
	//		ruleName = ruleName.substr(6, ruleName.size() - 10);
	//		// Add rule to list of callable rules
	//		//rules[i] = callFacotry(ruleName);
	//	}
	//}

	this->rules.emplace_back(new IntCountRule());
	this->rules.emplace_back(new ForLoopCount());
	this->rules.emplace_back(new SemicolonCount());
	this->rules.emplace_back(new CommentLineCount());

	fileName = "";
}

// Will return the instance of the RuleManager
RuleManager* RuleManager::getInstance()
{
	if (instance == 0)
	{
		instance = new RuleManager();
	}

	return instance;
}

// For receiving the active rules. Return false if
// there is any errors setting up the rules.
// Create using the rule name?
void RuleManager::setActiveRules(vector<string> ruleNames)
{
	activeRules.clear();

	// Check each passed rule name
	for (auto ruleName : ruleNames)
	{
		for (int i = 0; i < rules.size(); i++)
		{
			const auto &rule = rules[i];

			if (rule->getName() == ruleName)
			{
				activeRules.emplace_back(i);
				break;
			}
		}
	}
}

void RuleManager::clearActiveRules()
{
	this->activeRules.clear();
}

// For receiving the file name. Return false if
// there is any errors setting the name.
void RuleManager::setName(string filePath)
{
	fileName = filePath;
}

// Used by parser to send the string
void RuleManager::run(string input)
{
	// Run rules that are active
	// Send line to each rule
	for(int i = 0; i < activeRules.size(); i++)
		rules[activeRules[i]]->run(input);
}

// Will be called at the end of a file and retreive the
// final metrics from the rules then push them to storage
string RuleManager::finished()
{
	string data = "{"; // Temp string to hold metrics

	// Loop all active rules to tell them the
	// parser is finished
	for (auto rule : activeRules)
	{
		data.append(rules[rule]->finished());
		data.append(", ");
	}

	data.append("}");
	data.append("\0");

	return data;
}