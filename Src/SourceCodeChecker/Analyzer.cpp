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
	// Delimit string to vector<string>
	auto rules = split(config, ",");

	// Get RuleManager instance
	auto ruleManager = RuleManager::getInstance();

	// Set ActiveRules
	ruleManager->setActiveRules(rules);
}

void SetFilePaths(char * config)
{
	// Delimit string to vector<string>
	auto filePaths = split(config, ",");

	// Get Parser instance
	auto parser = Parser::getInstance();

	// Set file paths
	parser->setFilePaths(filePaths);
}

void StartAnalysis(char * results)
{
	// Get Parser instance
	auto parser = Parser::getInstance();
	auto ruleManager = RuleManager::getInstance();

	// Analyze each file
	parser->Parse();

	// Return json output
	auto json = ruleManager->finished();

	// Return JSON
	strcpy(results, json.c_str());
}

// Helper function to delimit strings
vector<string> split(char *phrase, string delimiter) {
	vector<string> list;
	string s = string(phrase);
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		list.push_back(token);
		s.erase(0, pos + delimiter.length());
	}
	list.push_back(s);
	return list;
}
