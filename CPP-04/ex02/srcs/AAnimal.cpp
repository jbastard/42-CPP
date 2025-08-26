#include "../includes/AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << BRIGHT_GREEN "AAnimal constructor called" RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &src) {
	*this = src;
}

AAnimal::~AAnimal() {
	std::cout << BRIGHT_RED "AAnimal destructor called" RESET << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src) {
	if (this != &src) {
		this->_type = src.getType();
	}
	return *this;
}

const std::string& AAnimal::getType() const {
	return this->_type;
}

std::ostream &operator<<(std::ostream &out, const AAnimal &src) {
	(void)src;
	out << "Class infos here" << std::endl;
	return out;
}