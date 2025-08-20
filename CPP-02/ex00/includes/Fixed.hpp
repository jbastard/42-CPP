#ifndef FIXED_HPP
# define FIXED_HPP

#include "Colors.hpp"
#include <iostream>

class Fixed {

private:

	int					_value;
	static const int	_fractionnal_bits;

public:

	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& src);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(const int raw_bits);
};

#endif
