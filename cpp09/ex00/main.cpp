#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if(ac != 2) {
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	(void)av;
	try {
		BitcoinExchange btc;
		btc.run(av[1]);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

    return 0;
}