#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numUniqueEmails(vector<string>& emails) 
{
    unordered_map<string, int> mp;

    for (int i = 0; i < emails.size(); i++)
    {
        string str = emails[i];
        int pos_rate_sign = str.find('@');

        string local_name = str.substr(0, pos_rate_sign);
        string domain_name = str.substr(pos_rate_sign, str.length() - 1);

        local_name.erase(remove(local_name.begin(), local_name.end(), '.'), local_name.end());

        if (local_name.find('+') != string::npos)
        {
            int pos_plus = local_name.find('+');
            local_name = local_name.substr(0, pos_plus);
        }

        mp[local_name + domain_name]++;
    }

    return mp.size();
}

int main()
{
    vector<string> emails = { "test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com", "testemail+david@lee.tcode.com" };

    int res = numUniqueEmails(emails);

    return 0;
}