#include <iostream>
#include <vector>
#include <map>

using namespace std;

void merge(vector<int>& nums1, vector<int>& nums2) 
{
    map<int, int> mp;

    for (int i = 0; i < nums1.size(); i++)
    {
        mp[nums1[i]]++;
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        mp[nums2[i]]++;
    }

    nums1.clear();

    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it)
    {
        for (int i = 0; i < it->second; i++)
        {
            nums1.push_back(it->first);
        }
    }
}


int main()
{
    vector<int> nums1 { 1,3,3 };
    vector<int> nums2 { 2,5,6 };

    merge(nums1, nums2);

    return 0;
} 