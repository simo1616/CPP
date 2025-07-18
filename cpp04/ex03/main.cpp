#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    std::cout << "=== AMateria / Ice / Cure Test ===\n\n";

    // On travaille toujours via des pointeurs vers la classe de base
    AMateria* mat1 = new Ice();           // Default ice
    AMateria* mat2 = new Cure("cure");    // Arg cure

    std::cout << "-- Types des instances créées --\n";
    std::cout << "mat1 type: " << mat1->getType() << "\n";
    std::cout << "mat2 type: " << mat2->getType() << "\n\n";

    std::cout << "-- Test de clone() --\n";
    AMateria* clone1 = mat1->clone();
    AMateria* clone2 = mat2->clone();
    std::cout << "clone1 type: " << clone1->getType() << "\n";
    std::cout << "clone2 type: " << clone2->getType() << "\n\n";

    // Nettoyage
    delete mat1;
    delete mat2;
    delete clone1;
    delete clone2;

    std::cout << "Test terminé sans fuite mémoire.\n";
    return 0;
}







// int main()
// {
//     IMateriaSource* src = new MateriaSource();
//     src->learnMateria(new Ice());
//     src->learnMateria(new Cure());
//     ICharacter* me = new Character("me");
//     AMateria* tmp;
//     tmp = src->createMateria("ice");
//     me->equip(tmp);
//     tmp = src->createMateria("cure");
//     me->equip(tmp);
//     ICharacter* bob = new Character("bob");
//     me->use(0, *bob);
//     me->use(1, *bob);
//     delete bob;
//     delete me;
//     delete src;
//     return 0;
// }