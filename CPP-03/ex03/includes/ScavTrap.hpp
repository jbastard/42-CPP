#pragma once
#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
public:
    static const unsigned int baseHitPoints = 100;
	static const unsigned int baseEnergyPoints = 50;
    static const unsigned int baseAttackDamage = 20;

	ScavTrap();
    explicit ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& copy);
	~ScavTrap();

	ScavTrap&   operator=(const ScavTrap& src);

	void        guardGate();
	void        attack(const std::string& target);
	void        takeDamage(unsigned int amount);
	void        beRepaired(unsigned int amount);

};

std::ostream& operator<<(std::ostream& out, const ScavTrap& src);