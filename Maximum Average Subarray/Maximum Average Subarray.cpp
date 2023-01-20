#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) 
{
	if (k < 1 || (nums.size() < k))
	{
		return 0;
	}

    double max_average = 0;

	for (int i = 0; i < k; i++)
	{
		max_average += nums[i];
	}

	int size = nums.size();

	double window_average = max_average;

	for (int i = k; i < size; i++)
	{
		window_average += nums[i] - nums[i - k];
		max_average = max(max_average, window_average);
	}

	return max_average / k;
}



int main()
{
    vector<int> nums { 1,12,-5,-6,50,3 };

    double res = findMaxAverage(nums, 4);

	return 0;
}
