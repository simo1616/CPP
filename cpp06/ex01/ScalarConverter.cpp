#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {(void)other;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &o) {(void)o; return *this;}

ScalarConverter::~ScalarConverter() {}

// static void display(std::string input, ) {
// 	std::cout << "char: " << static_cast<unsigned char>(input)
// }

static bool isDoubleForm(std::string const& input) {
		int		start 	= 1;
		int		point 	= 0;

		if(input.empty())
			return false;
		bool sign = (input[0] == '+' || input[0] == '-');
		if(sign && input.size() < 2) // .2 +.
			return false;
		if(sign)
			start = 1;
		else
			start = 0;
		// -42.580
		for (size_t i = start; i < input.length(); i++) {
			if(input[i] == '.') {
				if(!i || i == input.length() - 1) // .654
					return false;
				else if (!std::isdigit(static_cast<unsigned char>(input[i - 1]))) // +.
					return false;
				point++;
				if(point != 1)
					return false;
			}
		}
		if(point != 1)
			return false;
		for (size_t i = start; i < input.length() ; i++) { 
			if ((input[i] != '.'))
				if(!std::isdigit(static_cast<unsigned char>(input[i])))
					return false;
		}
		return true;
}

static bool isFloatForm(std::string const& input) {
		int		start 	= 1;
		int		point 	= 0;
		int		f 		= 0;

		if(input.empty())
			return false;
		bool sign = (input[0] == '+' || input[0] == '-');
		if(sign && input.size() < 2) // .2 +.
			return false;
		if(sign)
			start = 1;
		else
			start = 0;
		// -42.580
		for (size_t i = start; i < input.length(); i++) {
			if(input[i] == '.') {
				if(!i || i == input.length() - 1) // .654
					return false;
				else if (!std::isdigit(static_cast<unsigned char>(input[i - 1]))) // +.
					return false;
				point++;
				if(point != 1)
					return false;
			}
			if(input[i] == 'f') {
				if(!i) // f645
					return false;
				if(i != input.length() - 1) // 28.f3
					return false;
				else if (!std::isdigit(static_cast<unsigned char>(input[i - 1]))) // 89.f
					return false;
				f++;
				if(f != 1) // 89.8ff
					return false;
			}
		}
		if(f != 1 || point != 1)
			return false;
		for (size_t i = start; i < input.length() ; i++) { 
			if ((input[i] != '.' && input[i] != 'f'))
				if(!std::isdigit(static_cast<unsigned char>(input[i])))
					return false;
		}
		return true;
}

static bool isIntForm(std::string const& input) {
		size_t start = 1;
		if(input.empty())
			return false;
		bool sign = (input[0] == '+' || input[0] == '-');
		if(sign && input.size() < 2)
			return false;
		
		if(sign)
			start = 1;
		else
			start = 0;
		for (size_t i = start; i < input.length() ; i++) {
			if (!std::isdigit(static_cast<unsigned char>(input[i])))
				return false;
		}
		return true;
}

ScalarConverter::LiteralType ScalarConverter::detectType(std::string const& input) {
	if			(input == "nanf" || input == "+inff" || input == "-inff")
		return ScalarConverter::PSEUDO_FLOAT;
	else if		(input == "nan" || input == "+inf" || input == "-inf")
		return ScalarConverter::PSEUDO_DOUBLE;
	else if 	(	input.size() == 1 
				&&  std::isprint(static_cast<unsigned char>(input[0])) 
				&& !std::isdigit(static_cast<unsigned char>(input[0])) )
		return ScalarConverter::CHAR_T;

	else if	(isIntForm(input))	
		return ScalarConverter::INT_T;

	else if	(isFloatForm(input))	
		return ScalarConverter::FLOAT_T;
		
	
	else if	(isDoubleForm(input))	
		return ScalarConverter::DOUBLE_T;

	return ScalarConverter::INVALID;
}

