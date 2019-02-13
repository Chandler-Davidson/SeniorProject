#include <string>

template <typename T>
class Rule
{
public:
	string execute();
private:
	string name;
	T state;
};