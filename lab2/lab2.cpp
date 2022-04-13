#include "myLib.h"

int main()
{
	string name = nameOfFile();
	create(name);
	cout << "List of teleprograms:\n";
	output(name);
	new_list(name);
	newfile(name);
	cout << "List of teleprograms that run in the day time:\n";
	output("output.txt");
	return 0;
}


