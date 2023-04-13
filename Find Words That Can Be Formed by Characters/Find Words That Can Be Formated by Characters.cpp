#include <iostream>
#include <vector>

using namespace std;

int countCharacters(vector<string>& words, string chars) 
{
	int answer = 0;

	for (int i = 0; i < words.size(); i++)
	{
		vector<int> Ischar(26, 0);

		for (int j = 0; j < chars.length(); j++)
			Ischar[chars[j] - 'a']++;

		bool cheak = true;
		for (int j = 0; j < words[i].size(); j++)
		{
			if (Ischar[(words[i][j]) - 'a'] == 0)
			{
				cheak = false;
				break;
			}
			Ischar[(words[i][j]) - 'a']--;
		}

		if (cheak)
			answer += words[i].size();
	}

	return answer;
}

int main()
{
	vector<string> words = { "cat", "bt", "hat", "tree" };
	string chars = "atach";

	int answer = countCharacters(words, chars);

	return 0;
}
