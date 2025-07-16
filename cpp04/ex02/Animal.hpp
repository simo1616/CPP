#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
	public :
		AAnimal();
		AAnimal(AAnimal const & other);
		AAnimal(std::string type);
		AAnimal& operator=(AAnimal const & other);
		std::string getType() const;
		virtual void makeSound() const = 0;
		virtual ~AAnimal();
	protected:
		std::string type;
};

#endif