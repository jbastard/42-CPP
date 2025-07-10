#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define RESET "\033[0m"

#define BRIGHT_BLACK   "\033[1;90m"
#define BRIGHT_RED     "\033[1;91m"
#define BRIGHT_GREEN   "\033[1;92m"
#define BRIGHT_YELLOW  "\033[1;93m"
#define BRIGHT_BLUE    "\033[1;94m"
#define BRIGHT_MAGENTA "\033[1;95m"
#define BRIGHT_CYAN    "\033[1;96m"
#define BRIGHT_WHITE   "\033[1;97m"

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
