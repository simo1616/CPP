#include "WrongCat.hpp"

WrongCat::WrongCat() :WrongAnimal() {
	std::cout 	<< "Default constructor type: " << type 
				<< " called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & other) :WrongAnimal(other) {
	std::cout 	<< "Constructor Copy type: " << type 
				<< " called" << std::endl;
}

WrongCat::WrongCat(std::string type) :WrongAnimal(type), type(type) {
	std::cout 	<< "Constructor with arg type: " << type 
				<< " called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const & other) {
	if(this != &other)
		type = other.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout 	<< "Miaou-Miaou-Miaou-Miaou-Miaou" << std::endl;

}

WrongCat::~WrongCat() {
	std::cout 	<< "Destructor type: " << type 
				<< " called" << std::endl;
}
