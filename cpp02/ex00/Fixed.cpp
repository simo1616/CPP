/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:51:24 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 15:17:54 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



Fixed::Fixed() :rawbit(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(Fixed const& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other) {
		setRawBits(other.getRawBits());
	}
	return(*this);
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return(rawbit);
}
void Fixed::setRawBits( int const raw ) {
	rawbit = raw;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}