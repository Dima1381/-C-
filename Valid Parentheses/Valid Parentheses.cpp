#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) 
{
    stack<char> stack;

    for (int i = 0; i < s.length(); i++)
    {
        if (stack.empty())
            stack.push(s[i]);

        else if (s[i] == ')')
        {
            if (stack.top() != '(')
                return false;
            else
                stack.pop();
        }
        else if (s[i] == '}')
        {
            if (stack.top() != '{')
                return false;
            else
                stack.pop();
        }
        else if (s[i] == ']')
        {
            if (stack.top() != '[')
                return false;
            else
                stack.pop();
        }
        else
            stack.push(s[i]);
    }
    if (stack.empty())
        return true;
    else
        return false;

}
int main()
{
    setlocale(LC_ALL, "Ukr");

    string s = "(){}[]";

    cout << isValid(s);
}