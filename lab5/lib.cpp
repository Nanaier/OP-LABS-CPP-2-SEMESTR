#include "lib.h"

void TIntNumber::print() {
	cout << this->number<<"  ";
}
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
string TIntNumber16::DecToHex(int num)
{
	string str;
	int temp = (num <= 0 ? (-num) : num);
	while (temp != 0) {
		str = (((temp % 16) < 10) ? char(temp % 16 + 48) : char(temp % 16 + 55)) + str; temp /= 16;
	}
	if (num < 0)
		str = "-" + str;
	if (num == 0)
		str = "0";
	return str;
}
string TIntNumber2::DecToBin(int num) {
	int temp = num;
	string r = "";
	while (num != 0)
	{
		r = (num % 2 == 0 ? "0" : "1") + r; num /= 2;
	}
	if (temp < 0)
		r = "-" + r;
	if (temp == 0)
		r = "0";
	return r;
}
TIntNumber2::TIntNumber2(string num) {
	this->number = num;
	this->base = 2; 
}
TIntNumber16::TIntNumber16(string num) {
	this->number = num;
	this->base = 16;
}
void TIntNumber16::operator--() {
	int new_number = TIntNumberToDecimal();
	new_number--;
	this->number = DecToHex(new_number);
}
void TIntNumber16::operator++() {
	int new_number = TIntNumberToDecimal();
	new_number++;
	this->number = DecToHex(new_number);
}
void TIntNumber2::operator++() {
	int new_number = TIntNumberToDecimal();
	new_number++;
	this->number = DecToBin(new_number);
}
void TIntNumber2::operator--() {
	int new_number = TIntNumberToDecimal();
	new_number--;
	this->number = DecToBin(new_number);
}

int TIntNumber::TIntNumberToDecimal() {
	int new_number = stoi(number, nullptr, base);
	return new_number;
}
TIntNumber2* GenarateRandomBinNumbers(int m, int up, int down) {
	srand(time(NULL));
	TIntNumber2* array = new TIntNumber2[m];
	TIntNumber2 object;
	for (size_t i = 0; i < m; i++)
	{
		object.number = object.DecToBin((rand() % (up - down + 1)) + down);
		array[i] = object;
	}
	return array;
}
TIntNumber16* GenarateRandomHexNumbers(int n, int up, int down) {
	srand(time(NULL));
	TIntNumber16* array = new TIntNumber16[n];
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
