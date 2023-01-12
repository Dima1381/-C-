#include <iostream>

using namespace std;

bool checkPerfectNumber(int num) 
{
	int perferc_num = 0;

	for (int i = 1; i <= num / 2; i++)
	{
		if ((num % i) == 0)
			perferc_num += i;
	}

	if (perferc_num == num)
		return true;
	else
		return false;


}

int main()
{
	int num = 29;

	bool res = checkPerfectNumber(num);

	return 0;
}