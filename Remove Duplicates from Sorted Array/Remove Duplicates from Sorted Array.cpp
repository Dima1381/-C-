#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    int k = 1;
    int i = 0;
    for (int j = 0; j < v.size(); j++)
    {
        if (v[i] != v[j])
        {
            i++;
            v[i] = v[j];
            k++;
        }
    }
    return k;
}

int main() {

    vector<int> v{ 0,1,1,1,2,2,3,3,4 };

    int k = removeDuplicates(v);
    
    for (int i = 0; i < k; i++)
    {
        cout << v[i] << " ";
    }

}