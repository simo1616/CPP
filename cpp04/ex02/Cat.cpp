#include "Cat.hpp"

Cat::Cat() :AAnimal(), _brain(new Brain()) {
	std::cout 	<< "Default constructor type: " << type 
				<< " called" << std::endl;
}

Cat::Cat(Cat const & other) 
:AAnimal(other), type(other.type), _brain(new Brain(*other._brain)) {
	std::cout 	<< "Constructor Copy type: " << type 
				<< " called" << std::endl;
}

Cat::Cat(std::string t) 
:AAnimal(t), type(t) , _brain(new Brain()) {
	std::cout 	<< "Constructor with arg type: " << type 
				<< " called" << std::endl;
}

Cat& Cat::operator=(Cat const & other) {
	if(this != &other) {
		AAnimal::operator=(other);
		type         = other.type;
		*(_brain) = *other._brain;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout 	<< "Miaou-Miaou-Miaou-Miaou-Miaou" << std::endl;

}

Cat::~Cat() {
	delete _brain;
	std::cout 	<< "Destructor type: " << type 
				<< " called" << std::endl;
}
