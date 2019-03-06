#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Parser
{
public:
	void Parse(string filePath);
private:
	//RuleManager ruleManager;
};


void Parser::Parse(string filePath)
{
	ifstream myfile;
	myfile.open(filePath);
	string line;
	size_t found = NULL;
	size_t previous = 0;
	string word = "";
	int strLen = NULL;
	const string searchStr = " ";

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			strLen = line.length();
			previous = 0;
			//Check the line for "words" 
			//by getting all data between spaces
			do
			{
				// Blank word for the next run
				word = "";

				//Check for the first space
				found = line.find(searchStr, previous+1);
				//Check if there is a space at start
				if (found == 0) {
					//If found == 0 do nothing
				}
				//As long as it's not end of line pull the "word" out
				else if (found != string::npos) {
					//pull the "word" out
					word = line.substr(previous, found-previous);
					previous = found;
				}
				else
					word = line.substr(previous, strLen-previous);

				if (word != "")
					cout << word << "\n"; //Send word to rule manager

			} while (found != string::npos); // Stop checking if end of line
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