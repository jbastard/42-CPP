
#include "../includes/Phonebook.hpp"

Contact::~Contact() {}

Contact::Contact() {}

void Contact::fillInfos() {
	std::cout << "Enter contact name: ";
	std::getline(std::cin, this->_name);
	std::cout << "Enter contact last name: ";
	std::getline(std::cin, this->_lastName);
	std::cout << "Enter " << this->_name << "'s Nickname: ";
	std::getline(std::cin, this->_nickName);
	std::cout << "Enter " << this->_name << "'s Phone number: ";
	std::getline(std::cin, this->_phoneNumber);
	std::cout << "Enter " << this->_name << "'s Darkest Secret: ";
	std::getline(std::cin, this->_darkestSecret);
	std::cout << std::endl;
}
