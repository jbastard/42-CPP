#include "../includes/Dog.hpp"

Dog::Dog() : Animal() {
	this->_type = "Dog";
}

Dog::Dog(const Dog &src) : Animal(src) {
	*this = src;
}

Dog::~Dog() {}

Dog &Dog::operator=(const Dog &src) {
	if (this != &src) {
		// Put Atributs here
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << make_rgb(255, 242, 117) << "WOUAF!!" RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Dog &src) {
	(void)src;
	out << "Class infos here" << std::endl;
	return out;
}
