#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n) 
{
    vector<int> count_bits;

    count_bits.push_back(0);

    for (int i = 1; i <= n ; i++)
    {
        int temp = i;
        int bits = 0;
        int unit_bits = 0;

        while (temp > 0)
        {
            bits = bits * 10 + (temp % 2);
            temp /= 2;
        }

        while (bits)
        {
            if ((bits % 10) == 1)
            {
                unit_bits++;
            }
            bits /= 10;
        }

        count_bits.push_back(unit_bits);
    }

    return count_bits;
}

int main()
{
    vector<int> res = countBits(5);

    return 0;
}
