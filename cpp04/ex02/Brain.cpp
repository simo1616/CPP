#include "Brain.hpp"

Brain::Brain() :ideas() {
	std::cout << "Constructor Brain called" << std::endl;
}

Brain::Brain(Brain const & other) {
	std::cout << "Copy   constructor Brain called" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain::Brain(std::string const src[100]) {
	std::cout << "Arguments   constructor Brain called" << std::endl;
	for(int i = 0; i < 100; i++)
		ideas[i] = src[i];
}

Brain& Brain::operator=(Brain const & other) {
	std::cout << "Assignment operator Brain called" << std::endl;
	if(this != &other)
	{
		for(int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "destructor Brain called" << std::endl;
}
