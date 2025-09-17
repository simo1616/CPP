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
		enum LiteralType {
			CHAR_T,
			INT_T,
			FLOAT_T,
			DOUBLE_T,
			PSEUDO_FLOAT,
			PSEUDO_DOUBLE,
			INVALID
		};
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