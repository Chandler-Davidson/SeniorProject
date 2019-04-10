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
public:
	Parser();
	//Parser(string path);
	void Parse(string filePath);

private:
	RuleManager* ruleManager;
};

#endif