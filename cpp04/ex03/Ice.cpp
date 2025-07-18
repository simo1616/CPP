#include "Ice.hpp"

Ice::Ice() :AMateria("ice") {
    std::cout   << "Defaut construtor called type :"
				<< type << std::endl;
}

Ice::Ice(std::string const & type) :AMateria("ice")  {
    std::cout   << "Arg construtor called type :"
				<< type << std::endl;
}

Ice::Ice(Ice const& other) :AMateria(other) {
    std::cout   << "Copy construtor called type :"
				<< type << std::endl;
}

Ice& Ice::operator=(Ice const& other) {
    if(this != &other)
        AMateria::operator=(other);
    return *this;
}

std::string const & Ice::getType() const {  //Returns the materia type
	return type;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {
	std::cout   << "Defaut construtor called type :"
				<< type << std::endl;
}
