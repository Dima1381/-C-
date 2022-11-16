#include <iostream>

using namespace std;

void GenerateRandomArray(int* _result, unsigned int _maxValue)
{
    for (int i = 0; i < _maxValue; i++)
    {
        _result[i] = 5 + rand() % (15 - 5 + 1);
        cout << _result[i] << " ";
    }
}

int GetMissingValue(const int* _values, unsigned int _count)
{
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < _count; i++)
    {
        sum1 += _values[i];
    }
    for (int i = 0; i < _count - 1; i++)
    {
        sum2 += _values[i];
    }

    return sum1 - sum2;
}

int main()
{
    srand(time(NULL));
    cout << "Enter size array : ";
    int N = 0;
    cin >> N;

    int* arr = new int[N];

    GenerateRandomArray(arr, N);
    cout << endl;
    cout << "Last elements : " << GetMissingValue(arr, N);


    delete[] arr;
}

