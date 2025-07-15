#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	public :
		WrongAnimal();
		WrongAnimal(WrongAnimal const & other);
		WrongAnimal(std::string type);
		WrongAnimal& operator=(WrongAnimal const & other);
		std::string getType() const;
		void makeSound() const;
		~WrongAnimal();
	protected:
		std::string type;
};

#endif