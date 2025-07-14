#include "Point.hpp"

Point::Point() :x(0),y(0) {}

Point::Point(float const x, float const y) :x(x), y(y) {}

Point::Point(Point const& other) :x(other.x),y(other.y) {}

Point& Point::operator=(Point const&)
{
    return *this;
}

float Point::getX() const{
    return(x.toFloat());
}
float Point::getY() const{
    return(y.toFloat());
}

void Point::display_x() const{
    std::cout << "x = " << this->x << std::endl; 
}

void Point::display_y() const{
    std::cout << "y = " << this->y << std::endl;
}


Point::~Point() {

}