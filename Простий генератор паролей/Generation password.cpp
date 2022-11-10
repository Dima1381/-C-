// Generation password.cpp 
//
#define SIZE_PASSWORD 10

#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));

    const char All_symbols[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVMXYZ0123456789!@#$%&";

    char password[SIZE_PASSWORD];

    for (int i = 0; i < SIZE_PASSWORD; i++)
    {
        password[i] = All_symbols[rand() % 61]; // 62 symbols
    }

    cout << "Your password : ";
    for (int i = 0; i < SIZE_PASSWORD; i++)
    {
        cout << password[i];

    }
}
