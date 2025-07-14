#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	public :
		Point();
		Point(float const x, float const y);
		Point(Point const& other);
		Point& operator=(Point const& other);
		~Point();
	private :
		Fixed const x;
		Fixed const y;
};



#endif
