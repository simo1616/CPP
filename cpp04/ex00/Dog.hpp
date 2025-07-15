#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog :public Animal {
	public :
		Dog();
		Dog(Dog const & other);
		Dog(std::string type);
		Dog& operator=(Dog const & other);
		void makeSound() const;
		~Dog();
	private:
		std::string type;
};

#endif