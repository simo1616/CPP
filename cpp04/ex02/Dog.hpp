#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"


class Dog :public AAnimal {
	public :
		Dog();
		Dog(Dog const & other);
		Dog(std::string t);
		Dog& operator=(Dog const & other);
		void makeSound() const;
		~Dog();
	private:
		std::string type;
		Brain* _brain;
};

#endif