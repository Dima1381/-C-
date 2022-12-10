#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int index_day_min = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < prices[index_day_min])
        {
            index_day_min = i;
        }
    }

    int index_day_max = index_day_min;

    for (int i = index_day_max + 1; i < prices.size(); i++)
    {
        if (prices[i] > prices[index_day_max])
        {
            index_day_max = i;
        }
    }

    int profit = 0;

    if (index_day_max > index_day_min)
    {
        profit = prices[index_day_max] - prices[index_day_min];
        return profit;
    }
    else
    {
        return profit;
    }
}


int main()
{
    vector<int> prices { 7, 6, 4, 3, 1, 7, 1, 5, 19, 13, 0, 19 };

    int profit = maxProfit(prices);

    return 0;
} 