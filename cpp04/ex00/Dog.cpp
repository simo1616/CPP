#include "Dog.hpp"

Dog::Dog() :Animal() {
	std::cout 	<< "Default constructor type: " << type 
				<< " called" << std::endl;
}

Dog::Dog(Dog const & other) :Animal(other){
	type = other.type;
	std::cout 	<< "Constructor Copy type: " << type 
				<< " called" << std::endl;
}

Dog::Dog(std::string type) :Animal(type), type(type) {
	std::cout 	<< "Constructor with arg type: " << type 
				<< " called" << std::endl;
}

Dog& Dog::operator=(Dog const & other) {
	if(this != &other)
		type = other.type;
	return *this;
}

void Dog::makeSound( void ) const{
	std::cout 	<< "Haw-How-Haw-How-Haw-How" << std::endl;
}

Dog::~Dog() {
	std::cout 	<< "Destructor type: " << type 
				<< " called" << std::endl;
}
