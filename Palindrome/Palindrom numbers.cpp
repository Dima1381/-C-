#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cout << "Enter number: ";
	cin >> n;

	int revers_n = 0;

	int temp = n;

	while (temp > 0)
	{
		revers_n = revers_n * 10 + (temp % 10);
		temp /= 10;
	}

	if (revers_n == n)
		cout << "Yes, this number is a palindrome." << endl;
	else
	    cout << "No, this number is not a palindrome." << endl;
	
}
