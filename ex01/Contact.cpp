#include "Contact.hpp"



std::string Contact::get_firstName() const{
	return firstName;
}

std::string Contact::get_lastName() const{
	return lastName;
}

std::string Contact::get_nickName() const{
	return nickname;
}

void Contact::set_Infos()
{
	std::cout << "Enter the first_name : " << std::endl;
	std::getline(std::cin, firstName);
	std::cout << "Enter the last_name : " << std::endl;
	std::getline(std::cin, lastName);
	std::cout << "Enter the nickname : " << std::endl;
	std::getline(std::cin, nickname);
	std::cout << "Enter the phone_number : " << std::endl;
	std::getline(std::cin, phoneNumber);
	std::cout << "Enter the darkest_secret : " << std::endl;
	std::getline(std::cin, darkestSecret);
}

void Contact::display()
{
	std::cout << "The first_name is : " << Contact::firstName << std::endl;
	std::cout << "The last_name is : " << Contact::lastName << std::endl;
	std::cout << "The nickname is : " << Contact::nickname << std::endl;
	std::cout << "The phone number is : " << Contact::phoneNumber << std::endl;
	std::cout << "The darkest secret is : " << Contact::darkestSecret << std::endl;
}