#include "lib.h"

int main()
{
	double ver_1 = 0, ver_2 = 0, ver_3 = 0;
	 do{
		cout << "Enter the correct sizes of the vertices you are looking for:\nvertice 1: "; cin >> ver_1;
		cout << "vertice 2: "; cin >> ver_2;
		cout << "vertice 3: "; cin >> ver_3; cout << endl;
	 } while (ifValid(ver_1, ver_2, ver_3) == 0);
	Triangle T1(ver_1, ver_2, ver_3);
	printf("vertices of T1: 1. %.3f; 2. %.3f; 3. %.3f;\n", T1.GetVertice1(), T1.GetVertice2(), T1.GetVertice3());
	cout << "_______________________________________" << endl;


	string line;
	cout << "T2:\nEnter the sizes of the vertices in one line(like this: v1 v2 v3): ";
	cin.ignore();
	getline(cin, line, '\n');
	vector <string> temp = split(line, ' ');
	while ((ifValid(stod(temp[0])-1, stod(temp[1])-1, stod(temp[2])-1) == 0)) {
		cout << "Enter the correct sizes of the vertices in one line(like this: v1 v2 v3): "; 
		cin.clear();
		getline(cin, line, '\n');
		temp = split(line, ' ');
	}
	Triangle T2(line);
	printf("\nvertices of T2: 1. %.3f; 2. %.3f; 3. %.3f;\n\n", T2.GetVertice1(), T2.GetVertice2(), T2.GetVertice3());
	cout << "_______________________________________" << endl;


	cout << "T3:" << endl;
	Triangle T3(T1);
	printf("vertices of T3: 1. %.3f; 2. %.3f; 3. %.3f;\n\n", T3.GetVertice1(), T3.GetVertice2(), T3.GetVertice3());
	cout << "_______________________________________" << endl;

	cout << "Incremintation of T1:\n";
	++T1;
	printf("vertices of T1: 1. %.3f; 2. %.3f; 3. %.3f;\n", T1.GetVertice1(), T1.GetVertice2(), T1.GetVertice3());

	cout<< "Decremintation of T2:\n";
	--T2;
	printf("vertices of T2: 1. %.3f; 2. %.3f; 3. %.3f;\n\n", T2.GetVertice1(), T2.GetVertice2(), T2.GetVertice3());

	cout << "Making T3 bigger by adding value:\n";
	double n = 0;
	do {
		cout << "enter the value: "; cin >> n;
	} while (ifValid(T3.GetVertice1() + n, T3.GetVertice2() + n, T3.GetVertice3() + n) == 0);
	
	T3 += n;
	printf("vertices of T3: 1. %.3f; 2. %.3f; 3. %.3f;\n\n", T3.GetVertice1(), T3.GetVertice2(), T3.GetVertice3());

	cout << "The areas:"<<endl;
	cout << "T1: " << T1.findArea()<<endl;
	cout << "T2: " << T2.findArea()<<endl;
	cout << "T3: " << T3.findArea()<<endl<<endl;
	vector <string> pos;
	cout << "The max area is " << max_area(T1.findArea(), T2.findArea(), T3.findArea(), pos)<< " and it is triangle/s ";
	for (size_t i = 0; i < pos.size(); i++)
	{
		if (i == pos.size() - 1)
			cout << pos[i] << endl;
		else
			cout << pos[i] << ", ";
	}
	
	return 0;
}

