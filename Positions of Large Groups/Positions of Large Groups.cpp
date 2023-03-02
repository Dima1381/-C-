#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> largeGroupPositions(string s) 
{
    int len_s = s.length();
    vector<vector<int>> answer;

    if (len_s == 0)
        return answer;
    int count = 0;

    for (int i = 1; i <= len_s; i++)
    {
        if (s[i] == s[i - 1])
        {
            count++;
        }
        else
        {
            if (count >= 2)
            {
                answer.push_back({i - count - 1, i - 1});
            }
            count = 0;
        }
    }

    return answer;
}

int main()
{
    string s = "abcdddeeeeaabbbcd";
    
    vector<vector<int>> answer = largeGroupPositions(s);

    return 0;
}
