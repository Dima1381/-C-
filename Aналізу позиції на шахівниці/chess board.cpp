#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#define SIZE 8

using namespace std;

class Board
{
public:
    Board()
    {
        for (int i = 0; i < SIZE; i++)
        {
            board[i] = new char[SIZE] {};
        }
        blank_board(board);
    }
    ~Board()
    {
        for (int i = 0; i < SIZE; i++)
        {
            delete[] board[i];
        }
        delete[] board;
    }

    void blank_board(char** board);
    void draw_a_board(char** board);

    char** Get()
    {
        return board;
    }
protected:
    char** board = new char* [SIZE] {};
};


class Filling_board_figures : public Board
{
public:
    Filling_board_figures() = default;
    Filling_board_figures(string filename)
    {
        this->file_name = filename;
    }
    void Reading_figures_from_file(char** board);
    void Figures_processing(string fig, char** board);

private:
    string file_name;
};


class Impact_analysis : public Board
{
public:
    void Analysis_figure_Rook(char** board);
    void Analysis_figure_Knight(char** board);
    void Analysis_figure_Pawn(char** board);
    void Analysis_figure_King(char** board);
    void Analysis_figure_Bishop(char** board);
    void Analysis_figure_Queen(char** board);
};



int main()
{
    setlocale(LC_ALL, "Ukr");
    Filling_board_figures f("positions of figures.txt");
    f.blank_board(f.Get());                  // створення пустої дошки
    f.Reading_figures_from_file(f.Get());    // додавання фігур на дошку, позиції яких визначені в файлі
    f.draw_a_board(f.Get());                 // мацюємо дошку 

    Impact_analysis ia;
    ia.Analysis_figure_Rook(f.Get());       // аналіз фігури "Тура"
    ia.Analysis_figure_Knight(f.Get());     // аналіз фігури "Кінь"
    ia.Analysis_figure_Pawn(f.Get());       // аналіз фігури "Пешка"
    ia.Analysis_figure_King(f.Get());       // аналіз фігури "Король"
    ia.Analysis_figure_Bishop(f.Get());     // аналіз фігури "Слон"
    ia.Analysis_figure_Queen(f.Get());      // аналіз фігури "Королева"

    return 0;
}


void Board::blank_board(char** board)
{
    for (int i = 0; i < SIZE; i++)
    {
        board[i] = new char[SIZE] {};

        for (int j = 0; j < SIZE; j++)
        {
            if ((i + j) % 2 == 0)
                board[i][j] = '1';
            else
                board[i][j] = '0';
        }
    }
}

void Board::draw_a_board(char** board)
{
    cout << "******\t 1 - бiла клiтинка, 0 - чорна клiтинка \t******" << endl;
    cout << "| K - Король, Q - Ферзь, B - Слон, N - Кінь, R - Тура, P - Пешка | " << endl << endl;
    cout << setw(9) << "A" << setw(5) << "B" << setw(5) << "C" << setw(5) << "D" << setw(5) << "E" << setw(5) << "F" << setw(5) << "G" << setw(5) << "H" << endl;
    cout << endl << endl;;
    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << "   ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << setw(5) << board[i][j];
        }
        cout << endl;
        cout << endl;
    }
}


void Filling_board_figures::Reading_figures_from_file(char** board)
{
    ifstream in(file_name);

    string temp;
    if (in.is_open())
    {
        while (getline(in, temp))
        {
            Figures_processing(temp, board);
        }

        in.close();
    }
    else
    {
        cout << "\n Файл з позиціями фігур не відкрито! :(" << endl;
    }
}

void Filling_board_figures::Figures_processing(string fig, char** board)
{
    int px = (fig[0] - '0');
    int py = (fig[1] - '0');
    char figures = fig[3];

    board[px - 1][py - 1] = figures;
}


