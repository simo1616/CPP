/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:51:24 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 19:07:47 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"



std::ostream& operator<<(std::ostream& out, Fixed const& F) {
	out << F.toFloat();
	return(out);
}

Fixed::Fixed() :rawbit(0) {
}
Fixed::Fixed(Fixed const& other) {
	*this = other;
}

Fixed::Fixed(const int n) {
	setRawBits(n << bits);
}

Fixed::Fixed(const float f) {
	setRawBits(roundf(f * (1 << bits)));
}


Fixed& Fixed::operator=(Fixed const& other) {
	if(this != &other) {
		setRawBits(other.rawbit);
	}
	return(*this);
}

// Les 6 opérateur de comparaison : >, <, >=, <=, == et !=
		
bool Fixed::operator==(Fixed const& other) const{
	return(rawbit == other.rawbit);
}

bool Fixed::operator!=(Fixed const& other) const{
	return(!operator==(other));
}

bool Fixed::operator<(Fixed const& other) const{
	return(rawbit < other.rawbit);
}

bool Fixed::operator>(Fixed const& other) const{
	return(rawbit > other.rawbit);
}

bool Fixed::operator<=(Fixed const& other) const{
	return(operator<(other) || operator==(other));
}

bool Fixed::operator>=(Fixed const& other) const{
	return(operator>(other) || operator==(other));
}

// Les 4 opérateurs de arithmétiques : +, -, *, et /

Fixed Fixed::operator+(Fixed const& other) {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator+() {
	return(*this);
}

Fixed Fixed::operator-(Fixed const& other) {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator-() {
	return Fixed(this->toFloat() * -1);
}

Fixed Fixed::operator*(Fixed const& other) {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const& other) {
	if (other.getRawBits() == 0) {
        std::cerr << "Error: division by zero" << std::endl;
        return Fixed();
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
	rawbit += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed tmp = *this;
	rawbit += 1;
	return tmp;
}

Fixed& Fixed::operator--() {
	rawbit -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed tmp = *this;
	rawbit -= 1;
	return tmp;
}

Fixed& Fixed::min(Fixed& left, Fixed& right) {
	if(left < right)
		return left;
	else
		return right;
}

Fixed const& Fixed::min(Fixed const& left, Fixed const& right) {
	if(left < right)
		return left;
	else
		return right;
}

Fixed& Fixed::max(Fixed& left, Fixed& right) {
	if(left > right)
		return left;
	else
		return right;
}

Fixed const& Fixed::max(Fixed const& left, Fixed const& right) {
	if(left > right)
		return left;
	else
		return right;
}

int Fixed::getRawBits( void ) const {
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
}