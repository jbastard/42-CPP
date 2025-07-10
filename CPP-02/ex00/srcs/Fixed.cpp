
#include "../includes/Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout
			<< BRIGHT_GREEN "Default constructor called" RESET
			<< std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout
			<< BRIGHT_MAGENTA "Copy constructor called" RESET
			<< std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed& src) {
	std::cout
			<< BRIGHT_CYAN "Copy assignment operator called" RESET
			<< std::endl;

	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout
			<< BRIGHT_RED "Destructor called" RESET
			<< std::endl;
}

int Fixed::getRawBits() const {
	std::cout
			<< "getRawBits member function called"
			<< std::endl;
	return(this->_value);
}

void Fixed::setRawBits(const int raw_bits) {
	std::cout
			<< "setRawBits member function called"
			<< std::endl;
	this->_value = raw_bits;
}
