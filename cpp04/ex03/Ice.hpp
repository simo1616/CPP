#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice :public AMateria {
	private:

	public:
		Ice();
		Ice(std::string const & type);
		Ice(Ice const& other);
		Ice& operator=(Ice const& other);
		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		void use(ICharacter& target);
		~Ice();
};

#endif