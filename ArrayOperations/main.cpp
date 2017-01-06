#include "Arraypp.h"
#include <iostream>
using namespace std;

int main()
{
	ifstream file("data.txt");
	ofstream file2("output.txt");
	char t;
	int size;
	Arraypp table(file);
	Arraypp table2("23 75 9 -24 67 -17 54 89 -8 3 14");
	vector<double> test;
	cout << table << endl;
	table.shift(0, 5);
	cout <<"Array after 5 left shift : " << table << endl;
	table.shift(1, 2);
	cout << "Array after 2 right shift : " << table << endl;
	table.makeAbs();
	cout << "Array after absolute value : " << table << endl;
	table.sorting(0);
	cout << "Array after ascending sort: " << table << endl;
	table.sorting(1);
	cout << "Array after descending sort: " << table << endl;
	cout << "Deviation: " << table.getDeviation() << "\tAverage: "<< table.getAvg() << "\tMax: "<< table.getMax() << "\tMin: " << table.getMin() << "\tSum: " << table.getSum() << endl;
	cout << "Addition: " << table + table2 << endl;
	cout << "Substraction: " << table - table2 << endl;
	table.printToFile(file2);
	table.copy(test);
	cout << "23 is at the position :" << table.find(23) << endl;
	size = table.getSize();
	for (size_t i = 0; i < size; i++)
	{
		cout << test[i] << " ";
	}
	cout << endl;
	Arraypp userArray;
	cout << "enter array data : ";
	cin >> userArray;
	cout << userArray << endl;
	cin >> t;
	return 0;
}