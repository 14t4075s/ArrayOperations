#include "Arraypp.h"

using namespace std;

Arraypp::Arraypp()
{
	arr = vector<double>();
}

Arraypp::Arraypp(std::vector<double> vec) : arr(vec)
{
}

Arraypp::Arraypp(const Arraypp & a)
{
	this->arr = a.arr;
}

Arraypp::Arraypp(std::string str): arr(vector<double>())
{
	double num(0);
	std::stringstream ssin(str);
	while (ssin.good())
	{
		ssin >> num;
		arr.push_back(num);
	}
}

Arraypp::Arraypp(std::ifstream& file) : arr(vector<double>())
{
	double num;
	while (!file.eof())
	{
		file >> num;
		arr.push_back(num);
	}
}

int Arraypp::getSize()
{
	return arr.size();
}

void Arraypp::initArray(int size)
{
	arr.clear();
	srand(time(0));
	double randNum(0);
	for (size_t i = 0; i < size; i++)
	{
		randNum = rand() % 100;
		arr.push_back(randNum);
	}
}

void Arraypp::initArray(double num, int size)
{
	arr.clear();
	for (size_t i = 0; i < size; i++)
	{
		arr.push_back(num);
	}
}

double Arraypp::getMin()
{
	double tmp = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] < tmp)
		{
			tmp = arr[i];
		}
	}
	return tmp;
}

double Arraypp::getMax()
{
	double tmp = arr[0];
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] > tmp)
		{
			tmp = arr[i];
		}
	}
	return tmp;
}

int Arraypp::find(double num)
{
	int pos(-1);
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] == num)
		{
			pos = i + 1;
			break;
		}
	}
	return pos;
}

double Arraypp::getSum()
{
	double sum(0);
	for (size_t i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}
	return sum;
}

double Arraypp::getAvg()
{
	double avg(0.0);
	double sum(0);
	for (size_t i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
	}
	avg = sum / arr.size();
	return avg;
}

double Arraypp::getDeviation()
{
	double avg(getAvg());
	double s(0.0);
	double sum(0.0);
	for (size_t i = 0; i < arr.size(); i++)
	{
		sum += pow(arr[i] - avg, 2);
	}
	double num = 1.0 / double(arr.size());
	s = sqrt(num*sum);
	return s;
}

void Arraypp::copy(std::vector<double> &vec)
{
	vec.clear();
	for (size_t i = 0; i < arr.size(); i++)
	{
		vec.push_back(arr[i]);
	}
}



void Arraypp::makeAbs()
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] = abs(arr[i]);
	}
}

void Arraypp::shift(int direction, int times)
{
	if (times <= 0)
	{
		times = 1;
	}
	if (direction == LEFT)
	{
		for (size_t i = 0; i < times; i++)
		{
			std::rotate(arr.begin(), arr.begin() + 1, arr.end());
		}
	}
	else
	{
		for (size_t i = 0; i < times; i++)
		{
			std::rotate(arr.rbegin(), arr.rbegin() + 1, arr.rend());
		}
	}
}

int Arraypp::printToFile(std::ofstream& file)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		file << arr[i] << " ";
	}
	return 0;
}

void Arraypp::sorting(int order)
{
	if (order == 0)
	{
		std::sort(arr.begin(), arr.end());
	}
	else
	{
		std::sort(arr.begin(), arr.end(), std::greater<double>());
	}
}








Arraypp Arraypp::operator+(const Arraypp & a)
{
	vector<double> tmp;
	for (size_t i = 0; i < arr.size(); i++)
	{
		tmp.push_back(arr[i] + a.arr[i]);
	}
	return Arraypp(tmp);
}

Arraypp Arraypp::operator-(const Arraypp & a)
{
	vector<double> tmp;
	for (size_t i = 0; i < arr.size(); i++)
	{
		tmp.push_back(arr[i] - a.arr[i]);
	}
	return Arraypp(tmp);
}

Arraypp::~Arraypp()
{
}

std::ostream & operator<<(std::ostream & os, const Arraypp & c)
{
	os << "[ ";
	for (size_t i = 0; i < c.arr.size(); i++)
	{
		os << c.arr[i] << " ";
	}
	os << "]";
	return os;
}

std::istream & operator >> (std::istream & is, Arraypp & c)
{
	string s;
	getline(is, s);
	double num(0);
	std::stringstream ssin(s);
	c.arr.clear();
	while (ssin.good())
	{
		ssin >> num;
		c.arr.push_back(num);
	}
	return is;
}
