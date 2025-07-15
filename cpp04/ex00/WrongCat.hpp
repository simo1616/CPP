#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat :public WrongAnimal {
	public :
		WrongCat();
		WrongCat(WrongCat const & other);
		WrongCat(std::string type);
		WrongCat& operator=(WrongCat const & other);
		void makeSound() const;
		~WrongCat();
	private:
		std::string type;
};

#endif