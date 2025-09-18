#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cerrno>
#include <string>
#include <limits>
#include <climits>
#include <cmath>

class  ScalarConverter {
	public:
		static void convert(const std::string& input);
		
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &other);
		ScalarConverter& operator=(const ScalarConverter &o);
		~ScalarConverter();
		static void displayChar(double d);
		static void displayInt(double d);
		static void displayFloat(double d);
		static void displayDouble(double d);
};

#endif