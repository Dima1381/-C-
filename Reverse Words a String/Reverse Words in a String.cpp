#include <iostream>

using namespace std;

string reverseWords(string s) 
{
	int left_index = 0;
	int len = s.length();

	for (size_t i = 0; i < len; i++)
	{
		if (s[i] == ' ')
		{
			reverse(s.begin() + left_index, s.begin() + i);

			left_index = i + 1;
		}
	}

	reverse(s.begin() + left_index, s.end());

	return s;
}

int main()
{
	string res = reverseWords("Let's take LeetCode contest");

	return 0;
}
