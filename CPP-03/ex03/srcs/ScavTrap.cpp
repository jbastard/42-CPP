#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout
			<< BRIGHT_GREEN "Default constructor called" RESET
			<< std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout
			<< BRIGHT_GREEN  "ScavTrap " << "Name constructor called" RESET
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
			<< BRIGHT_YELLOW "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage !" RESET
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

void ScavTrap::guardGate() {
	std::cout
		<< BRIGHT_MAGENTA "ScavTrap " << this->_name << " is now guarding." RESET
		<< std::endl;
}

std::ostream& operator<<(std::ostream& out, const ScavTrap& src) {
	out
		<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl
		<< BRIGHT_BLUE << "|         ScavTrap Stats        |" << RESET << std::endl
		<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl
		<< BRIGHT_BLUE "|" RESET << "  Name           : " << BRIGHT_WHITE << src.getName() << std::setw(24  - src.getName().length()) << BRIGHT_BLUE "|" RESET << std::endl
		<< BRIGHT_BLUE "|" RESET << "  Health         : " << BRIGHT_WHITE << src.getHitPoints() << std::setw(24  - getNumLen(src.getHitPoints())) << BRIGHT_BLUE "|" RESET << std::endl
		<< BRIGHT_BLUE "|" RESET << "  Attack Damage  : " << BRIGHT_WHITE << src.getAttackDamages() << std::setw(24  - getNumLen(src.getAttackDamages())) << BRIGHT_BLUE "|" RESET << std::endl
		<< BRIGHT_BLUE "|" RESET << "  Energy Points  : " << BRIGHT_WHITE << src.getEnergyPoints() << std::setw(24  - getNumLen(src.getEnergyPoints())) << BRIGHT_BLUE "|" RESET << std::endl
		<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl;
	return out;
}
