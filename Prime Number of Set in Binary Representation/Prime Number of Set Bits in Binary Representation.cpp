#include <iostream>

using namespace std;

unsigned int number_of_units(int num)
{
	unsigned int count = 0;
	while (num) {
		count += num & 1;
		num >>= 1;
	}
	return count;
}

int simple(int n) 
{
	for (int i = 2; i <= n / 2; i++) 
		if (((n % i) == 0)) 
			return 0;

	return 1;
}
int countPrimeSetBits(int left, int right)
{
	if (left < 1 || left > right || right > pow(10, 6) || 0 > (left - right) || (left - right) > pow(10, 4))
		return 0;

	int res = 0;
	unsigned int count_unit_bits = 0;

	for (int i = left; i <= right; i++)
	{
		count_unit_bits = number_of_units(i);
		if (count_unit_bits != 1) {
			res += simple(count_unit_bits);
		}
	}
	return res;
}

int main() 
{
	int res = countPrimeSetBits(6, 10);
	return 0;
}
