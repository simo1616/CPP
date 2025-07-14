/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 20:46:16 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/14 14:27:35 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void testPoint(Point const& A, Point const& B, Point const& C, Point const& P)
{
	std::cout  << "Test P(" << P.getX() << ", " << P.getY() << "): ";
	if (bsp(A, B, C, P))
		std::cout << "➤ à l’intérieur";
	else
		std::cout << "➤ à l’extérieur / bord";

	std::cout << " du triangle ABC\n";
}

int main()
{
	Point A(-2.2f, 3.3f);
	Point B(1.2f, 0.3f);
	Point C(2.9f, 1.3f);

	std::cout << "Triangle ABC avec :\n"
				<< " A(" << A.getX() << ", " << A.getY() << ")\n"
				<< " B(" << B.getX() << ", " << B.getY() << ")\n"
				<< " C(" << C.getX() << ", " << C.getY() << ")\n\n";

	// p a l’intérieur
	testPoint(A, B, C, Point(2.2f, 1.8f));  // attendu : intérieur

	// p a l’intérieur
	testPoint(A, B, C, Point(2.0f, 2.5f));  // attendu : intérieur

	// p sur chaque arête (milieux)
	testPoint(A, B, C, Point((2.2f+1.2f)/2, (3.3f+0.3f)/2)); // milieu de AB
	testPoint(A, B, C, Point((1.2f+2.9f)/2, (0.3f+1.3f)/2)); // milieu de BC
	testPoint(A, B, C, Point((2.9f+2.2f)/2, (1.3f+3.3f)/2)); // milieu de CA

	// p = sommet
	testPoint(A, B, C, A);  // sommet A
	testPoint(A, B, C, B);  // sommet B
	testPoint(A, B, C, C);  // sommet C

	// p a à l’extérieur
	testPoint(A, B, C, Point(0.0f, 0.0f));
	testPoint(A, B, C, Point(5.0f, 5.0f));

	return 0;
}

