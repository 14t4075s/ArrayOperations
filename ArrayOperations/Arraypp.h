#pragma once

#include <vector>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <functional>

#define LEFT 0
#define RIGHT 1
/*!class for the array*/
class Arraypp
{
private:
	/**/
	std::vector <double> arr;
public:
	Arraypp();
	Arraypp(std::vector<double> vec);
	Arraypp(const Arraypp &a);
	Arraypp(std::string str);
	Arraypp(std::ifstream& file);

	int getSize();
	void initArray();
	void initArray(double num);
	double getMin();
	double getMax();
	int find(double num);
	double getSum();
	double getAvg();
	double getDeviation();
	void copy(std::vector<double> &vec);
	void makeAbs();
	void shift(int direction);
	int printToFile(std::ofstream& file);
	void sorting(int order);

	friend std::ostream& operator<<(std::ostream& os, const Arraypp& c);
	friend std::istream& operator >> (std::istream& is, Arraypp& c);
	Arraypp operator+(const Arraypp &a);
	Arraypp operator-(const Arraypp &a);
	~Arraypp();
};

