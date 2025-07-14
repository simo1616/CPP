/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Simple.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:50:18 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 09:23:29 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_HPP
#define SIMPLE_HPP

#include <iostream>

class Simple
{
	
	public:
		Simple();
		~Simple();
		int getSimple_x(void);
		void setSimple_x(int n);
	private:
		int x;
};




#endif