void Impact_analysis::Analysis_figure_Rook(char** board)
{
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

    cout << "\n\n|-------------------------------------------------------------|" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'R')
            {

                for (int k = 0; k < 8; k++)
                {
                    if ((board[k][j] != '1') && (board[k][j] != '0') || (board[i][j] != 'R'))
                    {
                        if (((i + j) % 2 != 0) && ((k + j) % 2 == 0) || ((i + j) % 2 == 0) && ((k + j) % 2 != 0))
                        {
                            cout << "Тура на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][j] << " ] на позицiї [ " << k + 1 << arr[j] << " ]" << endl;
                        }
                    }
                }

                for (int g = 0; g < 8; g++)
                {
                    if ((board[i][g] != '1') && (board[i][g] != '0') || (board[i][j] != 'R'))
                    {
                        if (((i + j) % 2 != 0) && ((i + g) % 2 == 0) || ((i + j) % 2 == 0) && ((i + g) % 2 != 0))
                        {
                            cout << "Тура на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i][g] << " ] на позицiї [ " << i + 1 << arr[g] << " ]" << endl;
                        }
                    }
                }
            }
        }
    }
}

void Impact_analysis::Analysis_figure_Knight(char** board)// метод полягає у знаходженні коня, та аналізом всіх його ударних позицій (8 позицій)
{
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

    cout << "\n\n|-------------------------------------------------------------|" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'N')
            {
                if ((i > 2) && (j < 7))
                {
                    if ((board[i - 2][j + 1] != '1') && (board[i - 2][j + 1] != '0'))
                    cout << "Кінь на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i - 2][j + 1] << " ] на позицiї [ " << i - 1 << arr[j + 1] << " ]" << endl;
                }
                if ((i > 0) && (j < 6))
                {
                    if ((board[i - 1][j + 2] != '1') && (board[i - 1][j + 2] != '0'))
                        cout << "Кінь на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i - 1][j + 2] << " ] на позицiї [ " << i << arr[j + 2] << " ]" << endl;
                }
                if ((i < 7) && (j < 6))
                {
                    if ((board[i + 1][j + 2] != '1') && (board[i + 1][j + 2] != '0'))
                        cout << "Кінь на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i + 1][j + 2] << " ] на позицiї [ " << i + 2 << arr[j + 2] << " ]" << endl;
                }
                if ((i < 6) && (j < 7))
                {
                    if ((board[i + 2][j + 1] != '1') && (board[i + 2][j + 1] != '0'))
                        cout << "Кінь на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i + 2][j + 1] << " ] на позицiї [ " << i + 3 << arr[j + 1] << " ]" << endl;
                }
                if ((i < 6) && (j > 0))
                {
                    if ((board[i + 2][j - 1] != '1') && (board[i + 2][j - 1] != '0'))
                        cout << "Кінь на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i + 2][j - 1] << " ] на позицiї [ " << i + 3 << arr[j - 1] << " ]" << endl;
                }
                if ((i < 7) && (j > 1))
                {
                    if ((board[i + 1][j - 2] != '1') && (board[i + 1][j - 2] != '0'))
                        cout << "Кінь на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i + 1][j - 2] << " ] на позицiї [ " << i + 2 << arr[j - 2] << " ]" << endl;
                }
                if ((i > 0) && (j > 1))
                {
                    if ((board[i - 1][j - 2] != '1') && (board[i - 1][j - 2] != '0'))
                        cout << "Кінь на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i - 1][j - 2] << " ] на позицiї [ " << i << arr[j - 2] << " ]" << endl;
                }
                if ((i > 1) && (j > 0))
                {
                    if ((board[i - 2][j - 1] != '1') && (board[i - 2][j - 1] != '0'))
                        cout << "Кінь на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i - 2][j - 1] << " ] на позицiї [ " << i - 1 << arr[j - 1] << " ]" << endl;
                }
            }
        }
    }
}

void Impact_analysis::Analysis_figure_Pawn(char** board)
{
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

    cout << "\n\n|-------------------------------------------------------------|" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'P')
            {
                if (((i + j) % 2 == 0) && i > 1) // білі - 1
                {
                    if ((board[i - 1][j] != '1') && board[i - 1][j] != '0')
                        cout << "Пешка на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i - 1][j] << " ] на позицiї [ " << i << arr[j] << " ]" << endl;
                }

                if (((i + j) % 2 != 0) && i < 7) // чорні - 0
                {
                    if ((board[i + 1][j] != '1') && board[i + 1][j] != '0')
                        cout << "Пешка на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i + 1][j] << " ] на позицiї [ " << i  + 2 << arr[j] << " ]" << endl;
                }
            }
        }
    }
}

