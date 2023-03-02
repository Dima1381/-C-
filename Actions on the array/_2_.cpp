
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void GenerateRandomArray(int* _result, unsigned int _maxValue)
{
    for (int i = 0; i < _maxValue; i++)
    {
        _result[i] = rand() % (_maxValue + 1);
        cout << _result[i] << " ";
    }
}

int main()
{
    srand(time(NULL));
    cout << "Enter size array : ";
    int N = 0;
    cin >> N;

    int* arr = new int[N];

    GenerateRandomArray(arr, N);

    delete[] arr;
}