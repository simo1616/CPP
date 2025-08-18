#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
	public:
		Form();
		Form(std::string const& name, int signGrade, int executeGrade);
		Form(Form	const &other);
		Form& operator=(Form const &other);
		std::string	getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw() {
					return "Form grade too high";
			}
		};
		class GradeTooLowException  : public std::exception {
			virtual const char* what() const throw() {
					return "Form grade too low";
			}
		};
		void beSigned(Bureaucrat const& b);
		~Form();
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;
};

std::ostream& operator<<(std::ostream& out, Form const& b);

#endif
