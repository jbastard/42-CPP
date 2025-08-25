#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &src) : WrongAnimal() {
	*this = src;
}

WrongCat::~WrongCat() {}

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