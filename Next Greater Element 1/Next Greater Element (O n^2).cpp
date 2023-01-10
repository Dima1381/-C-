#include <iostream>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
{
	if (nums1.size() == 0 || nums2.size() == 0)
		return nums1; // or exception

	vector<int> v;
	v.reserve(nums1.size());

	int size_nums2 = nums2.size();
	int size_nums1 = nums1.size();

	for (int i = 0; i < size_nums1; i++)
	{
		for (int j = 0; j < size_nums2; j++)
		{
			if (nums1[i] == nums2[j])
			{
				if (((j + 1) != size_nums2) && (nums2[j + 1]) > nums1[i])
				{

					v.push_back(nums2[j + 1]);
				}
				else
				{
					v.push_back(-1);
				}
				break;
			}

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
