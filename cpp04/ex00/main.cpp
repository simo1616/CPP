// #include "Dog.hpp"
// #include "Cat.hpp"

// int main()
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();
// 	return 0;
// }

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "=== Polymorphism Test ===" << std::endl;

    std::cout << "\n--- Animal Instances Creation ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j    = new Dog();
    const Animal* i    = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();    // chat
    j->makeSound();    // chien
    meta->makeSound(); // Animal générique

    std::cout << "\n--- Copy & Assignment ---" << std::endl;
    Animal copyAnimal(*j);       // copie de Dog dans Animal (slicing)
    copyAnimal.makeSound();      // Animal::makeSound
    Animal assignAnimal;
    assignAnimal = *i;           // affectation de Cat dans Animal
    assignAnimal.makeSound();    // Animal::makeSound

    std::cout << "\n--- Deleting Animal Instances ---" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Wrong Polymorphism Test ===" << std::endl;

    std::cout << "\n--- WrongAnimal Instances Creation ---" << std::endl;
    const WrongAnimal* w_meta = new WrongAnimal();
    const WrongAnimal* w_cat  = new WrongCat();

    std::cout << w_cat->getType() << std::endl;
    w_cat->makeSound();   // WrongAnimal::makeSound, pas WrongCat
    w_meta->makeSound();

    std::cout << "\n--- Copy & Assignment Wrong ---" << std::endl;
    WrongAnimal copyWrong(*w_cat);
    copyWrong.makeSound();     // WrongAnimal::makeSound
    WrongAnimal assignWrong;
    assignWrong = *w_cat;
    assignWrong.makeSound();   // WrongAnimal::makeSound

    std::cout << "\n--- Deleting Wrong Instances ---" << std::endl;
    delete w_meta;
    delete w_cat;

    return 0;
}
