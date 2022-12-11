#include <iostream>
#include <vector>
#include <map>

using namespace std;

int majorityElement(vector<int>& nums)
{
    map<int, int> mp;
    int n = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto x: mp)
    {
        if (x.second > (n / 2))
        {
            return x.first;
        }
    }

    return -1;
}


int main()
{
    vector<int> v{ 3,2,3};

    int single = majorityElement(v);

    return 0;
} 