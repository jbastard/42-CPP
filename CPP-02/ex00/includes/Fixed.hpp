#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
	static const int	_fractionnal_bits;

public:

	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& src);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw_bits);
};

#endif