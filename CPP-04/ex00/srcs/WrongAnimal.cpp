#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal &src) {
	*this = src;
}

WrongAnimal::~WrongAnimal() {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src) {
	if (this != &src) {
		this->_type = src.getType();
	}
	return *this;
}

const std::string& WrongAnimal::getType() const {
	return this->_type;
}

void WrongAnimal::makeSound() const {
	std::cout << BRIGHT_RED "WOUAF!!... Wait what ?" RESET << std::endl;
}

std::ostream &operator<<(std::ostream &out, const WrongAnimal &src) {
	(void)src;
	out << "Class infos here" << std::endl;
	return out;
}