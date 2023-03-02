#include <iostream>

using namespace std;

void ranks(int number)
{
	int mask = 1;
	for (int i = number; i > 0; i /= 10)
	{
		mask *= 10;
	}
	mask /= 10;

	int temp = number;
	
	int index = 1;
	while (temp != 0)
	{
		cout << "[ " << index << " ] " << "number" << " = " << temp / mask << endl;;

		temp = temp % mask;
		mask /= 10;
		index++;
	}
}
int main()
{
    int number = 0;
    cin >> number;
	cout << endl;
	ranks(number);

	return 0;
}

