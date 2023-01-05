#include <iostream>

using namespace std;

string licenseKeyFormatting(string s, int k) 
{
	int group = 0;

	s.erase(remove(s.begin(), s.end(), '-'), s.end());

	int len_s = s.size() - 1;

	for (int i = len_s; i >= 0; i--)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
			group++;
		}
		else if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'Z'))
		{
			group++;
		}
		if (i > 0 && group == k)
		{
			s.insert(i, "-");

			group = 0;
		}
	}

	return s;
}

int main()
{
	string s = "2-5g-3-J";

	string Formatting = licenseKeyFormatting(s,2);

	return 0;
}
