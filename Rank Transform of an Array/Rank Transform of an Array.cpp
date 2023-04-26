#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> arrayRankTransform(vector<int>& arr) 
{
	map<int, int> mp;

	for (auto& num : arr)
	{
		mp[num] = 0;
	}
	int rank = 1;

	for (auto& num : mp)
	{
		num.second = rank++;
	}

	for(int i = 0; i < arr.size(); i++)
	{
		arr[i] = mp[arr[i]];
	}
	return arr;
}

int main()
{
	vector<int> arr = { 40,40, 10, 20, 30 };

    vector<int> answer = arrayRankTransform(arr);

	return 0;
}
