/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 09:01:50 by mbendidi          #+#    #+#             */
/*   Updated: 2025/06/20 10:53:45 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Contact.cpp
#include "Contact.hpp"
#include <cctype>

std::string Contact::get_firstName() const { return firstName; }
std::string Contact::get_lastName() const  { return lastName;  }
std::string Contact::get_nickName() const  { return nickname;  }



static bool is_blank(const std::string& s) {
	for (unsigned int i = 0; i < s.length(); ++i) {
		if (s[i] != ' ')
			return false;
	}
	return true;
}

bool Contact::set_Infos() {
	std::cout << "Enter the first name:\n";
	if (!std::getline(std::cin, firstName)) 
		return false;
	while (firstName.empty() || is_blank(firstName)) 
	{
		std::cout << "First name cannot be empty. Try again: \n";
		if (!std::getline(std::cin, firstName)) 
			return false;
	}

	std::cout << "Enter the last name:\n";
	if (!std::getline(std::cin, lastName)) 
		return false;
	while (lastName.empty() || is_blank(lastName)) 
	{
		std::cout << "Last name cannot be empty. Try again: \n";
		if (!std::getline(std::cin, lastName)) 
			return false;
	}

	std::cout << "Enter the nickname:\n";
	if (!std::getline(std::cin, nickname)) 
		return false;
	while (nickname.empty() || is_blank(nickname)) 
	{
		std::cout << "Nickname cannot be empty. Try again: \n";
		if (!std::getline(std::cin, nickname)) 
			return false;
	}

	std::cout << "Enter the phone number:\n";
	if (!std::getline(std::cin, phoneNumber)) 
		return false;
	while (phoneNumber.empty() || is_blank(phoneNumber)) 
	{
		std::cout << "Phone number cannot be empty. Try again: \n";
		if (!std::getline(std::cin, phoneNumber)) 
			return false;
	}

	std::cout << "Enter the darkest secret:\n";
	if (!std::getline(std::cin, darkestSecret)) 
		return false;
	while (darkestSecret.empty() || is_blank(darkestSecret)) 
	{
		std::cout << "Darkest secret cannot be empty. Try again: \n";
		if (!std::getline(std::cin, darkestSecret)) 
			return false;
	}

	return true;
}

void Contact::display() const {
    std::cout << "First Name    : " << firstName    << '\n'
              << "Last  Name    : " << lastName     << '\n'
              << "Nickname      : " << nickname     << '\n'
              << "Phone Number  : " << phoneNumber  << '\n'
              << "Darkest Secret: " << darkestSecret<< '\n';
}


