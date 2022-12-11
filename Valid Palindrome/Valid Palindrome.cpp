#include <iostream>

using namespace std;

bool isPalindrome(string s) 
{
    string str;
    string revers_str;

    char nonwords[] = " .,!?+-{}[]/\t\n_";

    for (size_t i = 0; i < s.length(); i++)
    {
        if (((s[i] >= 'A') && (s[i] <= 'Z')) && (strchr(nonwords, s[i]) == NULL))
        {
            str += (s[i] + 'z' - 'Z'); // or  str += s[i] + 32;
        }
        if (((s[i] >= 'a') && (s[i] <= 'z')) && (strchr(nonwords, s[i]) == NULL))
        {
            str += s[i];
        }
    }

    revers_str = str;

    int len = revers_str.length();

    for (size_t i = 0; i < len / 2; i++)
    {
        swap(revers_str[i], revers_str[len - i - 1]);
    }

    if (str == revers_str)
        return true;
    else
        return false;
}


int main()
{
    string s = "A man, a plan, a canal: Panama";

    bool res = isPalindrome(s);

    return 0;
} 