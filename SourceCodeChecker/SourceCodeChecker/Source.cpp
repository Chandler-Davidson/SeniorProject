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
#include <vector>
#include <stringstream>

int main(int argc, char** argv)
{
	RuleManager* ruleManager = ruleManager->getInstance();
	Parser parser;
	vector<string> filePaths;
	vector<string> activeRules;
	int j = 0

	for(int i = 1; i < argc; i++)
	{
		if(argv[i] == "-filepath")
		{
			j = 0;
			std::istringstream iss(argv[i+1]);;
			for(std::string s; iss >> s; )
			{
    			filePaths[j].emplace_back(s);
    			j++
			}
		}

		else if (argv[i] == "-rules")
		{
			j = 0;
			std::istringstream iss(argv[i+1]);;
			for(std::string s; iss >> s; )
			{
    			activeRules[j].emplace_back(s);
    			j++
			}
		}
	}

	// Set ruleManager Rules
	ruleManager->setActiveRules(activeRules);

	// Run Parser on files
	for(j = 0; j < filePaths.size(); j++)
		parser.Parse(filePaths[j]);
	
	return 0;
}
