#include <iostream>

using namespace std;

bool detectCapitalUse(const string word) 
{
	int len_word = word.length();

	for (int i = 0; i < len_word; i++)
	{
		if (word[i] >= 'A' && word[i] <= 'Z') // All letters in this word are capitals
		{
			if ((i > 0))
			{
				for (int j = i; j < len_word; j++)
				{
					if (!(word[j] >= 'A' && word[j] <= 'Z'))
						return false;
				}
			}
		}

		else if (word[i] >= 'a' && word[i] <= 'z') // All letters in this word are not capitals, 
			                                       // and Only the first letter in this word is capital
		{
			if (i >= 0)
			{
				for (int j = i; j < len_word; j++)
				{
					if (word[j] >= 'A' && word[j] <= 'Z')
						return false;
				}
			}
		}
	}


	return true;
}

int main()
{

	bool res = detectCapitalUse("Loveleetcode");

	return 0;
}
