#include "../includes/Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src) {
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &src) {
	if (this != &src) {
		for (int i = 0; i < 100; ++i) _ideas[i] = src._ideas[i];
	}
	return *this;
}

const std::string& Brain::getIdea(int i) const {
	static const std::string empty;
	if (i < 0 || i >= 100) return empty;
	return _ideas[i];
}

void Brain::setIdea(int i, const std::string& s) {
	if (i < 0 || i >= 100) return;
	_ideas[i] = s;
}

std::ostream &operator<<(std::ostream &out, const Brain &src) {
	(void) src;
	out << "Class infos here" << std::endl;
	return out;
}
