#include <iostream>
#include <string>
#include "Harl.hpp"

int main (int ac, char **av)
{
	if(ac != 2)
	{
		std::cerr 	<< "Usage: ./harlFilter <LEVEL>" << std::endl
  					<< "LEVEL must be one of "
					<< "DEBUG, INFO, WARNING or ERROR" << std::endl;
		return(1);

	}
	Harl H;
	H.complain(av[1]);
	return(0);
}