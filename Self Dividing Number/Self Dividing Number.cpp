#include <iostream>
#include <vector>

using namespace std;

bool solve(int num)
{
	int temp = num;
	while (temp)
	{
		if (temp % 10 == 0)
			return false;

		else if (num % (temp % 10) != 0)
			return false;

		temp /= 10;
	}

	return true;
}
vector<int> selfDividingNumbers(const int left, const int right)
{
	vector<int> res;

	if ((right < left) || (left < 1) || (right > pow(10,4)))
		return res;

	for (int i = left; i <= right; i++)
	{
		if (solve(i))
		{
			res.push_back(i);
		}
	}
	return res;
}

int main() 
{
	vector<int> res = selfDividingNumbers(1, 22);
	return 0;
}
