#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() :type("") {
	std::cout 	<< "Default constructor WrongAnimal type: " << type 
				<< " called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & other) {
	type = other.type;
	std::cout 	<< "Constructor Copy WrongAnimal type: " << type 
				<< " called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) :type(type) {
	std::cout 	<< "Constructor with arg WrongAnimal type: " << type 
				<< " called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & other) {
	if(this != &other)
		type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return(type);
}

void WrongAnimal::makeSound() const{
	std::cout 	<< "WROOOONG!! Aniiiiiiiiiiiimaaaaaal " << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout 	<< "Destructor WrongAnimal type: " << type 
				<< " called" << std::endl;
}