void Impact_analysis::Analysis_figure_King(char** board)
{
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

    cout << "\n\n|-------------------------------------------------------------|" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'K')
            {
                if (i > 0 && j < 7)
                {
                    if ((board[i - 1][j + 1] != '1') && (board[i - 1][j + 1] != '0') && (board[i - 1][j + 1] != 'K'))
                        cout << "Король на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i - 1][j + 1] << " ] на позицiї [ " << i << arr[j + 1] << " ]" << endl;
                }
                if (j < 7)
                {
                    if ((board[i][j + 1] != '1') && (board[i][j + 1] != '0') && (board[i][j + 1] != 'K'))
                        cout << "Король на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i][j + 1] << " ] на позицiї [ " << i + 1 << arr[j + 1] << " ]" << endl;
                }
                if (i < 7 && j < 7)
                {
                    if ((board[i + 1][j + 1] != '1') && (board[i + 1][j + 1] != '0') && (board[i + 1][j + 1] != 'K'))
                        cout << "Король на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i + 1][j + 1] << " ] на позицiї [ " << i + 2 << arr[j + 1] << " ]" << endl;
                }
                if (i < 7)
                {
                    if ((board[i + 1][j] != '1') && (board[i + 1][j] != '0') && (board[i + 1][j] != 'K'))
                        cout << "Король на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i + 1][j] << " ] на позицiї [ " << i + 2 << arr[j] << " ]" << endl;
                }
                if (i < 7 && j > 0)
                {
                    if ((board[i + 1][j - 1] != '1') && (board[i + 1][j - 1] != '0') && (board[i + 1][j - 1] != 'K'))
                        cout << "Король на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i + 1][j - 1] << " ] на позицiї [ " << i + 2 << arr[j - 1] << " ]" << endl;
                }
                if (j > 0)
                {
                    if ((board[i][j - 1] != '1') && (board[i][j - 1] != '0') && (board[i][j - 1] != 'K'))
                        cout << "Король на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i][j - 1] << " ] на позицiї [ " << i + 1 << arr[j - 1] << " ]" << endl;
                }
                if (i > 0 && j > 0)
                {
                    if ((board[i - 1][j - 1] != '1') && (board[i - 1][j - 1] != '0') && (board[i - 1][j - 1] != 'K'))
                        cout << "Король на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i - 1][j - 1] << " ] на позицiї [ " << i << arr[j - 1] << " ]" << endl;
                }
                if (i > 0)
                {
                    if ((board[i - 1][j] != '1') && (board[i - 1][j] != '0') && (board[i - 1][j] != 'K'))
                        cout << "Король на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i][j + 1] << " ] на позицiї [ " << i << arr[j] << " ]" << endl;
                }
            }
        }
    }
}

void Impact_analysis::Analysis_figure_Bishop(char** board)
{
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

    cout << "\n\n|-------------------------------------------------------------|" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'B')
            {
                for (unsigned int k = i, g = j; ; --k, ++g)            // від слона до правого верхнього кута. 
                {
                    if ((board[k][g] != '0') && (board[k][g] != '1') && ((board[k][g] != 'B') != (board[i][j] != 'B')))
                        cout << "Слон на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][g] << " ] на позицiї [ " << k + 1 << arr[g] << " ]" << endl;

                    if (k == 0 || g == 7)
                        break;
                }

                for (unsigned int k = i, g = j; ; ++k, --g)            // від слона до лівого нижнього кута. 
                {
                    if ((board[k][g] != '0') && (board[k][g] != '1') && ((board[k][g] != 'B') != (board[i][j] != 'B')))
                        cout << "Слон на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][g] << " ] на позицiї [ " << k + 1 << arr[g] << " ]" << endl;

                    if (k == 7 || g == 0)
                        break;
                }

                for (unsigned int k = i, g = j; ; --k, --g)            // від слона до лівого верхнього кута. 
                {
                    if ((board[k][g] != '0') && (board[k][g] != '1') && ((board[k][g] != 'B') != (board[i][j] != 'B')))
                        cout << "Слон на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][g] << " ] на позицiї [ " << k + 1 << arr[g] << " ]" << endl;

                    if (k == 0 || g == 0)
                        break;
                }

                for (unsigned int k = i, g = j; ; ++k, ++g)            // від слона до правого нижнього кута. 
                {
                    if ((board[k][g] != '0') && (board[k][g] != '1') && ((board[k][g] != 'B') != (board[i][j] != 'B')))
                        cout << "Слон на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][g] << " ] на позицiї [ " << k + 1 << arr[g] << " ]" << endl;
                    
                    if (k == 7 || g == 7)
                        break;
                }
            }
        }
    }
}

