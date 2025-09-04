#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
	public:
		Intern();
		Intern(Intern	const &other);
		Intern& operator=(Intern const& o);
		typedef AForm* (*Creator)(std::string const &);
		AForm* makeForm(std::string const & formName, std::string const & target);
		~Intern();

	private:
};



#endif