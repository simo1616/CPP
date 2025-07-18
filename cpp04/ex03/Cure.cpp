#include "Cure.hpp"

Cure::Cure() :AMateria("cure") {
	std::cout   << "Defaut construtor called type :"
				<< type << std::endl;
}

Cure::Cure(std::string const & type) :AMateria("cure")  {
	std::cout   << "Arg construtor called type :"
				<< type << std::endl;
}

Cure::Cure(Cure const& other) :AMateria(other) {
	std::cout   << "Copy construtor called type :"
				<< type << std::endl;
}

Cure& Cure::operator=(Cure const& other) {
	if(this != &other)
		AMateria::operator=(other);
	return *this;
}

std::string const & Cure::getType() const {  //Returns the materia type
	return type;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}


Cure::~Cure() {
	std::cout   << "Defaut construtor called type :"
				<< type << std::endl;
}