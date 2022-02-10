#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string nameOfFile()
{
	string fileName;
	cout << "enter the name of the file:";
	cin >> fileName;
	return fileName;
}
void input(string name)
{
	string line;
	char mode;
	ofstream fileout;
	cout << "Would you like to append your input? If so, enter a. Otherwise enter w:";
	cin >> mode;
	if (mode == 'a')
		fileout.open(name, ios::app);
	if (mode == 'w')
		fileout.open(name);
	while (mode != 'w' && mode != 'a')
	{
		cout << "Enter correct letter:";
		cin >> mode;
	}
	cout << endl;
	cout << "Enter your text:\n To end the line | press ---> ENTER\n To end the input | press ---> Ctrl + X\n";
	cin.ignore();
	while (1) {
		string line;
		getline(cin, line, '\n');
		if (char(line[0]) == 24)
			break;
		fileout << line << endl;
	}
	fileout.close();
	
}

void changeFile(string name, string newname)
{
	string newtext;
	ifstream filein(name);
	char ch;
	if (!filein.is_open())
	{
		cout << "Cannot open the file!\n";

	}
	else
	{
		while (filein.get(ch))
		{
			if (ch != '1' and ch != '0')
				newtext += ch;
			if (ch == '1')
				newtext += '0';
			if (ch == '0')
				newtext += '1';
		}
	}
	ofstream fileout(newname);
	fileout << newtext;
	filein.close();
	fileout.close();
}
void output(string name)
{
	ifstream file(name);
	string line;
	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl;
	}
	file.close();
	cout << endl;
}
