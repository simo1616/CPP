#include "Zombie.hpp"


Zombie::Zombie(std::string Name) :_name(Name) {}

Zombie::~Zombie() {
	std::cout << _name << " destroyed" << std::endl;
	return;
}

void	Zombie::announce() const{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return;
}
