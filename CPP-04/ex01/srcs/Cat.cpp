#include "../includes/Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << BRIGHT_GREEN "Cat constructor called" RESET << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src) {
	*this = src;
}

Cat::~Cat() {
	delete this->_brain;
	std::cout << BRIGHT_RED "Cat destructor called" RESET << std::endl;
}

Cat &Cat::operator=(const Cat &src) {
	if (this != &src) {
		Animal::operator=(src);
		Brain* newBrain = new Brain(*src._brain);
		delete _brain;
		_brain = newBrain;
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << make_rgb(255, 140, 66) << "MIAOUU!!" RESET << std::endl;
}

void Cat::setIdea(int i, const std::string& s) { _brain->setIdea(i, s); }
const std::string& Cat::getIdea(int i) const { return _brain->getIdea(i); }

std::ostream &operator<<(std::ostream &out, const Cat &src) {
	(void)src;
	out << "Class infos here" << std::endl;
	return out;
}
