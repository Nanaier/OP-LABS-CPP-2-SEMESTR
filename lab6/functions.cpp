#include "functions.h"
#include "tree.h"

void input(string name)
{
	string line;
	char mode;
	ofstream fileout(name);
	cout << "Enter your text:\n To end the line | press ---> ENTER\n To end the input | press ---> Ctrl + X\n";
	while (1) {
		string line;
		getline(cin, line, '\n');
		if (char(line[0]) == 24)
			break;
		fileout << line << endl;
	}
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

void workWithFiles(Tree& tree) {
	ifstream file("input.txt");
	string line;
	int k = 0;
	while (!file.eof())
	{
		getline(file, line);
		if (line.length() != 0) {
			if (line.length() >= 3)
			{
				int found = line.find('"');	int found1 = line.find_last_of('"');
				if ((found != -1) && (found1 != -1) && (found < found1))
					line.erase(found, found1 - found);
			}
			if (line.length() >= 3)
			{
				vector <string> insides;
				int found = line.find('(');	int found1 = line.find_last_of(')');
				if ((found != -1) && (found1 != -1) && (found < found1)) {
					insides = split((line.substr(found, found1 - found)), ' ');
					line.erase(found, found1 - found + 1);
				}
				for (size_t i = 0; i < insides.size(); i++)
				{
					if ((insides[i][insides[i].length() - 1] == ',') && (insides[i].length()>1))
						insides[i].erase(insides[i].length() - 1, 1);

					if (isIndentifier(insides[i]))
						tree.add_node(insides[i], k + 1);
				}
			}
			vector <string> words = split(line, ' ');
			for (int i = 0; i < words.size(); i++)
			{
				if (words[i].length() >= 2)
				{
					if (words[i][words[i].length() - 1] == ';' || words[i][words[i].length() - 1] == ':' 
						|| words[i][words[i].length() - 1] == '}' || words[i][words[i].length() - 1] == '{')
						words[i].erase(words[i].length() - 1, 1);

					if (words[i][words[i].length() - 1] == '*')
						words[i].erase(words[i].length() - 1, 1);

					if ((words[i][0] == '*') || (words[i][0] == '&'))
						words[i].erase(0, 1);

				}
				if (isIndentifier(words[i])) {
					tree.add_node(words[i], k + 1);
				}
				if (words[i].length() >= 3)
				{
					int found = words[i].find('.');
					if (found != -1) {
						vector <string> ins = split(words[i], '.');
						for (size_t i = 0; i < ins.size(); i++)
						{
							if (isIndentifier(ins[i])) {
								tree.add_node(ins[i], k + 1);
							}

						}
					}
				}
			}
			k++;
		}
		else {
			k++;
		}
	}
	file.close();
}

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

bool isKeyWord(string word) {
	vector <string> keyWords = { "int", "long",	"double", "float", "bool", "char", "string", "auto", "void", "class", "short",
	"namespace", "std", "struct", "default", "new", "switch", "and", "delete", "template", "do", "this", "continue",
	"throw", "else", "operator", "true", "enum", "or", "try", "break", "private", "protected", "public","short", "while",
	"if", "for", "cout", "endl", "return", "using", "false", "catch", "override", "virtual", "cin", "srand", "setw", "rand", 
	"unsigned", "size_t"};
	if (find(keyWords.begin(), keyWords.end(), word) != keyWords.end())
		return true;
	else
		return false;
}
bool isIndentifier(string word) {
	if (!isKeyWord(word)) {
		if (!((word[0] >= 'a' && word[0] <= 'z')
			|| (word[0] >= 'A' && word[0] <= 'Z')
			|| word[0] == '_'))
			return false;

		for (int i = 1; i < word.length(); i++) {
			if (!((word[i] >= 'a' && word[i] <= 'z')
				|| (word[i] >= 'A' && word[i] <= 'Z')
				|| (word[i] >= '0' && word[i] <= '9')
				|| word[i] == '_'))
				return false;
		}
		return true;
	}
	else
		return false;
}


