#include "TIntNumbers.h"
#include "Work_with_numbers.h"

int main()
{
	int m, n, up, down;

	cout << "Enter the amount of binary numbers m: ";
	input(m, down, up);

	TIntNumber* BinaryArr = GenerateRandomBinNumbers(m, up, down);
	cout << endl << "Randomly generated binary numbers:" <<  endl;
	PrintArray(BinaryArr, m);

	cout << "Enter the amount of hex numbers n: "; 
	input(n, down, up);

	TIntNumber* HexArr = GenerateRandomHexNumbers(n, up, down);
	cout << endl << "Randomly generated hex numbers:" << endl;
	PrintArray(HexArr, n);

	cout << "Those numbers in decimal system:" << endl<<endl;

	cout << "Binary array into decimal:" << endl;
	PrintArrayDec(BinaryArr, m);
	cout << "Hex array into decimal:" << endl;
	PrintArrayDec(HexArr, n);
	cout << "___________________________________" << endl;

	cout << "Incremented and Decremented numbers:" << endl << endl;
	IncrementAndDecrement(BinaryArr, HexArr, m, n);

	cout << "Those numbers in decimal system:" << endl << endl;

	cout << "Binary array into decimal:" << endl;
	PrintArrayDec(BinaryArr, m);
	cout << "Hex array into decimal:" << endl;
	PrintArrayDec(HexArr, n);
	cout << "___________________________________" << endl;

	cout<<"The biggest number in decimal system: "<< FindTheBiggestDecNumber(BinaryArr, HexArr, m, n)<<endl<<endl;

	vector <string> numbers = IndexesOfBiggest(BinaryArr, HexArr, m, n);
	cout << "Searched number in its system/s:" << endl<<endl;
	for (size_t i = 0; i < numbers.size(); i+=2)
	{
		cout << numbers[i] << " is the biggest number and it was written in " << numbers[i + 1] << " system"<<endl;
	}

	return 0;
}
