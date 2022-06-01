#include "TIntNumbers.h"

void TIntNumber::print() {
	cout << this->number << "  ";
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