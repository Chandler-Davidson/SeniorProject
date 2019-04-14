#include "Parser.h"
#include "RuleManager.h"
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#include "Analyzer.h"
#include "RuleManager.h"

using namespace std;

void SetActiveRules(char * config)
{
	// Convert getInstance() to static method
	RuleManager* ruleManager;
	ruleManager = ruleManager->getInstance();

	// Convert char* to vector<string>
	ruleManager->setActiveRules(vector<string>());
}

void SetFilePaths(char * config)
{
	throw "Not yet implemented";

	// Convert getInstance() to static method
	/*Parser* parser;
	parser = parser->getInstance();

	parser->setFilePaths(vector<string>());*/
}

int StartAnalysis()
{
	// Convert getInstance() to static method
	/*Parser* parser;
	parser = parser->getInstance();*/

	string output = "";

	// Run analysis per file
	//for (auto file : parser->getFilePaths)
	//{
	//	// Build JSON output
	//	output += parser.Parse(file);
	//}

	// Return JSON
	return stoi(output);
}