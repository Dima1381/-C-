#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int distributeCandies(vector<int>& candyType) 
{
    if (candyType.empty())
        return 0;

    unordered_map<int, int> mp;

    int max_candies = candyType.size() / 2;

    int size_candy = candyType.size();

    for (int i = 0; i < size_candy; i++)
    {
        mp[candyType[i]]++;
    }

    if (mp.size() >= max_candies)
        return max_candies;
    else
        return mp.size();

}

int main()
{
    vector<int> candies{ 1,1,2,2,3,3 };
    
    int res = distributeCandies(candies);

	return 0;
}
