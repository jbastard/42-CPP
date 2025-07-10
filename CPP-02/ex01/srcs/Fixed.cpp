
#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() {
	std::cout
		<< BRIGHT_GREEN "Default constructor called" RESET
		<< std::endl;
	this->_value = 0;
}

Fixed::Fixed(const int value) {
	std::cout
		<< BRIGHT_YELLOW "Int constructor called" RESET
		<< std::endl;
	this->_value = value << _fractionnal_bits;
}

Fixed::Fixed(const float value) {
	std::cout
		<< BRIGHT_BLUE "Float constructor called" RESET
		<< std::endl;
	this->_value = roundf(value * (1 << this->_fractionnal_bits));
}

Fixed::Fixed(const Fixed &src) {
	std::cout
			<< BRIGHT_MAGENTA "Copy constructor called" RESET
			<< std::endl;
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src) {
	std::cout
			<< BRIGHT_CYAN "Copy assignment operator called" RESET
			<< std::endl;

	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed& src) {
	out << src.toFloat();
	return out;
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

float	Fixed::toFloat() const {
	return (float)this->_value / (1 << _fractionnal_bits);
}

int		Fixed::toInt() const {
	return this->_value >> _fractionnal_bits;
}
