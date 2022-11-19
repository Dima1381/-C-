#include <iostream>

using namespace std;

int fid(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return fid(n - 1) + fid(n - 2);
}

int main()
{
    int first = 1, second = 2, result = 0;

    int n = 45;

    cout << 0 << " " <<  1 << " " << 1 << " " << 2 << " ";
    while (1)
    {
        if (first + second < n)
        {
            result = first + second;
            first = second;
            second = result;
            cout << result << " ";
        }
        else
        {
            break;
        }
    }

    return 0;
}
  