#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm :public AForm {
	public:
		PresidentialPardonForm(std::string const& target);
		PresidentialPardonForm(PresidentialPardonForm	const &other);
		PresidentialPardonForm& operator=(PresidentialPardonForm const& o);
		void executeAction() const;
		~PresidentialPardonForm();

	private:
		const std::string _target;
};

#endif