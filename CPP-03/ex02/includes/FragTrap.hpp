#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap();
	FragTrap(const std::string& name);
	~FragTrap();

	FragTrap&	operator=(const FragTrap& src);

	void		highFivesGuys();
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
};

std::ostream& operator<<(std::ostream& out, const FragTrap& src);