#include "PhoneBook.hpp"



PhoneBook::PhoneBook()
{
    this->i = 0;
    std::cout << "constructeur PhoneBook" << std::endl;
    return;
}

PhoneBook::~PhoneBook()
{
    std::cout << "destructeur PhoneBook" << std::endl;
    return;
}

void PhoneBook::addContact(const Contact &c)
{
    
}
// {
//     Contact[i] = c;

//     i = (i + 1) % 8;
// }