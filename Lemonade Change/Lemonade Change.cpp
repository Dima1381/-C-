#include<iostream>
#include <vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) 
{
    int Fives = 0, Tens = 0;

    int queue = bills.size();

    for (int i = 0; i < queue; i++)
    {
        if (bills[i] == 5)
            Fives++;

        else if (bills[i] == 10)
        {
            if (Fives >= 1)
            {
                Fives--;
                Tens++;
            }
            else
                return false;
        }

        else if (bills[i] == 20)
        {
            if (Tens >= 1 || Fives >= 3)
            {
                if (Tens >= 1 && Fives >= 1)
                {
                    Tens--;
                    Fives--;
                }
                else if (Fives >= 3)
                {
                    Fives -= 3;
                }
                else
                    return false;
            }
            else
                return false;
        }
    }

    return true;
}

int main()
{
    vector<int> bills = { 5,5,5,10,5,5,10,20,20,20 };

    bool answer = lemonadeChange(bills);

    return 0;
}