#ifndef FIXED_HPP
# define FIXED_HPP

#include "Colors.hpp"
#include <iostream>
#include <cmath>

class Fixed {

private:

	int					_value;
	static const int	_fractionnal_bits = 8;

public:

	Fixed();
	Fixed(const Fixed& copy);

	Fixed(const int value);
	Fixed(const float);

	~Fixed();

	Fixed&	operator=(const Fixed& src);

	bool	operator>(const Fixed& src) const;
	bool	operator<(const Fixed& src) const;
	bool	operator>=(const Fixed& src) const;
	bool	operator<=(const Fixed& src) const;
	bool	operator==(const Fixed& src) const;
	bool	operator!=(const Fixed& src) const;

	Fixed	operator+(const Fixed& src);
	Fixed	operator-(const Fixed& src);
	Fixed	operator*(const Fixed& src);
	Fixed	operator/(const Fixed& src);

	Fixed&	operator++();
	Fixed	operator++(int);
	Fixed&	operator--();
	Fixed	operator--(int);

	static const Fixed&	min(const Fixed& a,const Fixed& b);
	static Fixed&	min(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a,const Fixed& b);
	static Fixed&	max(Fixed& a, Fixed& b);

	float	toFloat(void) const;
	int		toInt(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw_bits);

};

std::ostream& operator<<(std::ostream& out, const Fixed& src);

#endif
