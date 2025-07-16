#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
//#include "ICharacter.hpp"


class Ice :public AMateria {
	protected:
		std::string type;

	public:
		Ice();
		Ice(std::string const & type);
		Ice(Ice const& other);
		Ice& operator=(Ice const& other);
		std::string const & getType() const; //Returns the materia type
		AMateria* clone() const;
		//virtual void use(ICharacter& target);
		~Ice();
};

#endif