#include <iostream>

using namespace std;

bool judgeCircle(string moves) 
{
	if (moves.empty())
		return true;

	int x = 0;
	int y = 0;

	int len = moves.length();

	for (int i = 0; i < len; i++)
	{
		if (moves[i] == 'R') x++;

		else if (moves[i] == 'L') x--;

		else if (moves[i] == 'U') y++;

		else if (moves[i] == 'D') y--;
	}
	

	if ((x == 0) && (y == 0))
		return true;
	else
		return false;
}


int main()
{
	string moves = "UD";

	bool res = judgeCircle(moves);

	return 0;
}
