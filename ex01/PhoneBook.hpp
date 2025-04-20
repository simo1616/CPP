#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>


class PhoneBook {
	private:
	Contact	contacts[MAX];
	size_t	index;
	int		nb_contacts;
public:
	PhoneBook();
	void add();
	void search();
};

#endif