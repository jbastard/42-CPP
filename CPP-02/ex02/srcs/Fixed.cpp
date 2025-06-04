
#include "../includes/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() {
	this->_value = 0;
}

Fixed::Fixed(const int value) {
	this->_value = value << _fractionnal_bits;
}

Fixed::Fixed(const float value) {
	this->_value = roundf(value * (1 << this->_fractionnal_bits));
}


Fixed::Fixed(const Fixed &src) {
	*this = src;
}

Fixed &Fixed::operator=(const Fixed &src) {
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed() {}


std::ostream& operator<<(std::ostream& out, const Fixed& src) {
	out << src.toFloat();
	return out;
}


bool	Fixed::operator>(const Fixed& src) const {
	return (this->_value > src._value);
}

bool	Fixed::operator<(const Fixed& src) const {
	return (this->_value < src._value);
}

bool	Fixed::operator>=(const Fixed& src) const {
	return (this->_value >= src._value);
}

bool	Fixed::operator<=(const Fixed& src) const {
	return (this->_value <= src._value);
}

bool	Fixed::operator==(const Fixed& src) const {
	return (this->_value == src._value);
}

bool	Fixed::operator!=(const Fixed& src) const {
	return (this->_value != src._value);
}



Fixed		Fixed::operator+(const Fixed& src) {
	return Fixed(this->toFloat() + src.toFloat());
}

Fixed		Fixed::operator-(const Fixed& src ) {
	return Fixed(this->toFloat() - src.toFloat());
}

Fixed		Fixed::operator*(const Fixed& src) {
	return Fixed(this->toFloat() * src.toFloat());
}

Fixed		Fixed::operator/(const Fixed& src) {
	return Fixed(this->toFloat() / src.toFloat());
}


Fixed&	Fixed::operator++() {
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	_value++;
	return temp;
}

Fixed&	Fixed::operator--() {
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	_value--;
	return temp;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a < b) ? b : a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a < b) ? b : a;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a > b) ? b : a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a > b) ? b : a;
}


int Fixed::getRawBits() const {
	return(this->_value);
}

void Fixed::setRawBits(const int raw_bits) {
	this->_value = raw_bits;
}

float	Fixed::toFloat() const {
	return (float)this->_value / (1 << _fractionnal_bits);
}

int		Fixed::toInt() const {
	return this->_value >> _fractionnal_bits;
}
