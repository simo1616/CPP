#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &o) { (void)o; return *this; }

void ScalarConverter::displayChar(double d) {
	std::cout << "char\t: ";
	if (std::isnan(d) || std::isinf(d) || d < 0.0 || d > 127.0) {
		std::cout << "impossible\n";
		return;
	}
	char ch = static_cast<char>(d);
	if (!std::isprint(static_cast<unsigned char>(ch)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << ch << "'\n";
}

void ScalarConverter::displayInt(double d) {
	std::cout << "int\t: ";
	if (std::isnan(d) || std::isinf(d) || d < INT_MIN || d > INT_MAX)
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(d) << "\n";
}

void ScalarConverter::displayFloat(double d) {
	std::cout << "float\t: ";
	if (std::isnan(d))
		std::cout << "nanf\n";
	else if (std::isinf(d))
		std::cout << (std::signbit(d) ? "-inff" : "+inff") << "\n";
	else
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f\n";
}

void ScalarConverter::displayDouble(double d) {
	std::cout << "double\t: ";
	if (std::isnan(d))
		std::cout << "nan\n";
	else if (std::isinf(d))
		std::cout << (std::signbit(d) ? "-inf" : "+inf") << "\n";
	else
		std::cout << std::fixed << std::setprecision(1) << d << "\n";
}

void ScalarConverter::convert(const std::string& input) {
	if (input.size() == 1 && !std::isdigit(static_cast<unsigned char>(input[0]))) {
		char c = input[0];
		double d = static_cast<double>(c);
		displayChar(d);
		displayInt(d);
		displayFloat(d);
		displayDouble(d);
		return;
	}

	if (input == "nanf" || input == "+inff" || input == "-inff" ||
		input == "nan"  || input == "+inf"  || input == "-inf") {
		if (input == "nanf" || input == "nan")
			std::cout << "char\t: impossible\nint\t: impossible\nfloat\t: nanf\ndouble\t: nan\n";
		else if (input == "+inff" || input == "+inf")
			std::cout << "char\t: impossible\nint\t: impossible\nfloat\t: +inff\ndouble\t: +inf\n";
		else
			std::cout << "char\t: impossible\nint\t: impossible\nfloat\t: -inff\ndouble\t: -inf\n";
		return;
	}

	std::string s = input;
	if (s.size() > 1 && s[s.size() - 1] == 'f' && s.find('.') != std::string::npos) {
		s.erase(s.size() - 1);
	}

	std::stringstream ss(s);
	double d;
	ss >> d;

	if (ss.fail() || !ss.eof()) {
		std::cout 	<< "char\t: impossible\n"
					<< "int\t: impossible\n"
					<< "float\t: impossible\n"
					<< "double\t: impossible\n";
		return;
	}

	displayChar(d);
	displayInt(d);
	displayFloat(d);
	displayDouble(d);
}
