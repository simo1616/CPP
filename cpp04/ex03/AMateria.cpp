#include "AMateria.hpp"

AMateria::AMateria() :type() {
	std::cout   << "Defaut construtor called type :"
				<< type << std::endl;
}

AMateria::AMateria(std::string const & type) :type(type) {
	std::cout   << "Arg construtor called type :"
				<< type << std::endl;
}

AMateria::AMateria(AMateria const& other) :type(other.type) {
	std::cout   << "Copy construtor called type :"
				<< type << std::endl;
}

AMateria& AMateria::operator=(AMateria const& other) {
	if(this != &other)
		type = other.type;
	return *this;
}

std::string const& AMateria::getType() const { //Returns the materia type
	return(this->type);
}

// void AMateria::use(ICharacter& target) {

// }

AMateria::~AMateria() {
	std::cout   << "Defaut Destrutor called type :"
				<< type << std::endl;
}