#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat :public Animal {
	public :
		Cat();
		Cat(Cat const & other);
		Cat(std::string type);
		Cat& operator=(Cat const & other);
		void makeSound() const;
		~Cat();
	private:
		std::string type;
};

#endif