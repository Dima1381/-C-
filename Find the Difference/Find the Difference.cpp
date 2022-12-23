#include <iostream>
#include <unordered_map>

using namespace std;

char findTheDifference(string s, string t) 
{
    unordered_map<char, int> mp_s;

    for (int i = 0; i < s.length(); i++)
    {
        mp_s[s[i]]++;
    }

    for (int i = 0; i < t.length(); i++)
    {
        if (mp_s.find(t[i]) == mp_s.end())
        {
            return t[i];
        }
    }

    return -1;
}


int main()
{
    string s = "", t = "y";

    char res = findTheDifference(s, t);

    return 0;
}

