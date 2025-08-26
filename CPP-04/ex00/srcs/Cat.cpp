#include "../includes/Cat.hpp"

Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout << BRIGHT_GREEN "Cat constructor called" RESET << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src) {
	*this = src;
}

Cat::~Cat() {
	std::cout << BRIGHT_RED "Cat destructor called" RESET << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	if (this != &src) {
		// Put Atributs here
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << make_rgb(255, 140, 66) << "MIAOUU!!" RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Cat &src) {
	(void)src;
	out << "Class infos here" << std::endl;
	return out;
}
