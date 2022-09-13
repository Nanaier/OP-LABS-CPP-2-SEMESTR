#include "tree.h"
#include "functions.h"

int main()
{
	Tree tree;
	input("input.txt");
	//cout << endl << "The output of file:" << endl<<endl;
	//output("input.txt");
	workWithFiles(tree);
	cout << endl << "The searched tree:" << endl << endl;
	tree.print();
	cout << endl;
	vector <int> v = tree.find_lines();
	cout << "Indexes of lines that contain all identifiers: ";
	if (v.size() == 0)
		cout << "none";
	else {
		for (size_t i = 0; i < v.size(); i++)
		{
			if (i != v.size() - 1)
				cout << v[i] << ", ";
			else
				cout << v[i];
		}
	}
	cout << endl;
	return 0;
}
