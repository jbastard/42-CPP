
#include "../includes/Weapon.hpp"

Weapon::Weapon(const std::string& type) : _type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType() {
	return (this->_type);
}

void		Weapon::setType(const std::string&	newType) {
	(this->_type = newType);
}
