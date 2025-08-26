#include "../includes/Animal.hpp"

Animal::Animal() {
	std::cout << BRIGHT_GREEN "Animal constructor called" RESET << std::endl;
}

Animal::Animal(const Animal &src) {
	*this = src;
}

Animal::~Animal() {
	std::cout << BRIGHT_RED "Animal destructor called" RESET << std::endl;
}

Animal &Animal::operator=(const Animal &src) {
	if (this != &src) {
		this->_type = src.getType();
	}
	return *this;
}

const std::string& Animal::getType() const {
	return this->_type;
}

void Animal::makeSound() const {}

std::ostream &operator<<(std::ostream &out, const Animal &src) {
	(void)src;
	out << "Class infos here" << std::endl;
	return out;
}