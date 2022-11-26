#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person() = default;
	~Person() = default;

	void Input()
	{
		cout << "Enter full name: ";
		getline(cin >> ws, Full_name);
		cout << "Enter Date of birthday: ";
		cin >> Date_of_Birth;
	}
	void Output()
	{
		cout << "Name : " << Full_name << endl;
		cout << "Date of birthday : " << Date_of_Birth << endl;
	}
private:
	string Full_name;
	string Date_of_Birth;
};

class Student : public Person
{
public:
	Student()
	{
		course = 0;
	}
	double average_rating_student()
	{
		double average = 0.0;
		for (int i = 0; i < 4; i++)
		{
			average += estimates[i];
		}
		return average / 4.0;
	}
	void scholarship_amount()
	{
		for (int i = 0; i < 4; i++)
		{
			if (estimates[i] < 60)
			{
				cout << "Student not receives a scholarship" << endl;
				return;
			}
		}
		double ave = average_rating_student();

		if((ave >= 60) && (ave <= 69))
			cout << "The student receives a basic scholarship(100)" << endl;

		if ((ave >= 70) && (ave <= 79))
			cout << "The student receives a scholarship(110%)" << endl;

		if ((ave >= 80) && (ave <= 89))
			cout << "The student receives a scholarship(120%)" << endl;

		if ((ave >= 90) && (ave <= 100))
			cout << "The student receives a scholarship(130%)" << endl;
	}

	void Input()
	{
		Person::Input();
		
		for (int i = 0; i < 4; i++)
		{
			cout << "Enter rating [ " << i + 1 << " ] : ";
			cin >> estimates[i];
		}
	}
	void Output()
	{
		Person::Output();
		cout << "Average rating = " << average_rating_student() << endl;
		scholarship_amount();
	}

private:
	int estimates[4]{};
	int course;
};

int main()
{
	setlocale(LC_ALL, "Rus");
	
	Student student[5];

	for (int i = 0; i < 5; i++)
	{
		cout << endl;
		student[i].Input();
		cout << endl;
		student[i].Output();
	}

}

