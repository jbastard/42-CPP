#include "../includes/Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Point::Point(const Point &src): _x(src.getX()), _y(src.getY()) {
}

Point &Point::operator=(const Point &src) {
	if (this == &src)
		return *this;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Point& src) {
	out << "x :" << src.getX() << std::endl
		<< "y :" << src.getY() << std::endl;
	return out;
}

Point::~Point() {}


const Fixed& Point::getX(void) const {
	return (this->_x);
}

const Fixed& Point::getY(void) const {
	return (this->_y);
}
