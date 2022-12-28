#include <iostream>

using namespace std;

int countSegments(string s)
{
	int Number = 0;

	char non_word[] = { " ,"};

	int len = s.length();

	for (int i = 0; i <= len; i++)
	{
		while (i <= len)
		{
			if (strchr(non_word, s[i]) != NULL)
			{
				break;
			}
			i++;
		}

		Number++;

		while (i <= len)
		{
			if (strchr(non_word, s[i]) == NULL)
			{
				break;
			}
			i++;
		}
	}

	return Number;
}

int main()
{
	string s = "Hello, my name is John";

	int res = countSegments(s);

	return 0;
}