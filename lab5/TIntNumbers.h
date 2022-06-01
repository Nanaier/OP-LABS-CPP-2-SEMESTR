#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;
class TIntNumber {
public:
	string number;
	int base;
public:

	virtual void operator++() = 0;
	virtual void operator--() = 0;

	int TIntNumberToDecimal();

	void print();

};
class TIntNumber2 :public TIntNumber {
public:
	TIntNumber2() { this->number = ""; this->base = 2; };
	TIntNumber2(string num);
	string DecToBin(int num);
	void operator++() override;
	void operator--() override;


};

class TIntNumber16 :public TIntNumber {
public:
	TIntNumber16() { this->number = ""; this->base = 16; };
	TIntNumber16(string num);
	string DecToHex(int num);
	void operator--() override;
	void operator++() override;


};


