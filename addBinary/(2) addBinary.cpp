#include <iostream>

using namespace std;

string addBinary(string a, string b) 
{
    string result;
    int Dec_a = 0;
    int Dec_b = 0;

    for (int i = a.length() - 1, k = 0; i >= 0; i--, k++)
    {
        Dec_a += (a[i] - '0') * pow(2, k);
    }

    for (int i = b.length() - 1, k = 0; i >= 0; i--, k++)
    {
        Dec_b += (b[i] - '0') * pow(2, k);
    }

    int Sum_Dec = Dec_a + Dec_b;


    while (Sum_Dec > 0)
    {
        result += (Sum_Dec % 2) + '0';
        Sum_Dec /= 2;
    }

    int len = result.length() - 1;

    for (int i = 0; i < len / 2; i++)
    {
        swap(result[i], result[len - i]);
    }

    return result;
}

int main()
{
    string a = "1010";
    string b = "1011";

    addBinary(a, b);

    return 0;
} 