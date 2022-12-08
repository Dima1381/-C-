#include <iostream>
#include <vector>

using namespace std;

unsigned int climbStairs(const int n)
{
    if (n <= 2)
        return n;
    
    vector<unsigned int> v(n + 1);

    v[0] = 0;
    v[1] = 1;
    v[2] = 1;

    for (int i = 3; i <= n ; i++)
    {
        v[i] = v[i - 1] + v[i - 2];
    }
    
    return v[n];
}

int main()
{
    int n = 6;

    cout << climbStairs(n);

    return 0;
} 