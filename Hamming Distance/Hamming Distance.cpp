#include <iostream>

using namespace std;

int hammingDistance(int x, int y) 
{
	int index_order_bit_x = 0;
	int index_order_bit_y = 0;

	int INT_BITS = sizeof(int) * 8;

	for (int i = INT_BITS - 1; x >= 0; i--)
	{
		if (x & (1 << i))
		{
			index_order_bit_x = i;
			break;
		}
	}

	for (int i = INT_BITS - 1; y >= 0; i--)
	{
		if (y & (1 << i))
		{
			index_order_bit_y = i;
			break;
		}
	}

	return (x > y) ? (index_order_bit_x - index_order_bit_y) : (index_order_bit_y - index_order_bit_x);

}

int main()
{
	int x = 1, y = 4;

	int res = hammingDistance(x,y);

	return 0;
}

