#include "Rpn.hpp"

int main(int ac, char **av)
{
	if(ac != 2) {
		std::cerr << "Error: please insert argument ;)" << std::endl;
		return 1;
	}
	std::string argv(av[1]);
	Rpn solv(argv) ;
	solv.processRpn();
	

	

    return 0;
}