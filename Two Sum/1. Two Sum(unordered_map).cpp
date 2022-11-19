#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
	vector<int> v{ 1,2,3,4,5,7,8,9,0 };
	unordered_map<int, int> umap;

	int number = 10;

	for (int i = 0; i < v.size(); i++)
	{
		if (umap.count(number - v[i]))
		{
			cout << "[ " << i << ", " << umap[number - v[i]] << " ]" << endl;;
			
		}
		else
		{
			umap[v[i]] = i;
		}
		
	}
}
