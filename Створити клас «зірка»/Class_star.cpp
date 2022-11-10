#include <iostream>

using namespace std;


class Star
{
private:
    double a;
    double b;
    double Area;

public:

    Star()
    {
        a = 0;
        b = 0;
        Area = 0;
    }
    Star(int parameters1, int parameters2)
    {
        a = parameters1;
        b = parameters2;
    }
    void Setsize(); // метод встановлення значень
    void Getsize(); // метод повернення значень

    double area(double a, double b)
    {
        Area = a * b;
        return Area;
    }

    void print_sqrt()
    {
        Star::Getsize();
        Area = area(a, b);
        cout << "Площа цiєї фiгури = " << Area;
    }

    friend ostream& operator<< (ostream& out, const Star& star);
    Star operator+(Star& star);
    Star operator++(int);
};


ostream& operator<< (ostream& out, const Star& star)
{
    out << "\n\n[ A = " << star.a << ", B = " << star.b << ", S = " << star.Area << " ] ";

    return out;
}

Star Star::operator+( Star& star) 
{
    Star new_star(a + star.a, b + star.b);
    return new_star;
}

Star Star::operator++(int) 
{
    Star temp = *this;
    a++;
    b++;

    return temp;
}


void Star::Setsize()
{
    cout << "Введiть значання а та b:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
}

void Star::Getsize()
{
    cout << "\nЗначення фiгури: \n";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}


int main()
{
    setlocale(NULL, "Ukr");
    Star a(5, 6), b(6, 7);

    Star c = a + b;

    a = b++;
    c.print_sqrt();
    cout << c;
}