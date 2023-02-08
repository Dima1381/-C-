#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Tic_tac_toe
{
public:
	Tic_tac_toe(int n)
	{
		board.resize(n, vector<char>(n, '0'));
	}

	void create_board();
	void draw_board();
	const bool cheak_win(char val);

private:
	vector<vector<char>> board;
};

void Tic_tac_toe::create_board()
{
	int count_X = (board.size() * board.size()) / 2;
	int size = board.size();
	for (int k = 0; k < count_X; k++)
	{
		int i = rand() % size + 0;
		int j = rand() % size + 0;

		if (board[i][j] == 'X')
			k--;

		else
		board[i][j] = 'X';

	}
}

void Tic_tac_toe::draw_board()
{
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			cout << board[i][j] << "    ";
		}
		cout << endl << endl;
	}
}

const bool Tic_tac_toe::cheak_win(char val)
{
	const int size = board.size();

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < board[i].size(); j++) { // check horizontal
			if (board[i][j] != val) {
				break;
			}
			if ((j + 1) == size) return true;
		}

		for (int j = 0; j < board[i].size(); j++) { // check vertical
			if (board[j][i] != val) {
				break;
			}
			if ((j + 1) == size) return true;
		}
	}
	for (int i = 0; i < size; i++) // the main diagonal
	{
		if (board[i][i] != val) 
			break;

		if ((i + 1) == size) return true;
	}

	for (int i = 0, j = size - 1; j >= 0; i++, j--) // side diagonal
	{
		if (board[i][j] != val) 
			break;
		
		if (j == 0) return true;
	}

	return false;
}

int main() 
{
	srand(time(0));
	int n = 0;

	while (n < 3 || n > 5)
	{
		cout << "Enter board size (3-5) : ";
		cin >> n;
	}

	Tic_tac_toe obj(n);

	obj.create_board();
	obj.draw_board();

	bool win_x = obj.cheak_win('X');
	bool win_0 = obj.cheak_win('0');

	if ((win_0 == false) && (win_x == false) || (win_0 == true) && (win_x == true))
		cout << "Draw";

	else if (win_x == true)
		cout << "X - win";
	else
		cout << "0 - win";

	return 0;
}
