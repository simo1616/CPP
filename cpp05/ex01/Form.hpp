#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Form {
	public:
		Form();
		Form(std::string const& name, int signGrade, int executeGrade);
		Form(Form	const &other);
		Form& operator=(Form	const &other);
		
		~Form();
	private:
		const		std::string name;
		bool		isSigned; // indique si le formulaire est signé (initialement false)
		const int	signGrade; // grade requis pour signer
		const int	executeGrade; // grade requis pour exécuter
};

std::ostream& operator<<(std::ostream& out, Form const& b);

#endif
