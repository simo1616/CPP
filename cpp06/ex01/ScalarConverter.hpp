#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
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
		static LiteralType detectType(std::string const& input);

};

#endif