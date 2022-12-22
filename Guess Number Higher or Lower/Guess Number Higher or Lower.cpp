#include <iostream>

using namespace std;

class Solution 
{
    int pick;

public:
    Solution(int _pick)
    {
        this->pick = _pick;
    }

    int guessNumber(int n) 
    {
        int left = 0;
        int right = n;
        int middle = 0;

        while (left <= right)
        {
            middle = (left + right) / 2;

            int val = guess(middle);
            if (val == 0)
                return middle;
            if (val == -1)
                right = middle - 1;
            if (val == 1)
                left = middle + 1;
        }

        return n;
    }

    int guess(int num)
    {
        if (num > pick)
            return -1;

        else if (num < pick)
            return 1;

        return 0;
    }
};


int main()
{
    Solution obj(6);
    obj.guessNumber(10);

    return 0;
}
