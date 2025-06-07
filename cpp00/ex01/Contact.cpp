#include "Contact.hpp"

Contact::Contact()
{
	std::cout << "Constructeur class Contact" << std::endl;
	return;
}

Contact:: ~Contact()
{
	std::cout << "Destructeur class Contact" << std::endl;
	return;
}

void Contact::setFirstName(const std::string&fa) {
	this->firstName = fa;
	return;
}

void Contact::getFirstName() const {
	std::cout << this->firstName << std::endl;
	return;
}

void Contact::setLastName(const std::string&la) {
	this->lastName = la;
	return;
}

void Contact::getLastName() const {
	std::cout << this->lastName << std::endl;
	return;
}

void Contact::setNickName(const std::string&nn) {
	this->nickName = nn;
	return;
}

void Contact::getNicktName() const {
	std::cout << this->nickName << std::endl;
	return;
}

void Contact::setPhoneNbr(const std::string&pn) {
	this->nickName = pn;
	return;
}

void Contact::getPhoneNbr() const {
	std::cout << this->phoneNbr << std::endl;
	return;
}

void Contact::setDarkestSecret(const std::string&ds) {
	this->nickName = ds;
	return;
}

void Contact::getDarkestSecret() const {
	std::cout << this->darkestSecret << std::endl;
	return;
}



