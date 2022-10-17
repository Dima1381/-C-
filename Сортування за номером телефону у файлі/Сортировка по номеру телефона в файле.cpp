#include <string>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <vector>
#include <algorithm>

using namespace std;

bool checking_file(string name_file);
void input_file(string name_file);
void sorting_file(string name_file);
void print_file(string name_file);
void menu(string name_file);

int main()
{
    setlocale(LC_ALL, "ua_US.UTF-8");
    string name_file = "";
    cout << "Enter a file name (with .txt format)" << endl;
    getline(cin, name_file);

    bool check = checking_file(name_file);

    if (check)
    {
        menu(name_file);
    }
}

void menu(string name_file)
{
    int menu = -1;
    while (!(menu == 4))
    {
        cout << "[ 1 ] Enter data into a file" << endl;
        cout << "[ 2 ] File sorting" << endl;
        cout << "[ 3 ] File data output" << endl;
        cout << "[ 4 ] Exit" << endl;
        cout << "Select an action:";
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            input_file(name_file);
            break;
        }
        case 2:
        {
            sorting_file(name_file);
            break;
        }
        case 3:
        {
            print_file(name_file);
            break;
        }
        case 4:
        {
            menu = 4;
            break;
        }
        default:
            cout << "There is no such action :(" << endl;
            break;
        }
    }
}

bool checking_file(string name_file)
{
    ifstream in;
    in.open(name_file);
    if (!in.is_open())
    {
        cout << "The file could not be opened :(" << endl;
        return false;
    }
    else
    {
        in.close();
    }
    return true;
}

void input_file(string name_file)
{
    ofstream in;
    in.open(name_file, ofstream::app);
    if (in.is_open())
    {
        int count = 0;
        string line = "";
        cout << "Enter a string:   " << endl;
        cin.ignore();
        getline(cin, line);
        in << line << endl;

        in.close();
    }
}

void print_file(string name_file)
{
    string temp = "";
    ifstream file(name_file);

    if (file.is_open()) 
    {
        cout << endl;
        while (getline(file, temp))
        {
            cout << temp << endl;
            temp = "";
        }
        cout << endl;
        file.close();
    }
}

void sorting_file(string name_file)
{
    vector <string> short_list;

    string temp;
    ifstream file(name_file);
    if (file.is_open()) 
    {
        while (getline(file, temp)) 
        {
            short_list.push_back(temp);
        }
        file.close();

        sort(short_list.begin(), short_list.end());

        ofstream fout(name_file);

        for (int i = 0; i < short_list.size(); i++)
        {
            fout << short_list[i] << endl;
        }

        cout << "File sorted!" << endl;
        fout.close();
    }
}
