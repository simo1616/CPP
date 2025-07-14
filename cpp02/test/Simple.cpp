/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simple.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:51:24 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 09:23:13 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Simple.hpp"

Simple::Simple() :x(0)
{
	std::cout << "Constructeur Called" << std::endl;
}

Simple::~Simple()
{
	std::cout << "Destructeur Called" << std::endl;
}

int Simple::getSimple_x(void) {
	return(this->x);
}

void Simple::setSimple_x(int n) {
	this->x = n;
}

