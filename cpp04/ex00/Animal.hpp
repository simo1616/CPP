#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
	public :
		Animal();
		Animal(Animal const & other);
		Animal(std::string type);
		Animal& operator=(Animal const & other);
		std::string getType() const;
		virtual void makeSound() const;
		virtual ~Animal();
	protected:
		std::string type;
};

#endif