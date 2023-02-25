#include <iostream>
#include <string>

using namespace std;

bool rotateString(string s, string goal) 
{
    if ((s.length() != goal.length()) || s.length() == 0)
        return false;

    int len_s = s.length();

    for (int i = 0; i < len_s; i++)
    {
        char first_symbol = s[0];
        int j = 0;

        for (j; j < len_s - 1; j++)
        {
            s[j] = s[j + 1];
        }
        s[j] = first_symbol;

        if (s == goal)
            return true;

    }
    return false;
}

int main()
{
    string s = "abcde", goal = "cdeab";

    bool res = rotateString(s, goal);
    return 0;
}