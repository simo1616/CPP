#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Deep Copy & Polymorphic Array Test ===\n\n";

    std::cout << "-- Individual Creation and Sounds --\n";
    Dog    dog1("Rex");
    Cat    cat1("Whiskers");
    dog1.makeSound();
    cat1.makeSound();

    std::cout << "\n-- Copy Constructor Test --\n";
    Dog    dog2(dog1);
    Cat    cat2(cat1);
    dog2.makeSound();
    cat2.makeSound();

    std::cout << "\n-- Assignment Operator Test --\n";
    Dog    dog3;
    Cat    cat3;
    dog3 = dog1;
    cat3 = cat1;
    dog3.makeSound();
    cat3.makeSound();

    std::cout << "\n-- Polymorphic Array Creation --\n";
    const Animal* zoo[6];
    for (int i = 0; i < 3; ++i)
        zoo[i] = new Dog("Buddy");
    for (int i = 3; i < 6; ++i)
        zoo[i] = new Cat("Kitty");

    std::cout << "\n-- Zoo Makes Sounds --\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << zoo[i]->getType() << ": ";
        zoo[i]->makeSound();
    }

    std::cout << "\n-- Cleaning Up --\n";
    for (int i = 0; i < 6; ++i)
        delete zoo[i];

    std::cout << "\nAll tests completed\n";
    return 0;
}
