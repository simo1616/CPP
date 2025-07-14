#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include <iostream>
#include <fstream>


class Vecteur
{
	
	public:
		Vecteur(double vx, double vy);
		void display(void);
		void operator+=(Vecteur const &other);
		Vecteur operator+(Vecteur const &other);
		Vecteur operator-(Vecteur const &other);
		Vecteur operator-();
		double get_x(void) const;
		double get_y(void) const;


		



		
	private:
		double x;
		double y;
};




#endif