void Impact_analysis::Analysis_figure_Queen(char** board)
{
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

    cout << "\n\n|-------------------------------------------------------------|" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 'Q')
            {
                for (unsigned int k = i, g = j; ; --k, ++g)            // від Q до правого верхнього кута. 
                {
                    if ((board[k][g] != '0') && (board[k][g] != '1') && ((board[k][g] != 'Q') != (board[i][j] != 'Q')))
                        cout << "Королева на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][g] << " ] на позицiї [ " << k + 1 << arr[g] << " ]" << endl;

                    if (k == 0 || g == 7)
                        break;
                }

                for (unsigned int k = i, g = j; ; ++k, --g)            // від Q до лівого нижнього кута. 
                {
                    if ((board[k][g] != '0') && (board[k][g] != '1') && ((board[k][g] != 'Q') != (board[i][j] != 'Q')))
                        cout << "Королева на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][g] << " ] на позицiї [ " << k + 1 << arr[g] << " ]" << endl;

                    if (k == 7 || g == 0)
                        break;
                }

                for (unsigned int k = i, g = j; ; --k, --g)            // від Q до лівого верхнього кута. 
                {
                    if ((board[k][g] != '0') && (board[k][g] != '1') && ((board[k][g] != 'Q') != (board[i][j] != 'Q')))
                        cout << "Королева на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][g] << " ] на позицiї [ " << k + 1 << arr[g] << " ]" << endl;

                    if (k == 0 || g == 0)
                        break;
                }

                for (unsigned int k = i, g = j; ; ++k, ++g)            // від Q до правого нижнього кута. 
                {
                    if ((board[k][g] != '0') && (board[k][g] != '1') && ((board[k][g] != 'Q') != (board[i][j] != 'Q')))
                        cout << "Королева на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][g] << " ] на позицiї [ " << k + 1 << arr[g] << " ]" << endl;

                    if (k == 7 || g == 7)
                        break;
                }


                for (int k = 0; k < 8; k++)
                {
                    if ((board[k][j] != '1') && (board[k][j] != '0') && ((board[k][j] != 'Q') != (board[i][j] != 'Q')))
                    {
                        if (((i + j) % 2 != 0) && ((k + j) % 2 == 0) || ((i + j) % 2 == 0) && ((k + j) % 2 != 0))
                        {
                            cout << "Королева на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[k][j] << " ] на позицiї [ " << k + 1 << arr[j] << " ]" << endl;
                        }
                    }
                }

                for (int g = 0; g < 8; g++)
                {
                    if ((board[i][g] != '1') && (board[i][g] != '0') && ((board[i][g] != 'Q') != (board[i][j] != 'Q')))
                    {
                        if (((i + j) % 2 != 0) && ((i + g) % 2 == 0) || ((i + j) % 2 == 0) && ((i + g) % 2 != 0))
                        {
                            cout << "Королева на позицiї [ " << i + 1 << arr[j] << " ], б'є фiгуру [ " << board[i][g] << " ] на позицiї [ " << i + 1 << arr[g] << " ]" << endl;
                        }
                    }
                }
            }
        }
    }
}
