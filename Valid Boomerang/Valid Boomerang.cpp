#include <iostream>
#include <vector>

using namespace std;

bool isBoomerang(vector<vector<int>>& points) 
{
	int x1 = points[0][0];
	int y1 = points[0][1];

	int x2 = points[1][0];
	int y2 = points[1][1];

	int x3 = points[2][0];
	int y3 = points[2][1];

	if (((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)) != 0)
		return true;

	return false;

}

int main()
{
	vector<vector<int>> points = { {1, 1}, {2, 3},{3, 2} };

	bool answer = isBoomerang(points);

	return 0;
}
