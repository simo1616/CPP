#include "Animal.hpp"

Animal::Animal() :type("") {
	std::cout 	<< "Default constructor Animal type: " << type 
				<< " called" << std::endl;
}

Animal::Animal(Animal const & other) {
	type = other.type;
	std::cout 	<< "Constructor Copy Animal type: " << type 
				<< " called" << std::endl;
}

Animal::Animal(std::string type) :type(type) {
	std::cout 	<< "Constructor with arg Animal type: " << type 
				<< " called" << std::endl;
}

Animal& Animal::operator=(Animal const & other) {
	if(this != &other)
		type = other.type;
	return *this;
}

std::string Animal::getType() const {
	return(type);
}

void Animal::makeSound() const{
	std::cout 	<< "Aniiiiiiiiiiiimaaaaaal" << std::endl;
}

Animal::~Animal() {
	std::cout 	<< "Destructor Animal type: " << type 
				<< " called" << std::endl;
}
