#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(std::string _name, int _grade);
		Bureaucrat(Bureaucrat	const &other);
		Bureaucrat& operator=(Bureaucrat	const &other);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade Too High";
				}
			};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Grade Too Low";
				}
			};
		
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm& f);
		std::string getName()	const;
		int	getGrade() const;
		void executeForm(AForm const & form) const;
		~Bureaucrat();
	private:
		const std::string name;
		int 		grade;
};

std::ostream& operator<<(std::ostream& out, Bureaucrat const& b);

#endif
