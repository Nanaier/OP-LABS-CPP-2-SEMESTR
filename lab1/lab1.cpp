#include "myLib.h"

int main()
{
	string name = nameOfFile();
	input(name);
	cout << "Entered text:\n" << endl;
	output(name);
	string newname = nameOfFile();
	changeFile(name, newname);
	cout << "Changed text:\n" << endl;
	output(newname);
	return 0;
}

