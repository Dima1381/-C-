#include <iostream>
#include <vector>
#include <map>

using namespace std;

int singleNumber(vector<int>& nums) 
{
    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto x: mp)
    {
        if (x.second == 1)
        {
            return x.first;
        }
    }

    return -1;
}


int main()
{
    vector<int> v{ 1,7,6,4,7,1,4,6 };

    int single = singleNumber(v);

    return 0;
} 