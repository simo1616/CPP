#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat :public AAnimal {
	public :
		Cat();
		Cat(Cat const & other);
		Cat(std::string t);
		Cat& operator=(Cat const & other);
		void makeSound() const;
		~Cat();
	private:
		std::string type;
		Brain* _brain;
};

#endif