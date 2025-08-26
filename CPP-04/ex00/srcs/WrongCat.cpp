#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << BRIGHT_GREEN "WrongCat constructor called" RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal() {
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout << BRIGHT_RED "WrongAnimal destructor called" RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src) {
	if (this != &src) {
		// Put Atributs here
	}
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << BRIGHT_WHITE "MIAOUU!!" RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, const WrongCat &src) {
	(void)src;
	out << "Class infos here" << std::endl;
	return out;
}