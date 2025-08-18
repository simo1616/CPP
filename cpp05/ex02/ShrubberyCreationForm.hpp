#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm :public AForm {
	public:
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm	const &other);
		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& o);
		void executeAction() const;
		~ShrubberyCreationForm();

	private:
		const std::string _target;
};

#endif

