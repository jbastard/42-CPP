
#include "Weapon.hpp"
#include "HumanB.hpp"

//HumanB::HumanB() {}

HumanB::HumanB(const std::string& name) {
	this->_name = name;
}

HumanB::~HumanB() {}

void HumanB::attack() {
	std::cout
			<< this->_name
			<< "attacks with their"
			<< this->_weapon.getType()
			<< std::endl;
}

void	HumanB::setWeapon(const Weapon& newWeapon) {
	this->_weapon = newWeapon;
}