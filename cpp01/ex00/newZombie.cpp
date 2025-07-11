#include "Zombie.hpp"

Zombie* newZombie(std::string Name) {
	return(new Zombie(Name));
}
