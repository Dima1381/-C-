#include <iostream>

using namespace std;

int* addTwoNumbers(int *arr1, int*arr2, int len1, int len2)
{
	int sum1 = 0, sum2 = 0;
	int res_sum = 0;
	int* result_arr = new int[len1 + len2];

	for (int i = len1 - 1; i >= 0; i--)
	{
		sum1 = sum1 * 10 + arr1[i];
	}
	for (int i = len2 - 1; i >= 0; i--)
	{
		sum2 = sum2 * 10 + arr2[i];
	}

	res_sum = sum1 + sum2;
	int i = 0;

	cout << "\nOutput: [ ";
	while (res_sum > 0)
	{
		result_arr[i] = res_sum % 10;
		res_sum /= 10;
		cout << result_arr[i] << " ";
		i++;
	}
	cout << "]" << endl;

	result_arr[i] = '\0';
	return result_arr;
}

int main()
{
	int arr1[] = { 9,9,9,9,9,9,9};
	int arr2[] = {9,9,9,9};
	int len_arr1 = sizeof(arr1) / sizeof(arr1[0]);
	int len_arr2 = sizeof(arr2) / sizeof(arr2[0]);

	cout << "Input : array1 [ ";
	for (int i = 0; i < len_arr1; i++)
	{
		cout << arr1[i] << " ";
	}
	cout << "]   ";

	cout << "array2 [ ";
	for (int i = 0; i < len_arr2; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << "]" << endl;

	int *res = addTwoNumbers(arr1, arr2, len_arr1, len_arr2);

	delete[] res;
}

