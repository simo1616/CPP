#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::memset(protot, 0, sizeof(protot));
	std::cout   << "MateriaSource Defaut construtor called!"
				<< std::endl;
}

MateriaSource::MateriaSource(AMateria * oth_pr[4]) {
	for(int i = 0; i < 4; i++) {
		protot[i] = oth_pr[i];
	}
	std::cout   << "MateriaSource Arg construtor called!"
				<< std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	
	std::cout   << "MateriaSource Copy construtor called!"
				<< std::endl;
}

MateriaSource& MateriaSource::operator=(MateriaSource const & other) {

}

void MateriaSource::learnMateria(AMateria*) {

}

AMateria* MateriaSource::createMateria(std::string const & type) {

}

MateriaSource::~MateriaSource() {
	std::cout   << "MateriaSource Defaut destrutor called!"
				<< std::endl;
}
