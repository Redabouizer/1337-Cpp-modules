#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(Point const &src) {
	*this = src;
}

Point::~Point() {}

Point & Point::operator=(Point const &rSym) {
	if (this != &rSym)
		new (this)Point(rSym.getX().toFloat(), rSym.getY().toFloat());
	return *this;
}

std::ostream &	operator<<(std::ostream &o, Point const &rSym) {
	o << "x:(" << rSym.getX() << "); y:(" << rSym.getY() << ");";
	return o;
}

Fixed const	Point::getX() const {
	return this->x;
}

Fixed const	Point::getY() const {
	return this->y;
}