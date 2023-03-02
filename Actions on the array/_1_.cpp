#include <iostream>

using namespace std;

char* voidNumberAsBinary(char* _result, unsigned int _number)
{
	int number = _number;
	int i = 0;

	while (number > 0)
	{
		_result[i] = (number % 2) + '0';
		number /= 2;
		i++;
	}

	for (size_t j = 0; j < i / 2; j++)
	{
		swap(_result[j], _result[i - j - 1]);
	}

	_result[i] = '\0';
	return _result;
}

int main()
{
	srand(time(NULL));

	unsigned int random = 0;
	char* result = new char[11]{};

	for (size_t i = 0; i < 10; i++)
	{
		random = rand() % 513;
		cout << "[ " << i << " ]  Number ( " << random << " ) " << "  Binary = " << voidNumberAsBinary(result, random) << endl;
	}

	delete[] result;
	return 0;
}
