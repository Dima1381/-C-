#include <iostream>
#include <vector>

using namespace std;

vector<int> sortArrayByParityII(vector<int>& nums) 
{
    vector<int> answer;
    answer.resize(nums.size());

    int k = 0, m = 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (!(nums[i] & 1))
        {
            answer[k] = nums[i];
            k += 2;
        }
        else
        {
            answer[m] = nums[i];
            m += 2;
        }
    }
    return answer;
}

int main()
{
    vector<int> nums = { 4, 2, 5, 7 };
	
    vector<int> answer = sortArrayByParityII(nums);
    return 0;
}