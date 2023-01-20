#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) 
{
	vector<int> res;

	map<int, int> mp;

	int size = nums.size();

	for (int i = 0; i < size; i++)
	{
		mp[nums[i]]++;
	}

	int missingNum = -1;
	int duplicateNum = -1;

	for (int i = 0; i < size ; i++)
	{
		if (mp[i] == 0)
			missingNum = i;

		if (mp[i] == 2)
			duplicateNum = i;

	}

	res.push_back(duplicateNum);
	res.push_back(missingNum);

	return res;
}


int main()
{
    vector<int> nums { 1,1 };

    vector<int> res = findErrorNums(nums);

	return 0;
}
