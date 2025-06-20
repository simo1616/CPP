/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:02:11 by mbendidi          #+#    #+#             */
/*   Updated: 2025/06/20 10:51:22 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"


std::string truncate(std::string str) {
	if(str.length() > 9)
		return str.substr(0, 9) + ".";
	return str;
}

PhoneBook::PhoneBook() {
	index = 0;
	nb_contacts = 0;
}

void PhoneBook::add() {
	if(!contacts[index].set_Infos())
		std::exit(0);
	std::cout << "Contact added successfully" << std::endl;
	index = (index + 1) % MAX;
	if(nb_contacts < MAX)
		nb_contacts++;
}

void PhoneBook::search() {
	std::cout	<< std::setw(10) << "Index"     << "|"
				<< std::setw(10) << "FirstName" << "|"
				<< std::setw(10) << "LastName"  << "|"
				<< std::setw(10) << "Nickname"  << std::endl;

	for (size_t i = 0; i < (size_t)nb_contacts; i++) {
		std::cout 	<< std::setw(10) << i << "|"
					<< std::setw(10) << truncate(contacts[i].get_firstName()) << "|" 
					<< std::setw(10) << truncate(contacts[i].get_lastName()) << "|" 
					<< std::setw(10) << truncate(contacts[i].get_nickName()) << std::endl;
	}
	std::string input;
	std::cout << "Insert index please:" << std::endl;
	std::getline(std::cin, input);
	if(input.length() != 1 || !isdigit(input[0])) {
		std::cout << "Index invalid" << std::endl;
		return;
	}
	int i = input[0] - '0';
	if(i >= 0 && i < nb_contacts)
		contacts[i].display();
	else
		std::cout << "Contact not found in this index" << std::endl;

}
