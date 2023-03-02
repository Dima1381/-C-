#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cout << "Enter number: ";
	getline(cin, str);

	bool check = false;

	int len = str.size();

	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		if (str[i] == str[j])
		{
			check = true;
		}
		else
		{
			check = false;
			break;
		}
	}
	if (check)
		cout << "Yes, this string is a palindrome." << endl;
	else
	    cout << "No, this string is not a palindrome." << endl;
	
}
