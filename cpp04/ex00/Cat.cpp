#include "Cat.hpp"

Cat::Cat() :Animal() {
	std::cout 	<< "Default constructor type: " << type 
				<< " called" << std::endl;
}

Cat::Cat(Cat const & other) :Animal(other) {
	std::cout 	<< "Constructor Copy type: " << type 
				<< " called" << std::endl;
}

Cat::Cat(std::string type) :Animal(type), type(type) {
	std::cout 	<< "Constructor with arg type: " << type 
				<< " called" << std::endl;
}

Cat& Cat::operator=(Cat const & other) {
	if(this != &other)
		type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout 	<< "Miaou-Miaou-Miaou-Miaou-Miaou" << std::endl;

}

Cat::~Cat() {
	std::cout 	<< "Destructor type: " << type 
				<< " called" << std::endl;
}
