#include <iostream>

int addDigits(int num)   
{
    if ((num > 0) && (num < 9))
        return num;

    do
    {
        int temp = num;
        num = 0;

        while (temp > 0)
        {
            num += temp % 10;
            temp /= 10;
        }

    } while (num > 10);

    return num;
}

int main()
{
    int n = 38;

    int result = addDigits(n);

    return 0;
}
