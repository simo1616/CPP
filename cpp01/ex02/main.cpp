#include <iostream>


int main ()
{
	std::string var = "HI THIS IS BRAIN";
	std::string* stringPTR = &var;
	std::string& stringREF = var;

	std::cout << "Adresses :" 				<< std::endl;

	std::cout << "Adresse of var		: "	<< &var << std::endl;
	std::cout << "Adresse of stringPTR	: "	<< stringPTR << std::endl;
	std::cout << "Adresse of stringREF	: "	<< &stringREF << std::endl;

	std::cout << "Values :" 				<< std::endl;

	std::cout << "Value of var		: "		<< var << std::endl;
	std::cout << "Value of stringPTR	: "	<< *stringPTR << std::endl;
	std::cout << "Value of stringREF	: "	<< stringREF << std::endl;
	return 0;

}	