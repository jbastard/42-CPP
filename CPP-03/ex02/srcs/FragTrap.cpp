#include "../includes/FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout
			<< BRIGHT_GREEN "Default constructor called" RESET
			<< std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout
			<< BRIGHT_GREEN  "FragTrap " << "Name constructor called" RESET
			<< std::endl;
	this->_name = name;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap &FragTrap::operator=(const FragTrap &src) {
	std::cout
			<< BRIGHT_CYAN "Copy assignment operator called" RESET
			<< std::endl;

	if (this != &src)
	{
		this->_name = src.getName();
		this->_hit_points = src.getHitPoints();
		this->_energy_points = src.getEnergyPoints();
		this->_attack_damage = src.getAttackDamages();
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout
			<< BRIGHT_RED  "FragTrap " << "Destructor called" RESET
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

void FragTrap::highFivesGuys() {
	std::cout << "High five, buddy!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const FragTrap& src) {
	out
		<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl
		<< BRIGHT_BLUE << "|         FragTrap Stats        |" << RESET << std::endl
		<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl

		<< BRIGHT_BLUE << "|" << RESET
		<< "  Name           : " << BRIGHT_WHITE << src.getName()
		<< std::setw(12 - src.getName().length()) << ""
		<< BRIGHT_BLUE << "|" << RESET << std::endl

		<< BRIGHT_BLUE << "|" << RESET
		<< "  Health         : " << BRIGHT_WHITE << src.getHitPoints()
		<< std::setw(12 - getNumLen(src.getHitPoints())) << ""
		<< BRIGHT_BLUE << "|" << RESET << std::endl

		<< BRIGHT_BLUE << "|" << RESET
		<< "  Attack Damage  : " << BRIGHT_WHITE << src.getAttackDamages()
		<< std::setw(12 - getNumLen(src.getAttackDamages())) << ""
		<< BRIGHT_BLUE << "|" << RESET << std::endl

		<< BRIGHT_BLUE << "|" << RESET
		<< "  Energy Points  : " << BRIGHT_WHITE << src.getEnergyPoints()
		<< std::setw(12 - getNumLen(src.getEnergyPoints())) << ""
		<< BRIGHT_BLUE << "|" << RESET << std::endl

		<< BRIGHT_BLUE << "+-------------------------------+" << RESET << std::endl;

	return out;
}
