#include <iostream>

using namespace std;

class My_class
{
private:
    int* arr;
    int number_even;
    int size;

public:
    My_class()
    {
        arr = nullptr;
        number_even = 0;
        size = 0;
    }

    My_class(int size) : My_class()
    {
        arr = new int[size];
        this->size = size;
    }

    My_class(const My_class &other) 
    {
        this->size = other.size;
        this->number_even = other.number_even;
        this->arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            this->arr[i] = other.arr[i];
        }
    }

    void addToArray()
    {
        cout << "Array elements:" << endl;
        for (int i = 0; i < size; i++)
        {
            if ((i % 2) == 0)
            {
                arr[i] = (i - 5);
            }
            else
            {
                arr[i] = i;
            }

            cout << arr[i] << " ";

            if ((arr[i] % 2) == 0)
            {
                number_even++;
            }
        }
        cout << "\n\nNumber of even numbers = " << number_even << endl;
    }

    ~My_class() 
    {
        delete[] arr;
        arr = nullptr;
    }
};

void number_even_elements( My_class obj)
{
    obj.addToArray();
}

int main()
{
    My_class obj(11);
    number_even_elements(obj);
 
    return 0;
}