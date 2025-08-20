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
	Fixed(const float value);

	Fixed&	operator=(const Fixed& src);

	~Fixed();

	float	toFloat(void) const;
	int		toInt(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw_bits);
};

std::ostream& operator<<(std::ostream& out, const Fixed& src);

#endif