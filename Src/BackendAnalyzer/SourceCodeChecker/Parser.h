/*
*	Last worked on 3/19/2019
*	Parser.h
*
*	This class will split a file into lines and feed
*	them to the Rule Manager along with the filePath
*/

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "RuleManager.h"

using namespace std;

#ifndef PARSER_H
#define PARSER_H

class Parser
{
private:
	Parser();
	static Parser* instance;
	RuleManager* ruleManager;
	vector<string> filePaths;

public:
	static Parser* getInstance();
	void Parse();
	void setFilePaths(vector<string>);
	vector<string> getFilePaths();
};

#endif