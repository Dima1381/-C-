#include <iostream>

using namespace std;

int findComplement(int num) 
{
	int Complement = num;
	
	int i = (sizeof(int) * 8) - 1; // number of bits

	for ( i ; i >= 0; i--)
	{
		if (num & (1 << i)) // != 0, found the index of the most significant bit
		{
			break;
		}
	}

	for ( i ; i >= 0; i--)
	{
		Complement ^= (1 << i);
	}

	return Complement;
}


int main()
{
	int num = 5;

	int Complement = findComplement(num);

	return 0;
}
