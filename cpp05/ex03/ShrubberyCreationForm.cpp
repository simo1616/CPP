#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target) 
: AForm("ShrubberyCreationForm", 145, 137),
_target(target) {}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm	const& other) 
:AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& o) {
	AForm::operator=(o);
	return *this;
}

void ShrubberyCreationForm::executeAction() const {
	std::ofstream out((_target + "_shrubbery").c_str());
	if(!out)
		throw std::runtime_error("Cannot open file " + _target + "_shrubbery");
	out << "    ccee88oo			\n"
           "  C8O8O8Q8PoOb o8oo		\n"
           " dOB69QO8PdUOpugoO9bD	\n"
           "CgggbU8OU qOp qOdoUOdcb	\n"
           "    6OuU  /p u gcoUodp	\n"
           "      \\\\//  /douUP	\n"
           "        \\\\////		\n"
           "         |||/\\			\n"
           "         |||\\/			\n"
           "         |||||			\n"
           "  .....\\//||||\\....	\n";
    if (out.fail()) {
        throw std::runtime_error("Error on file " + _target + "_shrubbery");
    }	
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
