#include "Ice.hpp"

Ice::Ice() :AMateria() {
    std::cout   << "Defaut construtor called type :"
				<< type << std::endl;
}

Ice::Ice(std::string const & type) 
:AMateria(), type(type) {
    std::cout   << "Arg construtor called type :"
				<< type << std::endl;
}

Ice::Ice(Ice const& other) 
:AMateria(), type(other.type) {
    std::cout   << "Copy construtor called type :"
				<< type << std::endl;
}

Ice& Ice::operator=(Ice const& other) {
    if(this != &other)
        AMateria::operator=(other);
    return *this;
}

std::string const & Ice::getType() const {  //Returns the materia type

}

AMateria* Ice::clone() const {

}

void Ice::use(ICharacter& target) {

}

Ice::~Ice() {

}
