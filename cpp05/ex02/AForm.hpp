#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
	public:
		AForm();
		AForm(std::string const& name, int signGrade, int executeGrade);
		AForm(AForm	const &other);
		AForm& operator=(AForm const &other);
		std::string	getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		class GradeTooHighException : public std::exception {
			virtual const char* what() const throw() {
					return "AForm grade too high";
			}
		};
		class GradeTooLowException  : public std::exception {
			virtual const char* what() const throw() {
					return "AForm grade too low";
			}
		};
		class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw() {
                    return "AForm is not signed";
                }
        };
		void beSigned(Bureaucrat const& b);
		virtual void execute(Bureaucrat const & executor) const;
		virtual void executeAction() const = 0;
		virtual ~AForm();
	private:
		const std::string	name;
		bool				isSigned;
		const int			signGrade;
		const int			executeGrade;
};

std::ostream& operator<<(std::ostream& out, AForm const& b);

#endif
