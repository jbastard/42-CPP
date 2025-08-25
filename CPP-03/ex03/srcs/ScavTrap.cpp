#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout
			<< BRIGHT_GREEN "ScavTrap default constructor called" RESET
			<< std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout
			<< BRIGHT_GREEN  "ScavTrap " << "name constructor called" RESET
			<< std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout
			<< BRIGHT_RED  "ScavTrap " << "Destructor called" RESET
			<< std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src) {
    if (this != &src) {
        ClapTrap::operator=(src);
        this->_name = src.getName();
    }
    return *this;
}

void ScavTrap::guardGate() {
    std::cout
            << BRIGHT_MAGENTA "ScavTrap " << this->_name << " is now guarding." RESET
            << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
	{
		if (this->_hit_points <= 0)
			std::cout
					<< "ScavTrap " << this->_name << " is dead !"
					<< std::endl;
		else if (this->_energy_points <= 0)
				std::cout
						<< "ScavTrap " << this->_name << " don't have enough energy points !"
						<< std::endl;
		return;
	}
	std::cout
			<< BRIGHT_YELLOW "ScavTrap " << ClapTrap::_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage !" RESET
			<< std::endl;
	_energy_points -= 1;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points <= 0)
	{
		std::cout
				<< "ScavTrap " << this->_name << " already is dead !"
				<< std::endl;
		return;
	}
	this->_hit_points -= amount;
	std::cout
			<< BRIGHT_RED << "ScavTrap " << this->_name << " took " << amount << " damages" RESET
			<< std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
	{
		if (this->_hit_points <= 0)
			std::cout
					<<  "ScavTrap " << this->_name << " is dead !"
					<< std::endl;
		else if (this->_energy_points <= 0)
				std::cout
						<<  "ScavTrap " <<  this->_name << " don't have enough energy points !"
						<< std::endl;
		return;
	}
	std::cout
			<< BRIGHT_GREEN "ScavTrap " << this->_name << " recover " << amount << " health." RESET
			<< std::endl;
	this->_energy_points -= 1;
	this->_hit_points += amount;
}
