#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource :public IMateriaSource {
	private:
		AMateria *protot[4];
	public:
		MateriaSource();
		MateriaSource(AMateria *protot[4]);
		MateriaSource(MateriaSource const & other);
		MateriaSource& operator=(MateriaSource const & other);
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
		~MateriaSource();
};

#endif