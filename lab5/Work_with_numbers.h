#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "TIntNumbers.h"
using namespace std;

TIntNumber* GenarateRandomBinNumbers(int, int, int);
TIntNumber* GenarateRandomHexNumbers(int, int, int);
void PrintArrayDec(TIntNumber*, int);
void PrintArray(TIntNumber*, int);
int FindTheBiggestDecNumber(TIntNumber*, TIntNumber*, int, int);
vector <string> IndexesOfBiggest(TIntNumber*, TIntNumber*, int, int);
void IncrementAndDecrement(TIntNumber*, TIntNumber*, int, int);
void input(int&, int&, int&);