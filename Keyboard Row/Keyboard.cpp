#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findWords(const vector<string>& words) 
{
	vector<string> v;
	v.reserve(words.size());

	string first_row = "qwertyuiopQWERTYUIOP", second_row = "asdfghjklASDFGHJKL", third_row = "zxcvbnmZXCVBNM";

	unordered_map<char, int> mp_first_row,  mp_second_row, mp_third_row;

	int size_row[3] = { first_row.length(), second_row.length(), third_row.length() };

	for (int i = 0; i < size_row[0]; i++)
	{
		mp_first_row[first_row[i]]++;
	}
	for (int i = 0; i < size_row[1]; i++)
	{
		mp_second_row[second_row[i]]++;
	}
	for (int i = 0; i < size_row[2]; i++)
	{
		mp_third_row[third_row[i]]++;
	}
	
	for (int i = 0; i < words.size(); i++)
	{
		int consists_one = 0, consists_two = 0, consists_three = 0;
		string s = words[i];
		int len = s.length();

		for (int j = 0; j < len; j++)
		{
			if (mp_first_row.find(s[j]) != mp_first_row.end())
				consists_one++;

			if (mp_second_row.find(s[j]) != mp_second_row.end())
				consists_two++;

			if (mp_third_row.find(s[j]) != mp_third_row.end())
				consists_three++;

		}
		if (consists_one == len || consists_two == len || consists_three == len)
			v.push_back(s);
	}

	return v;
}

int main()
{
	vector<string> words = { "Hello","Alaska","Dad","Peace" };

	vector<string> res = findWords(words);

	return 0;

}