#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if(ac < 2) {
		std::cerr << "Error: please insert arguments ;)" << std::endl;
		return 1;
	}
	try {
		PmergeMe Pm(ac, av);
		Pm.sortVec();
		Pm.displayVec("begin :");
		
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}

	

    return 0;
}