#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

private:

	const Fixed _x;
	const Fixed _y;

public:

	Point();
	Point(const float x, const float y);
	Point(const Point& copy);

	Point&	operator=(const Point& src);

	~Point();

	const Fixed &getX(void) const;
	const Fixed &getY(void) const;
};

std::ostream& operator<<(std::ostream& out, const Point& src);

#endif
