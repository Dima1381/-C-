#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int k = 0;
    if (nums.size() == 0)
        return k;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != val)
        {
            nums[k++] = nums[i];
        }
    }
    return k;
}

int main() {

    vector<int> v{ 0,1,2,2,3,0,4,2};

    int k = removeElement(v, 2);
    for (int i = 0; i < k; i++)
    {
        cout << v[i] << " ";
    }
}