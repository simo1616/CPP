/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:46:16 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/13 11:38:36 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vecteur.hpp"
#include <fstream>

std::ostream& operator<<(std::ostream& out,Vecteur const &other) {
	out << "<< V3 <<\nx = " << other.get_x() << std::endl
				<< "y = " << other.get_y() << std::endl;
	return(out);
}


int main (void) 
{
	Vecteur V1(3.5, 4.7);
	Vecteur V2(2.1, 3.9);

	V1 += V2;
	V1.display();

	Vecteur V3 = V1 + V2;
	V3.display();

	V3 = V1 - V2;
	
	std::cout << V3 << std::endl;
	std::cout << V2 << std::endl;
	std::cout << V3 + V2 << std::endl;



 

}