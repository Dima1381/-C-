#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool containsDuplicate(vector<int>& nums) 
{
    unordered_set<int> s;

    for (int i = 0; i < nums.size(); i++)
    {
        if (s.find(nums[i]) == s.end())
        {
            s.insert(nums[i]);
        }
        else
        {
            return true;
        }
    }
    return false;

}

int main()
{
    vector<int> v{ 1,2,3,1 };

    bool contains = containsDuplicate(v);

    return 0;
}
