#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numJewelsInStones(string jewels, string stones) 
{
    if (jewels.size() == 0)
        return 0;

    int count = 0;
    unordered_map<char, int> mp_jewels;

    int len_jewels = jewels.size();

    for (int i = 0; i < len_jewels; i++)
    {
        mp_jewels[jewels[i]]++;
    }

    int len_stones = stones.size();

    for (int i = 0; i < len_stones; i++)
    {
        if (mp_jewels.find(stones[i]) != mp_jewels.end())
        {
            count++;
        }
    }
    
    return count;
}

int main()
{
    string jewels = "aA", stones = "aAAbbbb";

    int res = numJewelsInStones(jewels, stones);

    return 0;
}