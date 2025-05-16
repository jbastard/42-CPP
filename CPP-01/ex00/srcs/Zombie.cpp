
#include "../includes/Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) {
	this->_name = name;
	std::cout
		<< GREEN << name + ": spawned..." << RESET
		<< std::endl;
}

Zombie::~Zombie() {
	std::cout
			<< RED <<this->_name + ": died..." << RESET << std::endl;
}

void	Zombie::announce() {
	std::cout
		<< BLUE << this->_name + ": BraiiiiiiinnnzzzZ..." << RESET
		<< std::endl;
}
