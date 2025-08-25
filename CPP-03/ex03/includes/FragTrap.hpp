#pragma once
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	static const unsigned int baseHitPoints = 100;
	static const unsigned int baseAttackDamage = 30;

	FragTrap();
	FragTrap(const std::string& name);
	~FragTrap();

	FragTrap&	operator=(const FragTrap& src);

	void		highFivesGuys();
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};
