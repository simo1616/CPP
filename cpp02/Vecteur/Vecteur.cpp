#include "Vecteur.hpp"


Vecteur::Vecteur(double vx, double vy) :x(vx),y(vy){

}

void Vecteur::display(void) {
	std::cout 	<< "x = " << x << std::endl
				<< "y = " << y << std::endl;
}

Vecteur Vecteur::operator+(Vecteur const &other) {

	return(Vecteur (x + other.x, y + other.y));
}

Vecteur Vecteur::operator-(Vecteur const &other) {

	return(Vecteur (x - other.x, y - other.y));
}

Vecteur Vecteur::operator-() {

	return(Vecteur (-x, -y));
}

void Vecteur::operator+=(Vecteur const &other) {
	x += other.x;
	y += other.y;
}

double Vecteur::get_x(void) const {
	return(this->x);
}

double Vecteur::get_y(void) const {
	return(this->y);
}

 
