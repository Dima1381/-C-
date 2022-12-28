#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) 
{
	vector<int> missing_numbers;

	unordered_map<int, int> mp_nums;

	for (size_t i = 0; i < nums.size(); i++)
	{
		mp_nums[nums[i]]++;
	}
	
	for (size_t i = 1; i <= nums.size(); i++)
	{
		if (mp_nums.find(i) == mp_nums.end())
		{
			missing_numbers.push_back(i);
		}
	}

	return missing_numbers;
}

int main()
{
	vector<int> nums = {4, 3, 2, 7, 2, 2, 3, 1};

	vector<int> res = findDisappearedNumbers(nums);

	return 0;
}


