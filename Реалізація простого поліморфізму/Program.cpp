#include <iostream>
#define PI 3.145

using namespace std;

class ball
{

public:
	virtual ~ball() = default;
	virtual void volume() = 0;
};

class truncated_straight_cone : public ball
{
public:
	truncated_straight_cone()
	{
		R = 0;
		r = 0;
		h = 0;
		V = 0;
	}
	truncated_straight_cone(double _R, double _r, double _h) :
		truncated_straight_cone()
	{
		this->R = _R;
		this->r = _r;
		this->h = _h;
	}
	~truncated_straight_cone() = default;

	void volume()
	{
		V = ((1.0 / 3.0) * PI * h * ((pow(R, 2) + R * r + pow(r, 2))));
		cout << "Об'єм усіченого прямого конуса (V) = " << V << endl;
		cout << endl;
	}

private:
	double R; // outer base radius
	double r; // inner base radius
	double h; // cone height
	double V; // result
};

class geometric_body : public ball
{

public:
	geometric_body()
	{
		S = 0;
		h = 0;
		V = 0;
	}
	geometric_body(double _h, double _S) : 
		geometric_body()
	{
		this->S = _S;
		this->h = _h;
	}
	~geometric_body() = default;

	void volume()
	{
		V = (1.0 / 3.0) * S * h;
		cout << "Об'єм геометричного тіла (V) = " << V <<  endl;
		cout << endl;
	}

private:
	double h; // height
	double S; // area
	double V; // result
};

class cone : public ball
{
public:
	cone()
	{
		h = 0;
		R = 0;
		V = 0;
	}
	cone(double _h, double _R) :
		cone()
	{
		this->h = _h;
		this->R = _R;
	}
	~cone() = default;

	void volume()
	{
		V = (1.0 / 3.0) * PI * pow(R, 2) * h;
		cout << "Об'єм конуса (V) = "<< V << endl;
		cout << endl;
	}

private:
	double h;
	double R;
	double V; // result
};

int main()
{
	setlocale(LC_ALL, "Ukr");

	ball* b[3];
	truncated_straight_cone tsc(35.6, 20.2, 15.0);
	geometric_body gb(10.3, 25.0);
	cone c(8.1, 18.0);

	b[0] = &tsc;
	b[1] = &gb;
	b[2] = &c;

	for (int i = 0; i < 3; i++)
	{
		b[i]->volume();
	}
}


  
