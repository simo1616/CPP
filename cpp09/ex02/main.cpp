#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if(ac < 2) {
		std::cerr << "Error: please insert arguments ;)" << std::endl;
		return 1;
	}
	try {
		PmergeMe Pm(ac, av);
		Pm.displayVec("Before:");
		Pm.sortVec();
		Pm.sortDec();
		Pm.displayVec("After:");
		Pm.timeToProcessVec();
		Pm.timeToProcessDec();

		
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}

	

    return 0;
}