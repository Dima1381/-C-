#include <iostream>
#include <string>
#include <string.h>
#include <windows.h>

using namespace std;

struct Znak
{
private:
    string name;
    string zodiac;
    int arr[3]{0};

public:

    void Setdata(string name, string zodiac, int* arr_birth)
    {
        this->name = name;
        this->zodiac = zodiac;

        for (int i = 0; i < 3; i++)
        {
            this->arr[i] = arr_birth[i];
        }
    }
    int Get_second_element_arr()
    {
        return arr[1];
    }

    void Get_information_person()
    {
        cout << name << endl;
        cout << zodiac << endl;
        cout << arr[0] << "." << arr[1] << "." << arr[2] << endl;
    }

    Znak* input_to_struct();
    void search_by_month(Znak*);
    void sorting(Znak*);
};
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Znak a;

    Znak* ptr = a.input_to_struct();

    a.search_by_month(ptr);
    a.sorting(ptr);

    delete[] ptr;
    return 0;
}

Znak* Znak::input_to_struct()
{
    Znak* book = new Znak[8];
    string name;
    string zodiac;
    
    for (int i = 0; i < 8; i++)
    {
        int data[3]{ 0 };
        cout << "[ " << i + 1 << " ] " << "Please, enter firstand last name through a space : ";
        getline(cin, name);

        cout << "Enter your zodiac sign: ";
        getline(cin, zodiac);

        cout << "Enter the date of birth in the format (dd.mm.yy) :";
        {
            string temp;
            getline(cin, temp);

            int index_data = 0;
            for (int i = 0; i < temp.length(); i++)
            {
                if ((temp[i] != '.'))
                {
                    data[index_data] = (data[index_data] * 10) + (temp[i] - '0');
                }
                else
                {
                    index_data++;
                }
            }
        }
        book[i].Setdata(name, zodiac, data);
    }

    return book;
}


void Znak::search_by_month(Znak *book) 
{
    int month = 0;
    cout << "\nEnter the serial number of the month : ";
    cin >> month;

    bool people_entered_month = true;

    for (int i = 0; i < 8; i++)
    {
        int temp = book[i].Get_second_element_arr();

        if (temp == month)
        {
            cout << endl;
            book[i].Get_information_person();
            people_entered_month = false;
        }
    }
    if (people_entered_month)
    {
        cout << "There are no people born in the month ( " << month << " )" << endl;
    }
  
}

void Znak::sorting(Znak* book)
{
    string temp_name1 = "";
    string temp_name2 = "";

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8 - i - 1; j++)
        {
            temp_name1 = book[j].name;
            temp_name2 = book[j + 1].name;

            if (temp_name1 > temp_name2)
            {
                swap(book[j].name, book[j + 1].name);
                swap(book[j].zodiac, book[j + 1].zodiac);
                
                for (int i = 0; i < 3; i++)
                {
                    swap(book[j].arr[i], book[j + 1].arr[i]);
                }
            }
        }
    }
}