#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Parser
{
public: 
	void Parse(string filePath);
	Parser();
private:
	//RuleManager ruleManager;
};


void Parser::Parse(string filePath)
{
	ifstream myfile;
	myfile.open(filePath);
	string line;
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
}

void main()
{
	Parser myparser;
	myparser.Parse("Test1.cpp");
}