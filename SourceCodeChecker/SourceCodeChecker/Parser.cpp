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
	size_t found = NULL;
	size_t previous = 0;
	string word = "";
	const string searchStr = " ";

	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			//Check the line for "words" 
			//by getting all data between spaces
			do
			{
				// Blank word for the next run
				word = "";

				//Check for the first space
				found = line.find(searchStr);
				//Returns string::npos (-1) if end of line
				if(found != string::npos)
				{
					//Check if there is a space at start
					if(found == 0){
						//If there is just make that the last previous
						previous = found;
					}
					//As long as it's not end of line pull the "word" out
					else if(found != string::npos){
						//pull the "word" out
						word = line.substr(found, previous);
						previous = found;
					}
					else
						word = line.substr(previous, line.length());

				}

				if(word != "")
					cout << word << "\n"; //Send word to rule manager

			}while(found1 != string::npos); // Stop checking if end of line
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