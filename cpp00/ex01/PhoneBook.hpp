#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        void addContact(const Contact&);
        void displayList();
        void displayContact(int index) const;
    private:
        Contact contacts[8];
        int i;

};

#endif