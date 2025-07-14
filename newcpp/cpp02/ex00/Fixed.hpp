/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:50:18 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 13:21:01 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	
	public:
		Fixed();
		Fixed(Fixed const& other);
		Fixed& operator=(Fixed const& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		~Fixed();
	private:
		int rawbit;
		static const int bits = 8;
};


 

#endif