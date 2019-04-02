/*
*	Last worked on 3/19/2019
*	Source.cpp
*	Won't be used in final product
*	For testing only
*/

// The main file should only need access to Storage
// and File Manager. Skipping both because we don't
// have those set up yet.

#include "Parser.h"
#include "RuleManager.h"
#include <string>
#include<vector>

int main()
{
	RuleManager* ruleManager = ruleManager->getInstance();
	Parser parser;

	string filePath1 = "C:\\Users\\Bobby\\Documents\\GitHub\\SeniorProject\\SourceCodeChecker\\SourceCodeChecker\\Rules\\IntCountRule.cpp";
	string filePath2 = "C:\\Users\\Bobby\\Documents\\GitHub\\SeniorProject\\SourceCodeChecker\\SourceCodeChecker\\Rules\\IntCountRule.h";

	vector<string> activeRules;
	activeRules.push_back("IntCountRule");

	// Set ruleManager Rules
	ruleManager->setActiveRules(activeRules);

	// Run Parser on files
	parser.Parse(filePath1);

	parser.Parse(filePath2);
	
	return 0;
}
