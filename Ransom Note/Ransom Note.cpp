#include <iostream>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) 
{
    unordered_map<char, int> mp_magazine;

    for (int i = 0; i < magazine.length(); i++)
    {
        mp_magazine[magazine[i]]++;
    }

    for (int i = 0; i < ransomNote.length(); i++)
    {
        if (mp_magazine[ransomNote[i]] != 0)
        {
            mp_magazine[ransomNote[i]]--;
        }
        else
        {
            return false;
        }
    }

    return true;
}


int main()
{
    string ransomNote = "aac", magazine = "acab";

    bool res = canConstruct(ransomNote, magazine);

    return 0;
}
