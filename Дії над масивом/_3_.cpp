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

void Sort(int* _values, unsigned int _count)
{
    int min = 0;
    
    for (int i = 0; i < _count; i++)
    {
        min = i;
        for (int j = i + 1; j < _count; j++)
        {
            if (_values[min] > _values[j])
            {
                min = j;
            }
        }
        swap(_values[i], _values[min]);

        cout << _values[i] << " ";
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
    cout << endl;
    Sort(arr, N);

    delete[] arr;
}

