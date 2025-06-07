#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {

	public:
		Contact(); // asupp
		~Contact(); // a suppr
		void setFirstName(const std::string&);
		void getFirstName() const;
		void setLastName(const std::string&);
		void getLastName() const;
		void setNickName(const std::string&);
		void getNicktName() const;
		void setPhoneNbr(const std::string&);
		void getPhoneNbr() const;
		void setDarkestSecret(const std::string&);
		void getDarkestSecret() const;

	
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNbr;
		std::string darkestSecret;

};

#endif