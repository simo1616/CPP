#include "Dog.hpp"

Dog::Dog() :Animal(), _brain(new Brain()) {
	std::cout 	<< "Default constructor type: " << type 
				<< " called" << std::endl;
}

Dog::Dog(Dog const & other) 
:Animal(other), type(other.type), _brain(new Brain(*other._brain)) { // deep copy
	std::cout 	<< "Constructor Copy type: " << type 
				<< " called" << std::endl;
}

Dog::Dog(std::string t) 
:Animal(t), type(t), _brain(new Brain()) {
	std::cout 	<< "Constructor with arg type: " << type 
				<< " called" << std::endl;
}

Dog& Dog::operator=(Dog const & other) {
	if(this != &other) {
		Animal::operator=(other);
		type = other.type;
		*(_brain) = *other._brain; // deep copy yeaah !!!!
	}
	return *this;
}

void Dog::makeSound( void ) const{
	std::cout 	<< "Haw-How-Haw-How-Haw-How" << std::endl;
}

Dog::~Dog() {
	delete _brain;
	std::cout 	<< "Destructor type: " << type 
				<< " called" << std::endl;
}
