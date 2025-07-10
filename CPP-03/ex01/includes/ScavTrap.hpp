#pragma once
#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(const std::string& name);
	~ScavTrap();

	void guardGate();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& out, const ScavTrap& src);