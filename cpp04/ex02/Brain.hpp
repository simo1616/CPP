#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain const & other);
		Brain(std::string const src[100]);
		Brain& operator=(Brain const & other);
		~Brain();
	private:
		std::string ideas[100];
};

#endif