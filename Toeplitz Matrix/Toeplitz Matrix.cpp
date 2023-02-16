#include <iostream>
#include <vector>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) 
{
    if (matrix.size() == 1 || matrix[0].size() == 1)
        return true;

    const int ROW = matrix.size() - 1;
    const int COL = matrix[0].size() - 1;

    for (int i = ROW - 1; i >= 0; i--) // diagonals located below the main diagonal inclusively
    {
        const int value = matrix[i][0];
        for (int r = i, c = 0; r < ROW; r++, c++)
        {
            if (r >= ROW || c >= COL)
                break;
            if (matrix[r][c] != matrix[r + 1][c + 1])
            {
                return false;
            }
        }
    }

    for (int i = 1; i < COL; i++) // Diagonals that are above the main one
    {
        const int value = matrix[0][i];
        
        for (int r = i, c = 0; r < COL; r++, c++)
        {
            if (c >= ROW || r >= COL)
                break;

            if (matrix[c][r] != matrix[c + 1][r + 1])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    vector<vector<int>> matrix = { {97, 97}, 
                                   {80, 97},
                                   {10, 80}  };

    bool res = isToeplitzMatrix(matrix);

    return 0;
}