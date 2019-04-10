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
		string temp2 = "";
		string temp = string(argv[i]);
		if(sizeof(argv) >= i+1)
			temp2 = string(argv[i + 1]);
		if(temp == "-filepath")
		{
			std::istringstream iss(temp2);
			for (std::string s; iss >> s; )
				filePaths.emplace_back(s);
		}

		else if (temp == "-rules")
		{
			std::istringstream iss(temp2);
			for (std::string s; iss >> s; )
				activeRules.emplace_back(s);
		}
	}
	//filePaths.push_back("C:\\Users\\Bobby\\Documents\\GitHub\\SeniorProject\\SourceCodeChecker\\SourceCodeChecker\\Rules\\IntCountRule.cpp");
	//activeRules.push_back("ForLoopCount");
	//activeRules.push_back("SemicolonCount");
	//activeRules.push_back("IntCountRule");


	// Set ruleManager Rules
	ruleManager->setActiveRules(activeRules);

	// Run Parser on files
	for(j = 0; j < filePaths.size(); j++)
		parser.Parse(filePaths[j]);

	cin.get();

	return 0;
}
