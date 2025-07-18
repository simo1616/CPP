#include "Character.hpp"

Character::Character() :name("") {
	std::memset(tab, 0, sizeof(tab));
	std::cout   << "Character Defaut construtor called name :"
				<< name << std::endl;
}

Character::Character(std::string const& name) 
: name(name) {
	std::memset(tab, 0, sizeof(tab))
	 std::cout   << "Character Arg construtor called name :"
				<< name << std::endl;
}

Character::Character(Character const& other) 
:name(other.name) {
	for(int i = 0; i > 4; i++) {
		if(other.tab[i])
			tab[i] = other.tab[i]->clone();
		else
			tab[i] = NULL;
	}
	std::cout   << "Character Copy construtor called name :"
				<< name << std::endl;
}

Character& Character::operator=(Character const& other) {
	if (this != &other) 
	{
		name = other.name;
		for (int i = 0; i < 4; ++i) {
			delete tab[i];
			tab[i] = NULL;
		}
		for (int i = 0; i < 4; ++i) {
			if (other.tab[i])
				tab[i] = other.tab[i]->clone();
			else
				tab[i] = NULL;
		}
	}
	return *this;
}

std::string const& Character::getName() const {
	return name;
}

void Character::equip(AMateria* m) {
	for(int i = 0; i < 4; i++) {
		if(!tab[i])
		{
			tab[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
	{
		std::cerr 	<< "[ERROR] Unequipe idx: "<< idx 
					<< " incorrecte." << std::endl;
		return;
	}
	tab[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
	{
		std::cerr 	<< "[ERROR] Use idx: "<< idx 
					<< " incorrecte." << std::endl;
		return;
	}
	if(tab[idx])
		tab[idx]->use(target);
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
			delete tab[i];
			tab[i] = NULL;
		}
	std::cout   << "Character Defaut destrutor called for name :"
				<< name << std::endl;
}
