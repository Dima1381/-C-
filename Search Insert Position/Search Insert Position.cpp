#include <iostream>

using namespace std;

int binarySearch(int *arr, int size, int key)
{
    int LeftBound = 0;
    int RightBound = size - 1;
    int middle = 0;

    do
    {
        middle = (LeftBound + RightBound) / 2;

        if (key == arr[middle])
            return middle;

        else if (key < arr[middle])
            RightBound = middle - 1;

        else if (key > arr[middle])
            LeftBound = middle + 1;


    } while (LeftBound <= RightBound);

    return middle + 1;
}


int main()
{
    int arr[] = {1,3,5,6};
    
    int size = (sizeof(arr) / sizeof(arr[0]));

    int index = binarySearch(arr, size, 7);

    return 0;
} 