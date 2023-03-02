#include <iostream>


using namespace std;

void Result(const int player1, const int player2);
void draw_a_cube(const int x);

int main()
{
	int res_user = 0;
	int res_computer = 0;

	int first_walker = 0;
	srand(time(NULL));
	
	first_walker = 1 + rand() % (3 - 1); // 1 - computer , 2 - user

	cout << "............\t Welcome to the dice game \t............" << endl;

	for (int i = first_walker, couple = 1; i < first_walker + 8; i++, couple++)
	{
		int dice_number = 0;

		if ((i % 2) == 0)// user
		{
			cout << "...........The user walks..........." << endl;
			cout << "To roll the dice, press any key...";
			cin.get();
			dice_number = 1 + rand() % (7 - 1);;
			draw_a_cube(dice_number);
			res_user += dice_number;
		}
		else // computer
		{
			cout << "...........The computer walks..........." << endl;
			dice_number = 1 + rand() % (7 - 1);;
			draw_a_cube(dice_number);
			res_computer += dice_number;
		}
		if ((couple % 2) == 0)
		{
			cout << "\n\t [   Intermediate result   ]  Computer = " << res_computer << " User = " << res_user << endl;
		}
	}
	Result(res_computer, res_user);
}



void Result(const int computer, const int user)
{
	if (computer > user)
	{
		cout << "\n\n\t!!!!!!!!     The computer won - congratulations :)     !!!!!!!!" << endl;
		cout << "Scored points: User = [ " << user << " ]  Computer = [ " << computer << " ] " << endl;
	}
	else if (user > computer)
	{
		cout << "\n\n\t!!!!!!!!     The user won - congratulations :)     !!!!!!!!" << endl;
		cout << "Scored points: User = [ " << user << " ]  Computer = [ " << computer << " ] " << endl;
	}
	else if (user == computer)
	{
		cout << "\n\n\t!!!!!!!!     The results are the same - a draw, congratulations to both players    !!!!!!!!" << endl;
		cout << "Scored points: User = [ " << user << " ]  Computer = [ " << computer << " ] " << endl;
	}
}

void draw_a_cube(const int x)
{
	switch (x)
	{
	case 1:
	{
		cout << endl;
		cout << "   *****  " << endl;
		cout << " **     ** " << endl;
		cout << "*** [1] ***" << endl;
		cout << " **     ** " << endl;
		cout << "   *****  " << endl;
		break;
	}
	case 2:
	{
		cout << endl;
		cout << "   *****  " << endl;
		cout << " **     ** " << endl;
		cout << "*** [2] ***" << endl;
		cout << " **     ** " << endl;
		cout << "   *****  " << endl;
		break;
	}
	case 3:
	{
		cout << endl;
		cout << "   *****  " << endl;
		cout << " **     ** " << endl;
		cout << "*** [3] ***" << endl;
		cout << " **     ** " << endl;
		cout << "   *****  " << endl;
		break;
	}
	case 4:
	{
		cout << endl;
		cout << "   *****  " << endl;
		cout << " **     ** " << endl;
		cout << "*** [4] ***" << endl;
		cout << " **     ** " << endl;
		cout << "   *****  " << endl;
		break;
	}
	case 5:
	{
		cout << endl;
		cout << "   *****  " << endl;
		cout << " **     ** " << endl;
		cout << "*** [5] ***" << endl;
		cout << " **     ** " << endl;
		cout << "   *****  " << endl;
		break;
	}
	case 6:
	{
		cout << endl;
		cout << "   *****  " << endl;
		cout << " **     ** " << endl;
		cout << "*** [6] ***" << endl;
		cout << " **     ** " << endl;
		cout << "   *****  " << endl;
		break;
	}
	default:
	{
		cout << endl;
		cout << "   *****  " << endl;
		cout << " **     ** " << endl;
		cout << "*** [ ] ***" << endl;
		cout << " **     ** " << endl;
		cout << "   *****  " << endl;
	}
	break;
	}
}