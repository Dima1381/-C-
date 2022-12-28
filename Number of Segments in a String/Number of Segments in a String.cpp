#include <iostream>
#include <sstream>

using namespace std;

int countSegments(string s)
{
	stringstream str(s);
	string word;

	int Number = 0;

	while (str  word)
	{
		Number++;
	}

	return Number;
}

int main()
{
	string s = Hello, my name is John;

	int res = countSegments(s);

	return 0;
}
