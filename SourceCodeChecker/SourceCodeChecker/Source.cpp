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
#include <sstream>
#include <iterator>

int main(int argc, char** argv)
{
	RuleManager* ruleManager = ruleManager->getInstance();
	Parser parser;
	vector<string> filePaths;
	vector<string> activeRules;
	int j = 0;

	for(int i = 1; i < argc; i++)
	{
		if(argv[i] == "-filepath")
		{
			std::istringstream iss(argv[i+1]);
			std::vector<std::string> filePaths{
				std::istream_iterator<std::string>(iss), {}
			};
		}

		else if (argv[i] == "-rules")
		{
			std::istringstream iss(argv[i+1]);
			std::vector<std::string> activeRules{
				std::istream_iterator<std::string>(iss), {}
			};
		}
	}
	filePaths.push_back("C:\\Users\\Bobby\\Documents\\GitHub\\SeniorProject\\SourceCodeChecker\\SourceCodeChecker\\Rules\\IntCountRule.cpp");
	activeRules.push_back("ForLoopCount");
	activeRules.push_back("SemicolonCount");
	activeRules.push_back("IntCountRule");


	// Set ruleManager Rules
	ruleManager->setActiveRules(activeRules);

	// Run Parser on files
	for(j = 0; j < filePaths.size(); j++)
		parser.Parse(filePaths[j]);

	return 0;
}
