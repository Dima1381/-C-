#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	char str[] = "pwwkew";
	int res = 0;
	int start = -1;

	vector<int> dect(256, -1);

	for (int i = 0; i < strlen(str); i++)
	{
		if (dect[str[i]] > start)
		{
			start = dect[str[i]];
		}
		dect[str[i]] = i;
		res = max(res, i - start);
	}

	cout << res << endl;
}

