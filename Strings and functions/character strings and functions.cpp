#include <iostream>
#include <string>

using namespace std;

string Іnsert(string s, string s1, int n)
{
	int index = 0;
	int temp = 0;
	string result = "";
	for (int i = 0; i < n; i++)
	{
		result += s[i];
		temp = i;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		result += s1[i];
	}
	for (int i = temp + 1; i < s.size(); i++)
	{
		result += s[i];
	}
	result += '\0';
	return result;
}


int main()
{
	setlocale(NULL, "Ukr");
	string s;
	string s1;
	int n;

	string temp = "";
	while (temp != "***")
	{
		cout << "[ Вставка в рядок s пiд рядка s1, починаючи з позицiї n ]" << endl;
		cout << "Введiть рядок s : ";
		getline(cin, s);
		cout << "Введiть рядок s1 : ";
		getline(cin, s1);

		bool flag = true;
		while (flag)
		{
			cout << "Введiть позицiю n : ";
			cin >> n;
			if ((n > s.length()) || (n < 0))
			{
				cout << "n не знаходиться в межах рядка s" << endl;
				continue;
			}
			flag = false;
		}
		cout << endl << Іnsert(s, s1, n);

		cout << endl << "Для виходу з програми введiть: ***" << endl;
		cin.ignore();
		getline(cin, temp);
	}

}
