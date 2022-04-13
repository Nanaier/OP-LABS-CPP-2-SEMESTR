#include "myLib.h"

struct TeleProg {
	string nameOfProgram, text;
	int	startTimeHours, startTimeMinutes, endTimeHours, endTimeMinutes, lengthOfProgram;
	TeleProg(string line) {
		text = line + '\n';
		vector <string> parts = split(line, ' ');
		nameOfProgram = parts[0];
		startTimeHours = stoi(split(parts[1], ':')[0]);
		startTimeMinutes = stoi(split(parts[1], ':')[1]);
		endTimeHours = stoi(split(parts[2], ':')[0]);
		endTimeMinutes = stoi(split(parts[2], ':')[1]);
		lengthOfProgram = (endTimeHours*60 + endTimeMinutes) - (startTimeHours* 60 + startTimeMinutes);
	}
};

vector <string> split(string line, char del)
{
	string str = "";
	vector <string> parts;
	line += del;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == del) {
			if (str.length() > 0) {
				parts.push_back(str);
			}
			str = "";
		}
		else {
			str += line[i];
		}
	}
	return parts;
}
string nameOfFile()
{
	string fileName;
	cout << "enter the name of the file:";
	cin >> fileName;
	return fileName;
}

bool isInBase(TeleProg prog, vector <TeleProg> base) {
	for (int i = 0; i < base.size(); i++) {
		if (base[i].nameOfProgram == prog.nameOfProgram) return true;
		else if ((base[i].endTimeHours*60 + base[i].endTimeMinutes > prog.endTimeHours*60 + prog.endTimeMinutes) && (prog.endTimeHours * 60 + prog.endTimeMinutes > base[i].startTimeHours*60 + base[i].startTimeMinutes ))
			return true;
		else if ((prog.startTimeHours*60 + prog.startTimeMinutes < base[i].startTimeHours * 60 + base[i].startTimeMinutes) && (prog.endTimeHours * 60 + prog.endTimeMinutes > base[i].endTimeHours * 60 + base[i].endTimeMinutes))
			return true;
		else if ((base[i].startTimeHours * 60 + base[i].startTimeMinutes < prog.startTimeHours * 60 + prog.startTimeMinutes) && (prog.startTimeHours * 60 + prog.startTimeMinutes < base[i].endTimeHours * 60 + base[i].endTimeMinutes))
			return true;
	}
	return false;
}

void create(string name)
{
	char mode;
	ifstream fileif;
	vector <TeleProg> base;
	string text = "";
	cout << "Would you like to append your input? If so, enter a. Otherwise enter w:";
	cin >> mode;
	while (true) {
		if (mode == 'a'){
			fileif.open(name, ios::binary);
			char letter;
			while (fileif.read((char*)&letter, sizeof(char)))
			{
				if (letter == '\n') {
					base.push_back(TeleProg(text));
					text = "";
				}
				else text += letter;
			}
			fileif.close();
			break;
		}

		else if (mode == 'w')
			break;
		while (mode != 'w' && mode != 'a')
		{
			cout << "Enter correct letter:";
			cin >> mode;
		}
	}
	ofstream fileout(name, ios::binary);
	string line = "";
	cout << "Enter the input data as [name h:m h:m]\n To end the line | press ---> ENTER\n To end the input | press ---> Ctrl + X\n";
	cin.ignore();
	getline(cin, line);
	while (line[0] != 24)
	{
		TeleProg program(line);
		if (base.size() == 0)
		{
			base.push_back(program);
			getline(cin, line);
			continue;
		}
		if (!isInBase(program, base))
		{
			base.push_back(program);
		}
		else
			cout << "Enter not repeating name or not overlapping time" << endl;
		getline(cin, line);
	}

	for (int i = 0; i < base.size(); i++) {
		fileout.write(base[i].text.c_str(), base[i].text.length());
	}
		
	fileout.close();
}

void output(string name)
{

	ifstream filein(name, ios::binary);
	char letter;
	while (filein.read((char*)&letter, sizeof(char)))
	{
		cout << letter;
	}

	cout << "___________________________________" << endl;
	filein.close();
}

void new_list(string name)
{
	
	ifstream filein(name, ios::binary);
	char letter;
	string line = "";
	while (filein.read((char*)&letter, sizeof(char)))
	{
		if (letter == '\n') {
			TeleProg program(line);
			cout << "the name: " << program.nameOfProgram << "| " << "the length: " << program.lengthOfProgram/60 << " hours and " << program.lengthOfProgram%60 << " minutes" << endl;
			line = "";
		}
		else line += letter;
		
	}
	cout << "___________________________________" << endl;
	filein.close();

}

void newfile(string name)
{
	ifstream filein(name, ios::binary);
	ofstream fileout("output.txt", ios::binary);
	vector <TeleProg> base;
	string line = "";
	char letter;
	while (filein.read((char*)&letter, sizeof(char)))
	{
		if (letter == '\n') {
			TeleProg program(line);
			if ((program.startTimeHours >= 9) && ((program.endTimeHours < 18) || (program.endTimeHours == 18 && program.endTimeMinutes == 0))){
				base.push_back(program);
			}
			line = "";
		}
		else line += letter;
	}
	for (int i = 0; i < base.size(); i++) {
		fileout.write(base[i].text.c_str(), base[i].text.length());
	}
	filein.close();
	fileout.close();


}
