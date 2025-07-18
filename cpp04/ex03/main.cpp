#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

int main() {
	std::cout << "\n=== Materia Source & Learning ===\n";
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "\n=== Character Creation & Equipping ===\n";
	Character* leo = new Character("Leo");
	AMateria* m;
	m = src->createMateria("ice");
	leo->equip(m);
	m = src->createMateria("cure");
	leo->equip(m);

	std::cout << "\n=== Battle Simulation ===\n";
	ICharacter* goblin = new Character("Goblin");
	leo->use(0, *goblin);
	leo->use(1, *goblin);

	std::cout << "\n=== Unequip & Reuse ===\n";
	AMateria* materiaToDelete = leo->tab[0];
	
	leo->unequip(0);
	leo->use(0, *goblin);
	
	m = src->createMateria("ice");
	leo->equip(m);
	leo->use(0, *goblin);

	std::cout << "\n=== Copy & Independence Test ===\n";
	Character* leoClone = new Character(*leo);  // Plus simple aussi
	leoClone->use(0, *goblin);
	leoClone->use(1, *goblin);

	std::cout << "\n=== Cleanup ===\n";
	delete materiaToDelete;
	
	delete goblin;
	delete leoClone;
	delete leo;
	delete src;

	return 0;
}

