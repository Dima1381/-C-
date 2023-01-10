#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
{
	if (nums1.size() == 0 || nums2.size() == 0)
		return nums1; // or exception

	vector<int> v;
	v.reserve(nums1.size());

	unordered_map<int, int> mp_nums2;

	int size_nums2 = nums2.size();
	int size_nums1 = nums1.size();

	for (int i = 0; i < size_nums2; i++)
	{
		mp_nums2[nums2[i]]++;
	}

	unordered_map<int, int>::iterator it;

	for (int i = 0; i < size_nums1; i++)
	{
		it = mp_nums2.find(nums1[i]);
		it++;

		if ((it != mp_nums2.end()) && (it->first > nums1[i] ))
		{
			v.push_back(it->first);
		}
		else
		{
			v.push_back(-1);
		}
	}
	
	return v;
}

int main()
{
	vector<int> nums1 = { 4, 1, 2 }, nums2 = { 1, 3, 4, 2 };

	vector<int> res = nextGreaterElement(nums1, nums2);
	return 0;

}