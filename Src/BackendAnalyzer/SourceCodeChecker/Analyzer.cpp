#include "Parser.h"
#include "RuleManager.h"
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#include "Analyzer.h"
#include "RuleManager.h"

using namespace std;

void StartAnalysis(char* results, char* rules, char* files)
{
	// Set active rules
	auto ruleManager = RuleManager::getInstance();
	auto activeRules = split(rules, ",");
	ruleManager->setActiveRules(activeRules);

	// Set file paths
	auto parser = Parser::getInstance();
	auto filePaths = split(files, ",");
	parser->setFilePaths(filePaths);

	// Analyze each file
	parser->Parse();

	// Return json output
	auto json = ruleManager->finished();

	// Return JSON
	strcpy(results, json.c_str());

	// Clear active configuration
	ruleManager->clearActiveRules();
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
