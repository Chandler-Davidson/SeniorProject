
#include "MasterRule.h"

// Receive the line from RuleManager here and split
// the line up and send to checkLine to check
string MasterRule::run(string l)
{
	//Read line
}

// Where the rule will actually check the line for
// whatever metric it is currently looking for.
// ~~Be sure to add this to your class and customize as needed.
virtual void MasterRule::checkLine()
{
	// Check data
}

// Called after the file has finished being read
// used to send collected metrics back to the
// rule manager. 
// ~~Be sure to add this to your class and customize as needed.
virtual string MasterRule::finished()
{
	// Put data in a string and return it to the Rule Manager
	return data;
}
