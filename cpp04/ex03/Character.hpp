#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cstring>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character :public ICharacter {
	private:
		std::string name;

	public:
		Character();
		Character(std::string const& name);
		Character(Character const& other);
		Character& operator=(Character const& other);
		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		~Character();
		AMateria* tab[4];
};

#endif