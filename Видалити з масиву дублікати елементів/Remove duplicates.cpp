#include <iostream>
using namespace std;

int arrayUnique(int array[], int size)
{
    for (int counter1 = 0; counter1 < size; counter1++)
    {
        cout << array[counter1] << " ";
        for (int counter2 = counter1 + 1; counter2 < size; counter2++)
        {
            if (array[counter1] == array[counter2])
            {
                for (int shift = counter2; shift < size - 1; shift++)
                {
                    array[shift] = array[shift + 1];
                }
                size--;
                if (array[counter1] == array[counter2])
                {
                    counter2--;
                }
            }
        }
       
    }

    return size;
}

int main()
{
    srand(time(0));

    cout << "Enter array size: " << endl;
    int size;
    cin >> size;

    int* array = new int[size];

   for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 19;
        cout << array[i] << " ";
    }
    cout << endl;

    int new_size = arrayUnique(array, size);

    cout << endl << "New array size: " << new_size;
    return 0;
}


