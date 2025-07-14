/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:50:18 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/14 09:09:57 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed {
	
	public:
		Fixed();
		Fixed(Fixed const& other);
		Fixed(const int n);
		Fixed(const float f);

		// operateur d'affectation
		Fixed& operator=(Fixed const& other);

		// Les 6 opérateur de comparaison : >, <, >=, <=, == et !=
		bool operator==(Fixed const& other) const;
		bool operator!=(Fixed const& other) const;
		bool operator>(Fixed const& other) const;
		bool operator<(Fixed const& other) const;
		bool operator>=(Fixed const& other) const;
		bool operator<=(Fixed const& other) const;

		// Les 4 opérateurs de arithmétiques : +, -, *, et /
		Fixed operator+(Fixed const& other);
		Fixed operator+();
		Fixed operator-(Fixed const& other);
		Fixed operator-();
		Fixed operator*(Fixed const& other);
		Fixed operator/(Fixed const& other);

		// Les 2 opérateurs d’incrémentation ++i et i++
		Fixed& operator++();
		Fixed operator++(int);

		// Les 2 opérateurs de décrémentation --i et i--
		Fixed& operator--();
		Fixed operator--(int);

		// min 
		static Fixed& min(Fixed& left, Fixed& right);
		static Fixed const& min(Fixed const& left, Fixed const& right);

		// max 
		static Fixed& max(Fixed& left, Fixed& right);
		static Fixed const& max(Fixed const& left, Fixed const& right);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		~Fixed();
        
	private:
		int rawbit;
		static const int bits = 8;
};

std::ostream& operator<<(std::ostream& out, Fixed const& F);
 

#endif