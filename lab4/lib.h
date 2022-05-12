#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Triangle{
private:

	double vertice_1;
	double vertice_2;
	double vertice_3;

public:

	Triangle(double vertice_1, double vertice_2, double vertice_3);
	Triangle(string line);
	Triangle(Triangle& tr);
	
	double GetVertice1();
	double GetVertice2();
	double GetVertice3();
	double findArea();
	Triangle operator++ ();
	Triangle operator-- ();
	Triangle operator+= (double n);
	Triangle operator-= (double n);
};
vector <string> split(string, char );
bool ifValid(double , double , double );
double max_area(double, double , double, vector <string>&);