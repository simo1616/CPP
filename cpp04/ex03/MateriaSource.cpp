#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::memset(protot, 0, sizeof(protot));
	std::cout   << "MateriaSource Defaut construtor called!"
				<< std::endl;
}

MateriaSource::MateriaSource(AMateria * oth_pr[4]) {
	for(int i = 0; i < 4; i++) {
		protot[i] = oth_pr[i]->clone();
	}
	std::cout   << "MateriaSource Arg construtor called!"
				<< std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	for(int i = 0; i < 4; i++) {
		if(other.protot[i])
			protot[i] = other.protot[i]->clone();
		else
			protot[i] = NULL;
	}
	std::cout   << "MateriaSource Copy construtor called!"
				<< std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other) {
	if(this != &other)
	{
		for (int i = 0; i < 4; ++i) {
			delete protot[i];
			protot[i] = NULL;
		}
		for(int i = 0; i < 4; i++) {
			if(other.protot[i])
				protot[i] = other.protot[i]->clone();
			else
				protot[i] = NULL;
			}
	}
	return *this; 
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
        if (!protot[i]) {
            protot[i] = m;
            return;
        }
    }
    std::cerr << "No room to learn materia of type " << m->getType() << "\n";
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (protot[i] && protot[i]->getType() == type)
            return protot[i]->clone();
    }
	std::cout 	<< "MateriaSource dont find any type: "
				<< type << std::endl;
    return NULL;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
			delete protot[i];
			protot[i] = NULL;
		}
	std::cout   << "MateriaSource Defaut destrutor called!"
				<< std::endl;
}
