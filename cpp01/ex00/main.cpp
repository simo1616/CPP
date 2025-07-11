#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZ = newZombie("Heapy");
	heapZ->announce();
	delete heapZ;
	randomChump("Chumpy");
	return(0);
}
