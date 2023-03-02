#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
using namespace std;



int *Calculate()
{
	cout << "Введiть кiлькiсть цифр, пошук яких буде здiйснено (0-9) : ";
	int number = 0;
	cin >> number;

	int* array_number = new int[number];
	int* result = new int[number] {};

	for (int i = 0; i < number; i++)
	{
		cout << "Цифра [ " << i << " ] = ";
		cin >> array_number[i];
	}

	int n;
	cout << "\nВведiть n: ";
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		int temp = i;
		while (temp != 0)
		{
			int temp2 = temp % 10;
			for (int j = 0; j < number; j++)
			{
				if (temp2 == array_number[j])
				{
					result[j] += 1;
				}
			}
			temp /= 10;
		}
	}
	cout << endl;
	for (int i = 0; i < number; i++)
	{
		cout << "Цифра [ " << array_number[i] << " ] зустрiчається ";
	    cout << result[i] <<" раз | в дiапазонi вiд 1 до n" << endl;
	}
	delete[] array_number;

	return result;
}


int main()
{
	setlocale(NULL, "Ukr");

	int *arr = Calculate();
	
	delete arr;
	return 0;
}

