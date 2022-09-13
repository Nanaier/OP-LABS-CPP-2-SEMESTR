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
	TIntNumber2();
	TIntNumber2(string);
	string DecToBin(int);
	void operator++() override;
	void operator--() override;

};

class TIntNumber16 :public TIntNumber {
public:
	TIntNumber16();
	TIntNumber16(string);
	string DecToHex(int);
	void operator--() override;
	void operator++() override;

};


