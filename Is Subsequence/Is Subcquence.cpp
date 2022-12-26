#include <iostream>

using namespace std;

bool isSubsequence(string s, string t) 
{
    int index_s = 0;

    for (int i = 0; i < t.length(); i++)
    {
        if (t[i] == s[index_s])
        {
            index_s++;
        }
    }

    int len_s = s.length();

    if (index_s == len_s)
    {
        return true;
    }
    else
    {
        return false;
    }
}


int main()
{
    string s = "aec", t = "abcde";

    bool res = isSubsequence(s, t);

    return 0;
}