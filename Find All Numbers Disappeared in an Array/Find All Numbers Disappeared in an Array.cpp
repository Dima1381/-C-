#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) 
{
	vector<int> missing_numbers;

	int size = nums.size();

	int* temp = new int[size + 1] {0};

	for (int i = 0; i < size; i++)
	{
		temp[nums[i]] = 1;
	}

	for (int i = 1; i <= size; i++)
	{
		if (temp[i] == 0)
		{
			missing_numbers.push_back(i);
		}
	}
	
	delete[] temp;

	return missing_numbers;
}

int main()
{
	vector<int> nums = {4, 3, 2, 7, 2, 2, 3, 1};

	vector<int> res = findDisappearedNumbers(nums);

	return 0;
}

