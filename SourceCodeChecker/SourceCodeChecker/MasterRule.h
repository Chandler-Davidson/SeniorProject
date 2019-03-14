/*
*	Last worked on 3/13/2019
*	Rule.h
*	
*	This is a general class that all other rules will
*	inherent from.
*	
*	Each rule will check for one metric within a line from
*	the file parsed by the parser
*/

#include <string>

class MasterRule
{
public:
	// Receive the line from RuleManager here and split
	// the line up and send to checkLine to check
	string run(string l);

private:
	// Where the rule will actually check the line for
	// whatever metric it is currently looking for.
	// Be sure to add this to your class and customize as needed.
	virtual void checkLine();

	// Called after the file has finished being read
	// used to send collected metrics back to the
	// rule manager. 
	// Be sure to add this to your class and customize as needed.
	virtual string finished();

	// Base required variables
	string name;
	int state;
};
