#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums) 
{
	int size = nums.size();

	if (size == 0)
		return -1;

	else if (size == 1)
		return 0;

	int sum_nums = 0;

	for (int i = 0; i < size; i++)
	{
		sum_nums += nums[i];
	}
	
	int leftBorder = 0;
	int rightBorder = sum_nums;

	for (int i = 0; i < size; i++)
	{
		rightBorder = rightBorder - nums[i];
		
		if (leftBorder == rightBorder)
			return i;

		leftBorder += nums[i];
	}

	return -1;
}
int main() 
{
	vector<int> nums{ 1,7,3,6,5,6 };

	int index = pivotIndex(nums);
	return 0;
}
