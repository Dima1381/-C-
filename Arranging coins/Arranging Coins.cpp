#include <iostream>

using namespace std;

int arrangeCoins(int n) 
{
	int stairs = 0;
	int complete_rows = 0;

	while (n >= 0)
	{
		stairs++;
		n -= stairs;

		if (n >= 0)
			complete_rows++;
		else
			return complete_rows;
		
	}
}

int main()
{
	int n = 15;

	int res = arrangeCoins(n);

	return 0;
}

