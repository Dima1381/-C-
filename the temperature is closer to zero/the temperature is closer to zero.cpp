#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int res = INT32_MAX;

    int n; 
    cin >> n; cin.ignore();

    if (n == 0)
    {
        res = 0;
        cout << res;
        return 0;
    }

    unordered_map<int, int> mp_t;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t; cin.ignore();
        mp_t[t]++;
        if (abs(t) < abs(res))
        {
            res = t;
        }
    }

    if (mp_t.find(abs(res)) != mp_t.end())
        cout << abs(res);
    else
        cout << res;

    return 0;
}