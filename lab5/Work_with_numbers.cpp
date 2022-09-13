#include "Work_with_numbers.h"

void input(int& size, int& down, int& up) {
	cin >> size;
	while (size <= 0 || cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter correct amount: ";
		cin >> size;
	}
	cout << "Enter down limit for generated numbers: ";
	cin >> down;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter correct number: ";
		cin >> down;

	}
	cout << "Enter up limit for generated numbers: ";
	cin >> up;
	while (cin.fail() || up < down)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Enter correct number:";
		cin >> up;

	}
}

TIntNumber* GenerateRandomBinNumbers(int m, int up, int down) {
	srand(time(NULL));
	TIntNumber* array = new TIntNumber2[m];
	TIntNumber2 object;
	for (size_t i = 0; i < m; i++)
	{
		object.number = object.DecToBin((rand() % (up - down + 1)) + down);
		array[i] = object;
	}
	return array;
}

TIntNumber* GenerateRandomHexNumbers(int n, int up, int down) {
	srand(time(NULL));
	TIntNumber* array = new TIntNumber16[n];
	TIntNumber16 object;
	for (size_t i = 0; i < n; i++)
	{
		object.number = object.DecToHex((rand() % (up - down + 1)) + down);
		array[i] = object;
	}
	return array;
}
void IncrementAndDecrement(TIntNumber* a, TIntNumber* b, int m, int n) {
	cout << "Decremented binary numbers:" << endl;
	for (size_t i = 0; i < m; i++)
	{
		--a[i];
		cout << a[i].number << "  ";
	}cout << endl;
	cout << "Incremented hex numbers:" << endl;
	for (size_t i = 0; i < n; i++)
	{
		++b[i];
		cout << b[i].number << "  ";
	}cout << endl;
	cout << "___________________________________" << endl;
}
void PrintArrayDec(TIntNumber* a, int size) {
	
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i].TIntNumberToDecimal() << "  ";
	}cout << endl;
}
void PrintArray(TIntNumber* a, int size) {

	for (size_t i = 0; i < size; i++)
	{
		a[i].print();
	}cout << endl << "___________________________________" << endl << endl;
}
int FindTheBiggestDecNumber(TIntNumber* a, TIntNumber* b, int m, int n) {
	int max = a[0].TIntNumberToDecimal();
	for (size_t i = 0; i < m; i++)
	{
		if (a[i].TIntNumberToDecimal() > max)
			max = a[i].TIntNumberToDecimal();
	}
	for (size_t i = 0; i < n; i++)
	{
		if (b[i].TIntNumberToDecimal() > max)
			max = b[i].TIntNumberToDecimal();
	}
	return max;
}

vector <string> IndexesOfBiggest(TIntNumber* a, TIntNumber* b, int m, int n) {
	vector <string> numbers;
	int max = FindTheBiggestDecNumber(a,b, m, n);
	for (size_t i = 0; i < m; i++)
	{
		if (a[i].TIntNumberToDecimal() == max)
		{
			numbers.push_back(a[i].number);
			numbers.push_back("binary");
			break;
		}
			
	}
	for (size_t i = 0; i < n; i++)
	{
		if (b[i].TIntNumberToDecimal() == max)
		{
			numbers.push_back(b[i].number);
			numbers.push_back("hex");
			break;
		}
	}
	return numbers;
}
