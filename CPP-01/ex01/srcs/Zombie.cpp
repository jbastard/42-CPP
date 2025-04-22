
#include "../includes/Zombie.hpp"

Zombie::~Zombie() {
	std::cout
		<< RED <<this->_name + ": died..." << RESET << std::endl;
}

Zombie::Zombie() {}

void Zombie::setName(const std::string &name) {
	this->_name = name;
}

std::string	Zombie::getName() const {
	return (this->_name);
}

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout
		<< GREEN << name + ": spawned..." << RESET
		<< std::endl;
}

void	Zombie::announce() {
	std::cout
		<< BLUE << this->getName() << ": BraiiiiiiinnnzzzZ..." << RESET
		<< std::endl;
}
