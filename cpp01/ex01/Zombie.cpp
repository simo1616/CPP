#include "Zombie.hpp"


Zombie::Zombie() :_name("") {}

Zombie::~Zombie() {
	std::cout << _name << " destroyed" << std::endl;
	return;
}

void	Zombie::setName(std::string Name) {
	_name = Name;
	return;
}

void	Zombie::announce() const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
