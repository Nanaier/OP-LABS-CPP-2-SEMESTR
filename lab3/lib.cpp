#include "lib.h"

NumArray::NumArray() {
	size = 0;
	array = NULL;
}

NumArray::~NumArray() {
	array = NULL;
}

void NumArray::setContent(int down, int up) {
	srand(time(NULL));
	array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = (rand() % (up - down + 1) + down);
	}
}
void NumArray::outputContent() {
	cout << " [ ";
	for (size_t i = 0; i < size; i++)
	{
		if (i == size - 1)
			cout << array[i] << " ]" << endl;
		else
			cout << array[i] << ", ";
	}
}
int NumArray::maxElement() {
	int max = array[0];
	for (size_t i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return max;
}
void range(int& down, int& up) {
	cout << "Enter the down limit for random(an integer): ";
	cin >> down;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter correct amount:";
		cin >> down;

	}
	cout << "Enter the up limit for random(an integer): ";
	cin >> up;
	while (cin.fail() || up < down)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter correct amount:";
		cin >> up;

	}
}
int amountOfArrays() {
	int amount;
	cout << "Enter the amount of arrays you want(an integer that is bigger than zero): ";
	cin >> amount;
	while (amount <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter correct amount:";
		cin >> amount;
	}
	return amount;
}
vector <NumArray> create(int amount, int down, int up) {
	int size;
	vector <NumArray> vect;
	cout << "Enter the sizes of those arrays\n " << endl;
	for (size_t i = 0; i < amount; i++)
	{
		cout << "Size: ";
		cin >> size;
		while (size <= 0 || cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Enter correct size: ";
			cin >> size;
		}

		NumArray array(size);
		array.setContent(down, up);
		cout << "Array:";
		array.outputContent();
		cout << endl;


		vect.push_back(array);
		array.~NumArray();
	}
	return vect;
}

void print_max(int amount, vector <NumArray> vect) {
	for (size_t i = 0; i < amount; i++)
	{
		cout << "The array with number " << i + 1 << ":";
		vect[i].outputContent();
		cout << "The max element of array: " << vect[i].maxElement() << endl;
		cout << endl;
	}
}
vector <int> find_min(int amount, vector <NumArray> vect, int& min) {
	vector <int> max_v;
	for (size_t i = 0; i < amount; i++)
	{
		max_v.push_back(vect[i].maxElement());
	}
	min = max_v[0];
	for (size_t i = 0; i < amount; i++)
	{
		if (max_v[i] < min) {
			min = max_v[i];
		}
	}
	return max_v;
}
void output_result(vector <int> max_v, vector <NumArray> vect, int min) {
	cout << "The minimal max element out of all of them: " << min << endl << endl;
	cout << "The array/s with the max element " << min << ":" << endl;
	for (size_t i = 0; i < max_v.size(); i++)
	{
		if (max_v[i] == min) {
			cout << "Array:";
			vect[i].outputContent();
			cout << endl;
		}

	}
}
