#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
{
    if (image.empty())
        return image;

    for (int i = 0; i < image.size(); i++)
    {
        int size = image[i].size();

        for (int j = 0; j < size / 2; j++) // flipping
        {
            swap(image[i][j], image[i][size - j - 1]);
        }
        for (int j = 0; j < size; j++) // invert
        {
            image[i][j] ^= 1 << 0;
        }
    }

    return image;
}

int main()
{
    vector<vector<int>> image = { {1, 1, 0}, { 1, 0, 1 }, { 0, 0, 0 } };

    vector<vector<int>> answer = flipAndInvertImage(image);

    return 0;
}
