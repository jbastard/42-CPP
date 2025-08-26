#include "../includes/Dog.hpp"

Dog::Dog() : AAnimal() {
	std::cout << BRIGHT_GREEN "Dog constructor called" RESET << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other), _brain(new Brain(*other._brain)) {
	this->_type = other.getType();
}

Dog::~Dog() {
	delete this->_brain;
	std::cout << BRIGHT_RED "Dog destructor called" RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other._type;
		if (!_brain) _brain = new Brain(*other._brain);
		else         *_brain = *other._brain;
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
