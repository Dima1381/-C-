#include <iostream>
#include <vector>
#include <map>

using namespace std;

int thirdMax(vector<int>& nums) 
{
    map<int, int> mp_nums;

    for (int i = 0; i < nums.size(); i++)
    {
        mp_nums[nums[i]]++;
    }

    map<int, int>::iterator it = mp_nums.end();

    if (mp_nums.size() < 3)
    {
        it--;
        return it->first;
    }
    else
    {
        it--;
        it--;
        it--;

        return it->first;
    }
}


int main()
{
    vector<int> nums{ 2,2,3,1,4 };

    int res = thirdMax(nums);

    return 0;
}

