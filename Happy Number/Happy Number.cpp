#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isHappy(int n) 
{
    unordered_map <int, int> mp;
    int key = 0;

    while (n != 1)
    {
        key = n;

        vector<int> v;

        while (n)
        {
            v.push_back(n % 10);
            n /= 10;
        }

        for (int i = 0; i < v.size(); i++)
        {
            n += pow(v[i], 2);
        }

        if (mp.find(n) != mp.end())
        {
            return false;
        }

        mp[key] = n;
    }

    return true;
}


int main()
{
    int n = 19;

    bool Happy_number = isHappy(n);

    return 0;
} 