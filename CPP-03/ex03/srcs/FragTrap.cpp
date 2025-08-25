#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout
			<< BRIGHT_GREEN "FragTrap default constructor called" RESET
			<< std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout
			<< BRIGHT_GREEN  "FragTrap " << "name constructor called" RESET
			<< std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::~FragTrap() {
	std::cout
			<< BRIGHT_RED  "FragTrap " << "Destructor called" RESET
			<< std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& src) {
    if (this != &src) {
        ClapTrap::operator=(src);
        this->_name = src.getName();
    }
    return *this;
}

void FragTrap::highFivesGuys() {
    std::cout
        << BRIGHT_MAGENTA << "High five, buddy!" << RESET
        << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
	{
		if (this->_hit_points <= 0)
			std::cout
					<< "FragTrap " << this->_name << " is dead !"
					<< std::endl;
		else if (this->_energy_points <= 0)
				std::cout
						<< "FragTrap " << this->_name << " don't have enough energy points !"
						<< std::endl;
		return;
	}
	std::cout
			<< BRIGHT_YELLOW "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage !" RESET
			<< std::endl;
	_energy_points -= 1;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (this->_hit_points <= 0)
	{
		std::cout
				<< "FragTrap " << this->_name << " already is dead !"
				<< std::endl;
		return;
	}
	this->_hit_points -= amount;
	std::cout
			<< BRIGHT_RED << "FragTrap " << this->_name << " took " << amount << " damages" RESET
			<< std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (this->_energy_points <= 0 || this->_hit_points <= 0)
	{
		if (this->_hit_points <= 0)
			std::cout
					<<  "FragTrap " << this->_name << " is dead !"
					<< std::endl;
		else if (this->_energy_points <= 0)
				std::cout
						<<  "FragTrap " <<  this->_name << " don't have enough energy points !"
						<< std::endl;
		return;
	}
	std::cout
			<< BRIGHT_GREEN "FragTrap " << this->_name << " recover " << amount << " health." RESET
			<< std::endl;
	this->_energy_points -= 1;
	this->_hit_points += amount;
}
