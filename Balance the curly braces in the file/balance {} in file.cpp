#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void balance(string name_file)
{
	int counter_bracket_open = 0;
	int counter_bracket_close = 0;
	fstream file;
	file.open(name_file);

	if (!file.is_open())
	{
		cout << "File could not be opened :(" << endl;
	}
	else
	{
		char ch;
		while (file.get(ch))
		{
			if (ch == '{')
			{
				counter_bracket_open++;
			}
			else if (ch == '}')
			{
				counter_bracket_close++;
			}
		}
		file.close();
	}

	if ((counter_bracket_open == counter_bracket_close) && (counter_bracket_open != 0))
	{
		cout << "The balance is not broken :)" << endl;
	}
	else if (counter_bracket_open > counter_bracket_close)
	{
		cout << "The balance is broken '{' more " << endl;
	}
	else if (counter_bracket_open < counter_bracket_close)
	{
		cout << "The balance is broken '}' more " << endl;
	}
}
int main()
{
	string file_name = "";

	cout << "Name file: " << endl;
	getline(cin, file_name);

	balance(file_name);
}
