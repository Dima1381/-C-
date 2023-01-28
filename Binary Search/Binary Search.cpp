#include <iostream>
#include <vector>

using namespace std;

int search(const vector<int>& nums, const int target) 
{
	int size = nums.size();
	int leftBound = 0, rightBound = size - 1;

	while (leftBound <= rightBound)
	{
		int middle = (leftBound + rightBound) / 2;

		if (target == nums[middle])
			return middle;

		else if (target > nums[middle])
			leftBound = middle + 1;

		else if (target < nums[middle])
			rightBound = middle - 1;
	}
	return -1;
}

int main() 
{
	vector<int> nums = { -1, 0, 3, 5, 9, 12 };
	int target = 9;

	search(nums, target);

	return 0;
}
