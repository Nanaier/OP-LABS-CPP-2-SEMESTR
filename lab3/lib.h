#pragma once
#include <iostream>;
#include <vector>;
#include <string>;
using namespace std;

class NumArray {
	int size;
	int* array;

public:
	NumArray();
	NumArray(int arraysize) { size = arraysize; };
	~NumArray();
	int maxElement();
	void setContent(int down, int up);
	void outputContent();
};

void range(int&, int&);
int amountOfArrays();
vector <NumArray> create(int, int, int);
void print_max(int, vector <NumArray>);
vector <int> find_min(int, vector <NumArray>, int&);
void output_result(vector <int>, vector <NumArray>, int);

