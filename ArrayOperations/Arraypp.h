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
/**
*  Arraypp class. This class allows more operations on arrays
*/
class Arraypp
{
private:
	/**
	* member array
	* Dynamic array used to save data
	*/
	std::vector <double> arr;
public:
	/**
	*  constructor.
	* create an empty Arraypp class
	*/
	Arraypp();
	/**
	*  constructor.
	* create a Arraypp object from an existing dynamic array
	*@param vec dynamic array
	*/
	Arraypp(std::vector<double> vec);
	/**
	*  copy constructor.
	* create a Arraypp object from an existing Arraypp object
	*@param a Arraypp
	*/
	Arraypp(const Arraypp &a);
	/**
	* constructor.
	* create a Arraypp object from a string
	*@param str std::string containing array data
	*/
	Arraypp(std::string str);
	/**
	* constructor.
	* create a Arraypp object from an input file stream
	*@param file std::ifstream containing array data
	*/
	Arraypp(std::ifstream& file);

	/**
	* function return the current Array size
	*@return arr.size()
	*/
	int getSize();
	/**
	* function initialize
	* clear the array and initialize it with random numbers
	*@param size int determine the size of the array
	*/
	void initArray( int size = 1);
	/**
	* function initialize
	* clear the array and initialize it with a number
	*@param num double the number used for initialization
	*@param size int determine the size of the array
	*/
	void initArray(double num = 0.0 , int size = 1);
	/**
	* function used to get minimum
	*@return smallest number in the array
	*/
	double getMin();
	/**
	* function used to get maximum
	*@return biggest number in the array
	*/
	double getMax();
	/**
	* function return the position of a number
	*@param num double
	*@return if exist the position else -1
	*/
	int find(double num);
	/**
	* function used to get array element sum
	*@return sum of all array element
	*/
	double getSum();
	/**
	* function used to get array elements average
	*@return average of array elements
	*/
	double getAvg();
	/**
	* function used to get array elements standard deviation
	*@return standard deviation of array elements
	*/
	double getDeviation();
	/**
	* function used to copy array elements to a dynamic array
	*/
	void copy(std::vector<double> &vec);
	/**
	* function used to put all array elements to their absolute value
	*/
	void makeAbs();
	/**
	* function used to shift array elements
	*@param direction int for shift direction. 0 for left other number for right
	*@param times int for number of time to shift
	*/
	void shift(int direction = 0, int times = 1);
	/**
	* function used to print Array element to file
	*@param file std::ofstream output file stream to print to
	*/
	int printToFile(std::ofstream& file);
	/**
	* function used to sort array elements
	*@param order int. determine sort order 0: ascending, other: descending
	*/
	void sorting(int order = 0);
	/**
	* allow usage of standard output to print array content
	*@param os std::ostream outputstream
	*@param c Arraypp array to output
	*@return an output stream
	*/
	friend std::ostream& operator<<(std::ostream& os, const Arraypp& c);
	/**
	* allow usage of standard input fill array
	*value must  be separated by a space
	*@param is std::istream inputstream
	*@param c Arraypp array to fill
	*@return an input stream
	*/
	friend std::istream& operator >> (std::istream& is, Arraypp& c);
	/**
	* allow addition of two Arraypp object
	*@param a Arraypp array to add
	*@return operation result as array
	*/
	Arraypp operator+(const Arraypp &a);
	/**
	* allow substraction of two Arraypp object
	*@param a Arraypp array to substract
	*@return operation result as array
	*/
	Arraypp operator-(const Arraypp &a);
	~Arraypp();
};

