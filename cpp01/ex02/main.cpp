/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:21:42 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/12 07:52:47 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() 
{
	std::string		var			= "HI THIS IS BRAIN";
	std::string*	stringPTR	= &var;
	std::string&	stringREF	= var;

	std::cout
		<< "Memory address of string variable	: "		<<	&var		<< '\n'
		<< "Memory address held by stringPTR	: "		<<	stringPTR	<< '\n'
		<< "Memory address held by stringREF	: "		<<	&stringREF	<< "\n\n";

	std::cout
		<< "Value of string variable		: "			<<	var			<< '\n'
		<< "Value pointed to by stringPTR		: "		<<	*stringPTR	<< '\n'
		<< "Value pointed to by stringREF		: "		<<	stringREF	<< '\n';

	return (0);
}

