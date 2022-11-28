#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
    string s[] = { "flowe","flow","flight"};
    int n = sizeof(s) / sizeof(s[0]);
    
    sort(begin(s), end(s));
    
    int i = 0;
    
    for (i = 0; i < s[0].size(); i++)
    {
      	if (s[0][i] != s[n - 1][i])
		break;
    }
	
	cout << s[0].substr(0, i);
}
