#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) 
{
    int len_p = paragraph.length();

    if (len_p == 0)
        return "";

    for (int i = 0; i < len_p; i++)
    {
        paragraph[i] = ispunct(paragraph[i]) ? ' ' : tolower(paragraph[i]);
    }

    unordered_set<string> b(banned.begin(), banned.end());
    unordered_map<string, int> mp;

    stringstream ss(paragraph);
    string word;

    int count = 0;
    string res;

    while (ss >> word)
{
        if (b.count(word) == 0)
        {
            mp[word]++;

            if (res == "")
            res = word;
        }
    }

    for (auto &w: mp)
    {
        if (w.second > count)
        {
            res = w.first;
            count = w.second;
        }
    }

    return res;
}

int main()
{
    string paragraph = "a.";
    vector<string> banned = {"hit"};
    
    string res = mostCommonWord(paragraph, banned);
    return 0;
}
