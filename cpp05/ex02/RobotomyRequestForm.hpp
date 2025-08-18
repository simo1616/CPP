#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>


class RobotomyRequestForm :public AForm {
	public:
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(RobotomyRequestForm	const &other);
		RobotomyRequestForm& operator=(RobotomyRequestForm const& o);
		void executeAction() const;
		~RobotomyRequestForm();

	private:
		const std::string _target;
};

#endif