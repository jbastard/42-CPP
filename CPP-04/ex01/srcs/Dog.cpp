#include "../includes/Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << BRIGHT_GREEN "Dog constructor called" RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src) {
	*this = src;
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << BRIGHT_RED "Dog destructor called" RESET << std::endl;
}

Dog &Dog::operator=(const Dog &src) {
	if (this != &src) {
		Animal::operator=(src);
		Brain* newBrain = new Brain(*src._brain);
		delete _brain;
		_brain = newBrain;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << make_rgb(255, 242, 117) << "WOUAF!!" RESET << std::endl;
}

void Dog::setIdea(int i, const std::string& s) { _brain->setIdea(i, s); }
const std::string& Dog::getIdea(int i) const { return _brain->getIdea(i); }

std::ostream &operator<<(std::ostream &out, const Dog &src) {
	(void)src;
	out << "Class infos here" << std::endl;
	return out;
}
