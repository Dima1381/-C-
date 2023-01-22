#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums)
{
	if (nums.empty())
		return 0;

	int increasing_sub = 0;
	int temp_sub = 1;

	int size = nums.size();

	for (int i = 0; i < size - 1; i++)
	{
		if (nums[i] < nums[i + 1])
		{
			temp_sub++;
		}
		else
		{
			if (temp_sub > increasing_sub)
				increasing_sub = temp_sub;

			temp_sub = 1;
		}
	}

	if (temp_sub > increasing_sub)
		increasing_sub = temp_sub;

	return increasing_sub;
}

int main()
{
	vector<int> nums{ 1,3,5,7 };

	int res = findLengthOfLCIS(nums);

	return 0;
}
