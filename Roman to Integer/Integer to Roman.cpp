#include <iostream>

using namespace std;


int main()
{

    int number = 3549;
    int num[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };
    string sym[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M" };

    for (int i = 12; number > 0; i--)
    {
        int div = number / num[i];
        number = number % num[i];

        while (div--)
        {
            cout << sym[i];

        }
    }

}
