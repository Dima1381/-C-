#include <iostream>
#define SIZE 25

using namespace std;

void LessMySort(int &x, int &y)
{
	if (x > y)
	{
		swap(x, y);
	}
}
void GreatMySort(int &x, int &y)
{
	if (x < y)
	{
		swap(x, y);
	}
}

void bubble_Sort(int* arr, void(*ptr_func)(int&, int&))
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			ptr_func(arr[i], arr[j]);
		}
	}
}


int main()
{
	srand(time(0));
	void(*LessPtr) (int&, int&) = LessMySort;
	void(*GreatPtr) (int&, int&) = GreatMySort;

	int *arr = new int[SIZE];

	cout << "Create array: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 99;
		cout << arr[i] << " ";
	}

	cout << "\nBubble Sort: " << endl;
	bubble_Sort(arr, GreatMySort);

	for (int i = 0; i < SIZE; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}

