#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	public :
		Point();
		Point(float const x, float const y);
		Point(Point const& other);
		Point& operator=(Point const& other);
        float getX() const;
        float getY() const;
        void display_x() const;
        void display_y() const;
		~Point();
	private :
		Fixed const x;
		Fixed const y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
