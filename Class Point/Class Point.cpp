#include <iostream>
#include <string>

using namespace std;

class Equilateral_pentagon;

class _Shape
{
public:
    virtual double _Perimeter() = 0; 
    virtual double _Area() = 0;
    virtual void Init() = 0;
};


class Point
{
public:
    double x;
    double y;

    Point()
    {
        this->x = 0.0;
        this->y = 0.0;
    }
    Point(double _x, double _y) : x{ _x }, y{_y}{
    }
};

class Triangle : public _Shape
{
public:
    friend void const larger_area(Triangle&, Equilateral_pentagon&);

    void Init() override
    {
        cout << "\nEnter side A (x, y) : " << endl;
        cin >> p[0].x;
        cin >> p[0].y;
        cout << "Enter side B (x, y) : " << endl;
        cin >> p[1].x;
        cin >> p[1].y;
        cout << "Enter side C (x, y) : " << endl;
        cin >> p[2].x;
        cin >> p[2].y;
    }
    double _Perimeter() override
    {
    /*  a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
        b = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
        c = sqrt((x2 - x1) * (x3 - x2) + (y3 - y2) * (y3 - y2));
        p = a + b + c;*/

        a = sqrt((p[1].x - p[0].x) * (p[1].x - p[0].x) + (p[1].y - p[0].y) * (p[1].y - p[0].y));
        b = sqrt((p[2].x - p[0].x) * (p[2].x - p[0].x) + (p[2].y - p[0].y) * (p[2].y - p[0].y));
        c = sqrt((p[1].x - p[0].x) * (p[2].x - p[1].x) + (p[2].y - p[1].y) * (p[2].y - p[1].y));

        P = a + b + c;

        return P;
    }
    double _Area() override
    {
        /* S = (1/2) * (x1 * y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1)   */

        S = (1.0 / 2.0) * ((p[0].x * p[1].y + p[1].x * p[2].y + p[2].x * p[0].y) -
            (p[0].y * p[1].x + p[1].y * p[2].x + p[2].y * p[0].x));

        return S;
    }
    double Get_Area()
    {
        return S;
    }
private:
    Point p[3];
    double a = 0.0, b = 0.0, c = 0.0, P = 0.0, S = 0.0;
};

class Equilateral_pentagon : public _Shape
{
public:
    friend void const larger_area(Triangle&, Equilateral_pentagon&);

    void Init() override
    {
        cout << "\n\Equilateral pentagon\t" << endl;
        cout << "Enter side (x, y) : " << endl;
        cin >> p[0].x;
        cin >> p[0].y;
    }
    double _Perimeter() override
    {
        /* P = 5*a */
        P = ((5 * p[0].x) + (5 * p[0].y)) / 2;
        return P;
    }
    double _Area() override
    {
        S = (sqrt(25 + 10 * sqrt(5)) / 4) * pow(((p[0].x + p[0].y) / 2), 2);
        return S;
    }

    double Get_Area()
    {
        return S;
    }

private:
    Point p[1];
    double P = 0.0, S = 0.0;
};

class Name
{
private:
    string name;

public:
    string GetName()
    {
        return name;
    }

    void SetName()
    {
        cout << "Enter name figure : ";
        getline(cin >> ws, name);
    }

    void changeName()
    {
        cout << "Enter new name figure : ";
        getline(cin, name);
    }
};

class Name_Shape : public Name, Triangle
{
public:
    void Init(Name& name, Triangle& t)
    {
        double S = 0.0;
        name.SetName();
        S = t.Get_Area();

        cout << "Figure triangle, area: " << S << endl;
    }
};


int main()
{
    Equilateral_pentagon ep;
    Triangle t;
    Name_Shape ns;


    cout << "\t-----Equilateral pentagon-----\t" << endl;
    ep.Init();
    cout << "\nArea = " << ep._Area() << endl;
    cout << "P = " << ep._Perimeter() << endl;

    cout << "\n\t-----Triangle-----\t" << endl;
    t.Init();
    cout << "\nArea = " << t._Area() << endl;
    cout << "P = " << t._Perimeter() << endl;

    larger_area(t, ep);

    ns.Init(ns, t);
}

void const larger_area(Triangle& t, Equilateral_pentagon& ep)
{
    double S_Triangle = t.Get_Area();
    double S_Pentagon = ep.Get_Area();

    if (S_Triangle > S_Pentagon)
    {
        cout << "\nThe area of the triangle is larger = " << S_Triangle << endl;
    }
    else if (S_Triangle < S_Pentagon)
    {
        cout << "\nThe area of the Pentagon is larger = " << S_Pentagon << endl;
    }
    else if (S_Triangle == S_Pentagon)
    {
        cout << "\nThe area of the figures is the same = " << S_Triangle << endl;
    }
}
