#include "easyfind.hpp"

int main () {
	
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	vec.push_back(60);

	try {
		easyfind(vec, 50);
	}
	catch(std::runtime_error &e) {
		std::cout << "Error! " << e.what() << std::endl;
	}

	try {
		easyfind(vec, 1000);
	}
	catch(std::exception &e) {
		std::cout << "Error! " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	lst.push_back(60);

	try {
		easyfind(lst, 50);
	}
	catch(std::runtime_error &e) {
		std::cout << "Error! " << e.what() << std::endl;
	}



}