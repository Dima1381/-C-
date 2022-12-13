#include <iostream>
#include <unordered_map>

using namespace std;

bool isAnagram(string s, string t) 
{
    unordered_map<char, int> mp_s;

    int len_s = s.length();
    int len_t = t.length();

    if (len_s != len_t)
        return false;

    for (size_t i = 0; i < len_s; i++)
    {
        mp_s[s[i]]++;
    }

    for (int i = 0; i < len_t; i++)
    {
        if (mp_s.find(t[i]) != mp_s.end())
        {
            mp_s[t[i]] -= 1;
        }
        else
        {
            return false;
        }
    }

    for (auto it: mp_s)
    {
        if (it.second != 0)
            return false;

    }
    return true;
}

int main()
{
    string s = "anagram", t = "nagaram";

    bool Anagram = isAnagram(s, t);

    return 0;
}
