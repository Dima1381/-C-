#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits)
{
    int len = digits.size();

    if ((len == 1) && digits[0] == 9)
    {
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }

    for (int i = len - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
        {
            digits[i] = 0;

            if (i == 0)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        else
        {
            digits[i] += 1;
            break;
        }
    }

    return digits;
}


int main()
{
    vector<int> v{4,2,1 };

    vector<int> res = plusOne(v);

    for (auto i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    return 0;
} 