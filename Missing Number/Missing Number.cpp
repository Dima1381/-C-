#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int missingNumber(vector<int>& nums) 
{
    if (nums.size() == 1)
        return nums[0];

    sort(nums.begin(), nums.end());

    int missing = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        if ((nums[i - 1] + 1) != nums[i] )
        {
            missing = (nums[i - 1] + 1);
        }
        else
        {
            missing = (nums[i] + 1);
        }
    }

    return missing;
}

int main()
{
    vector<int> nums{ 1, 2, 3, 4, 5,7,8, 9,11};

    int result = missingNumber(nums);

    return 0;
}
