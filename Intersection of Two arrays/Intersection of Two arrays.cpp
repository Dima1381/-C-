include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
{
    unordered_map<int, int> mp1;
    vector<int> result;

    for (int i = 0; i < nums1.size(); i++)
    {
        mp1[nums1[i]]++;
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        if (mp1.erase(nums2[i]))
        {
            result.push_back(nums2[i]);
        }
    }
    return nums2;
}

int main()
{
    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2 };

    intersection(nums1, nums2);

    return 0;
}
