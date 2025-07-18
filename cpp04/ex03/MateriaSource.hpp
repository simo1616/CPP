#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource :public IMateriaSource {
	private:
		AMateria *protot[4];
	public:
		MateriaSource();
		MateriaSource(AMateria *protot[4]);
		MateriaSource(MateriaSource const & other);
		MateriaSource& operator=(MateriaSource const & other);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
		~MateriaSource();
};

#endif