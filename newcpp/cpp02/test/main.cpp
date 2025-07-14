/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:46:16 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 09:27:22 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Simple.hpp"


int main (void) 
{
	Simple a;
	Simple b;
	Simple c;
	c = a;

	b.setSimple_x(10);

	std::cout << a.getSimple_x() << std::endl;
	std::cout << c.getSimple_x() << std::endl;

	a.setSimple_x(42);
	c = a + b;
	std::cout << a.getSimple_x() << std::endl;
	std::cout << c.getSimple_x() << std::endl;
	
	return 0;
}