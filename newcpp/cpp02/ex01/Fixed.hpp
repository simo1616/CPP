/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:50:18 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 14:20:46 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>




class Fixed {
	
	public:
		Fixed();
		Fixed(Fixed const& other);
		Fixed(const int n);
		Fixed(const float f);
		Fixed& operator=(Fixed const& other);
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