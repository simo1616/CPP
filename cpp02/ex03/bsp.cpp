/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:47:56 by mbendidi          #+#    #+#             */
/*   Updated: 2025/07/14 14:31:14 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float det(Point const& U, Point const& V) {
	return U.getX() * V.getY()
			- U.getY() * V.getX();
}

Point vecteur(Point const& A, Point const& B) {
	return Point(B.getX() - A.getX(),
					B.getY() - A.getY());
}

bool bsp(Point const A, Point const B,
         Point const C, Point const P)
{
	float d1 = det(vecteur(A,B), vecteur(A,P));
	float d2 = det(vecteur(B,C), vecteur(B,P));
	float d3 = det(vecteur(C,A), vecteur(C,P));

	bool allPos = (d1 > 0 && d2 > 0 && d3 > 0);
	bool allNeg = (d1 < 0 && d2 < 0 && d3 < 0);
	return (allPos || allNeg);
}