void ScalarConverter::convert(const std::string& input) {

	ScalarConverter::LiteralType type = detectType(input);
	if (type == ScalarConverter::INVALID)
	{
		std::cout 	<< "char\t: impossible\n"
					<< "int\t: impossible\n"
					<< "float\t: impossible\n"
					<< "double\t: impossible\n";
	}

	else if (type == ScalarConverter::PSEUDO_FLOAT)
	{
		if (input == "nanf")
		{
			std::cout 	<< "char\t: impossible\n"
						<< "int\t: impossible\n"
						<< "float\t: nanf\n"
						<< "double\t: nan\n";
		}
		else if (input == "+inff")
		{
			std::cout 	<< "char\t: impossible\n"
						<< "int\t: impossible\n"
						<< "float\t: +inff\n"
						<< "double\t: +inf\n";
		}
		else if (input == "-inff")
		{
			std::cout 	<< "char\t: impossible\n"
						<< "int\t: impossible\n"
						<< "float\t: -inff\n"
						<< "double\t: -inf\n";
		}
	}
	else if (type == ScalarConverter::PSEUDO_DOUBLE)
	{
		if (input == "nan")
		{
			std::cout 	<< "char\t: impossible\n"
						<< "int\t: impossible\n"
						<< "float\t: nanf\n"
						<< "double\t: nan\n";
		}
		else if (input == "+inf")
		{
			std::cout 	<< "char\t: impossible\n"
						<< "int\t: impossible\n"
						<< "float\t: +inff\n"
						<< "double\t: +inf\n";
		}
		else if (input == "-inf")
		{
			std::cout 	<< "char\t: impossible\n"
						<< "int\t: impossible\n"
						<< "float\t: -inff\n"
						<< "double\t: -inf\n";
		}
	}

	else if (type == ScalarConverter::CHAR_T)
	{
		bool printable = std::isprint(static_cast<unsigned char>(input[0]));
		std::cout << "char	: ";
		if(!printable)	std::cout << "Non displayable\n";
		else								std::cout 	<< "'" << input[0] << "'\n";
		std::cout	<< "int	: " << static_cast<int>(input[0]) << "\n" // verifier si c'est un int !!!
					<< "float	: " << std::fixed << std::setprecision(1) << static_cast<float>(input[0])  << "f" << "\n"
					<< "double	: " << std::fixed << std::setprecision(1) << static_cast<double>(input[0]) << "\n"
					<< std::endl;
		
	}
	else if (type == ScalarConverter::INT_T)
	{
		char *end;
		errno = 0;
		long val = strtol(input.c_str(), &end, 10);
		bool parse_ok = *end == '\0' && errno != ERANGE; // valid int
		bool char_in_range = parse_ok && (val >= 0 && val <= 127); // valid char
		char c = static_cast<char>(val);
		bool printable = char_in_range && std::isprint(static_cast<unsigned char>(c));

		std::cout << "char	: ";
		if(!parse_ok || !char_in_range)		std::cout << "Impossible.\n";
		else if(!printable) 				std::cout << "Non displayable.\n";
		else								std::cout << c << std::endl;

		bool valid_int = val >= INT_MIN && val <= INT_MAX;
		std::cout << "int	: ";
		if(!parse_ok || !valid_int) std::cout << "Impossible\n";
		else 						std::cout << val << std::endl;

		float f = static_cast<float>(val);
		std::cout << "float	: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;

		double d = static_cast<double>(val);
		std::cout << "double	: " << std::fixed << std::setprecision(1) << d << std::endl;
	}
	else if (type == ScalarConverter::FLOAT_T)
	{
		char *end;
		float f = strtof(input.c_str(), &end);
		bool parse_ok = *end == 'f' && end[1] == '\0'; //text consommé
		bool is_nan = std::isnan(f);
		bool is_inf = std::isinf(f);
		bool is_finite = !is_inf && !is_nan;
		bool char_in_range = is_finite && f >= 0 && f <= 127;
		bool int_valid = is_finite && f >= INT_MIN && f <= INT_MAX;
		
		
		std::cout				<< "char\t: ";
		if(!parse_ok) 
			std::cout				<< " impossible.\n";
		else if(is_nan || is_inf)
			std::cout				<< " impossible.\n";
		else if(!char_in_range)
			std::cout				<< " impossible.\n";
		else {
			int iv = static_cast<int>(f);
			char ch = static_cast<char>(iv);
			if(!std::isprint(static_cast<unsigned char>(ch)))
				std::cout				<< "Non displayable.\n";
			else
				std::cout << "'" << ch << "'" << std::endl;
		}


		std::cout << "int\t: ";
		if (!parse_ok || is_nan || is_inf || !int_valid)
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(f) << "\n";

		std::cout << "float\t: ";  
		if(!parse_ok) 			std::cout << "impossible.\n";
		else if(is_nan) 		std::cout << "nanf\n";
		else if(is_inf) {
			if(std::signbit(f)) 	std::cout << "-inff\n";
			else 					std::cout << "+inff\n";
		}
		else {
			std::cout				<< std::fixed << std::setprecision(1)
									<< f << "f" << std::endl;
		}

		std::cout << "double\t: ";  
		if(!parse_ok) 			std::cout << "impossible.\n";
		else if(is_nan) 		std::cout << "nan\n";
		else if(is_inf) {
			if(std::signbit(f)) 	std::cout << "-inf\n";
			else 					std::cout << "+inf\n";
		}
		else {
			std::cout				<< std::fixed << std::setprecision(1)
									<< static_cast<double>(f) << std::endl;
		}

	}
	else if (type == ScalarConverter::DOUBLE_T)
	{
		char* end;
		double d = strtod(input.c_str(), &end);
		bool parse_ok = (*end == '\0');
		bool is_nan   = std::isnan(d);
		bool is_inf   = std::isinf(d);
		bool is_finite = !is_nan && !is_inf;

		bool char_in_range = is_finite && d >= 0.0 && d <= 127.0;
		bool int_valid = is_finite &&
			(d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max());

		// char
		std::cout << "char\t: ";
		if (!parse_ok || is_nan || is_inf || !char_in_range) {
			std::cout << "impossible\n";
		} else {
			int iv = static_cast<int>(d);
			char ch = static_cast<char>(iv);
			if (!std::isprint(static_cast<unsigned char>(ch))) std::cout << "Non displayable\n";
			else                                               std::cout << "'" << ch << "'\n";
		}

		// int
		std::cout << "int\t: ";
		if (!parse_ok || is_nan || is_inf || !int_valid) std::cout << "impossible\n";
		else                                             std::cout << static_cast<int>(d) << "\n";

		// float
		std::cout << "float\t: ";
		if (!parse_ok)				std::cout << "impossible\n";
		else if (is_nan)			std::cout << "nanf\n";
		else if (is_inf) {
			if (std::signbit(d))	std::cout << "-inff\n";
			else					std::cout << "+inff\n";
		} else {
			std::cout 	<< std::fixed << std::setprecision(1)
						<< static_cast<float>(d) << "f\n";
		}

		// double
		std::cout << "double\t: ";
		if (!parse_ok)				std::cout << "impossible\n";
		else if (is_nan)			std::cout << "nan\n";
		else if (is_inf) {
			if (std::signbit(d))	std::cout << "-inf\n";
			else					std::cout << "+inf\n";
		} else {
			std::cout 	<< std::fixed << std::setprecision(1)
						<< d << "\n";
		}
	}

}

