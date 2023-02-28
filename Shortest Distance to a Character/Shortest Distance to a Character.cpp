#include <iostream>
#include <vector>

using namespace std;

vector<int> shortestToChar(string s, char c) 
{
    int len_s = s.length();
    vector<int> position;
    vector<int> answer;
    int index_pos = 0;

    for (int i = 0; i < len_s; i++)
    {
        if (s[i] == c)
            position.push_back(i);
    }

    for (int i = 0; i < len_s; i++)
    {
        if (position[index_pos] < i && position.size() != 1 && index_pos + 1 != position.size())
            index_pos++;

        if (index_pos == 0)
        {
            answer.push_back(abs(i - position[index_pos]));
        }
        else
        {
            abs(i - position[index_pos]) <= abs(i - position[index_pos - 1]) ? answer.push_back(abs(i - position[index_pos])) : answer.push_back(abs(i - position[index_pos - 1]));
        }
    }

    return answer;
}

int main()
{
    string s = "abba";
    char c = 'b';

    vector<int> res = shortestToChar(s, c);
    return 0;
}
