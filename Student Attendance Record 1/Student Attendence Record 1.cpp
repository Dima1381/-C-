#include <iostream>

using namespace std;

bool checkRecord(string s) 
{
	int counter_A = 0;
	int counter_L = 0;

	int len_s = s.length();

	for (int i = 0; i < len_s; i++)
	{
		if (s[i] == 'A')
			counter_A++;

		if (s[i] == 'L')
			counter_L++;

		else
			counter_L = 0;

		if ((counter_A >= 2) || (counter_L >= 3))
			return false;
	}

	return true;
}
int main()
{

	bool res = checkRecord("PPALLALL");

	return 0;
}
