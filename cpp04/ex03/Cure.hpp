#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>
//#include "ICharacter.hpp"


class Cure :public AMateria {
	private:

	public:
		Cure();
		Cure(std::string const & type);
		Cure(Cure const& other);
		Cure& operator=(Cure const& other);
		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		void use(ICharacter& target);
		~Cure();
};

#endif