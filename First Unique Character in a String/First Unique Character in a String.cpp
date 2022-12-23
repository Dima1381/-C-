#include <iostream>
#include <unordered_map>

using namespace std;

int firstUniqChar(string s) 
{

    unordered_map<char, int> mp_s;

    for (int i = 0; i < s.length(); i++)
    {
        mp_s[s[i]]++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (mp_s[s[i]] == 1)
        {
            return i;
        }
    }

    return -1;
}


int main()
{
    string s = "loveleetcode"; // :)

    int res = firstUniqChar(s);

    return 0;
}

