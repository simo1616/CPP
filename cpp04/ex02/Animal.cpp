#include "Animal.hpp"

AAnimal::AAnimal() :type("") {
	std::cout 	<< "Default constructor AAnimal type: " << type 
				<< " called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & other) {
	type = other.type;
	std::cout 	<< "Constructor Copy AAnimal type: " << type 
				<< " called" << std::endl;
}

AAnimal::AAnimal(std::string type) :type(type) {
	std::cout 	<< "Constructor with arg AAnimal type: " << type 
				<< " called" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const & other) {
	if(this != &other)
		type = other.type;
	return *this;
}

std::string AAnimal::getType() const {
	return(type);
}

AAnimal::~AAnimal() {
	std::cout 	<< "Destructor AAnimal type: " << type 
				<< " called" << std::endl;
}
