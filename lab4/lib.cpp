#include "lib.h"

Triangle::Triangle(double vertice_1, double vertice_2, double vertice_3) {
	this->vertice_1 = vertice_1;
	this->vertice_2 = vertice_2;
	this->vertice_3 = vertice_3;
}
Triangle::Triangle(string line){

	vector <string> vertices = split(line, ' ');
	vertice_1 = stod(vertices[0]);
	vertice_2 = stod(vertices[1]);
	vertice_3 = stod(vertices[2]);
}
Triangle::Triangle(Triangle& tr) {
	this->vertice_1 = tr.vertice_1;
	this->vertice_2 = tr.vertice_2;
	this->vertice_3 = tr.vertice_3;
}
double Triangle::GetVertice1() {
	return this->vertice_1;
}
double Triangle::GetVertice2() {
	return this->vertice_2;
}
double Triangle::GetVertice3() {
	return this->vertice_3;
}
double Triangle::findArea() {
	double p = (vertice_1 + vertice_2 + vertice_3) / 2;
	double area = pow(p * (p - vertice_1) * (p - vertice_2) * (p - vertice_3), 0.5);
	return area;
}
Triangle Triangle::operator++ () {
	this->vertice_1++;
	this->vertice_2++;
	this->vertice_3++;
	return *this ;
}
Triangle Triangle::operator-- () {
	this->vertice_1--;
	this->vertice_2--;
	this->vertice_3--;
	return *this;
}
Triangle Triangle::operator+= (double n) {
	this->vertice_1	+= n;
	this->vertice_2 += n;
	this->vertice_3 += n;
	return *this;
}
Triangle Triangle::operator-= (double n) {
	this->vertice_1 -= n;
	this->vertice_2 -= n;
	this->vertice_3 -= n;
	return *this;
}
bool ifValid(double ver_1, double ver_2, double ver_3) {
	if (((ver_1 + ver_2) <= ver_3) || ((ver_2 + ver_3) <= ver_1) || ((ver_1 + ver_3) <= ver_2) || (ver_1<=0) || (ver_2 <= 0)|| (ver_3 <= 0))
		return 0;
	else
		return 1;
}
double max_area(double area_1, double area_2, double area_3, vector <string>& pos) {
	double max;
	if ((area_1 >= area_2) && (area_1 >= area_3)) {
		max = area_1;
		pos.push_back("T1");
	}

	if ((area_2 >= area_1) && (area_2 >= area_3)) {
		max = area_2;
		pos.push_back("T2");
	}
	if ((area_3 >= area_1) && (area_3 >= area_2)) {
		max = area_3;
		pos.push_back("T3");
	}
	return max;
}
vector <string> split(string line, char del) {
	string str = "";
	vector <string> vertices;
	line += del;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == del) {
			if (str.length() > 0) {
				vertices.push_back(str);
			}
			str = "";
		}
		else {
			str += line[i];
		}
	}
	return vertices;
}