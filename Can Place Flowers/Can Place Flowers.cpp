#include <iostream>
#include <vector>


using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
    int flowers = n;

	int size = flowerbed.size();

	for (int i = 0; i < size; i++)
	{
		if ((i == 0) && (flowerbed[i + 1] == 0) && (flowerbed[i] == 0)) // beginning flowerdad
		{
			flowerbed[i] = 1;
			flowers--;
		}

		else if (((i != 0) && (i < size -1)) && 
			((flowerbed[i - 1] == 0) && ((flowerbed[i + 1]) == 0) && (flowerbed[i] == 0))) // middle flowerded
		{
			flowerbed[i] = 1;
			flowers--;
		}

		else if ((i == size - 1) && (flowerbed[i - 1] == 0) && (flowerbed[i] == 0)) // end flowerded
		{
			flowerbed[i] = 1;
			flowers--;
		}
	}

	if (flowers == 0)
		return true;
	else
		return false;
}

int main()
{
 
    vector<int> flowerbed{ 1,0,0,0,1, 0, 0, 0, 1 };

    bool res = canPlaceFlowers(flowerbed, 2);


	return 0;
}