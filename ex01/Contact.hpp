#ifndef CONTACT_HPP
#define CONTACT_HPP


#include <iostream>



#define MAX 8

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
public:
	void set_Infos();
	void display();
	std::string get_firstName() const;
	std::string get_lastName() const;
	std::string get_nickName() const;
};

#endif
