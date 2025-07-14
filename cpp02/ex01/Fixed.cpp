/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:51:24 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 15:09:42 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



std::ostream& operator<<(std::ostream& out, Fixed const& F) {
	out << F.toFloat();
	return(out);
}

Fixed::Fixed() :rawbit(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(Fixed const& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(n << bits);
}

Fixed::Fixed(const float f) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(f * (1 << bits)));
}


Fixed& Fixed::operator=(Fixed const& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other) {
		setRawBits(other.rawbit);
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

float Fixed::toFloat( void ) const {
	return(rawbit / float(1 << bits));
}

int Fixed::toInt( void ) const {
	return(rawbit >> bits);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}