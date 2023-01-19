#include <iostream>
#include <vector>


using namespace std;

int maximumProduct(vector<int>& nums) 
{
	if (nums.size() < 3)
	{
		return 0;
	}

	int size = nums.size() - 2;

	int max = 0;

	for (int i = 0; i < size; i++)
	{
		int temp = (nums[i] * nums[i + 1] * nums[i + 2]);

		if (temp > max)
			max = temp;
	}

	return max;
}

int main()
{
 
    vector<int> nums { 1,2,3,2,0,2,0 };

    int res = maximumProduct(nums);

	return 0;
}
